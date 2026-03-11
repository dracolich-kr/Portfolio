using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;

namespace DataBaseParser
{
    class SqlResult
    {
        private List<SqlValue> mValues = new List<SqlValue>();

        private String mTableName = String.Empty;
        public Int32 Count { get { return mValues.Count; } }

        public SqlResult() { } 

        public void Parsing()
        {

        }

        public String MakeSqlHeader()
        {
            String buffer = 
$@"#pragma once

class Sql{mTableName}Data
{{
public:
    Sql{mTableName}()
{WriteSqlMemberInit()}
    {{
    }}

private:
{WriteSqlMember()}
}};

class {mTableName}Data
{{
public:
{WriteMember()}
}};

class {mTableName}Result 
    : public DataBase::ODBC::Result
{{
public:
    {mTableName}Result(DataBase::ODBC::SharedQuery query)
        : Result(query)
    {{
    }}

    virtual ~{mTableName}Result
    {{
    }}

	virtual ErrorResult Bind() override;
	virtual ErrorResult Fetch() override;
    
    List<std::shared_ptr<{mTableName}>>& GetResults() {{ return mResults }}

private:
    Sql{mTableName} mSqlData;
    List<std::shared_ptr<{mTableName}>> mResults;
}};
";
            return buffer;
        }

        private String WriteSqlMemberInit()
        {
            String buffer = String.Empty;

            for(Int32 index = 0; index < mValues.Count; index++)
            {
                var info = mValues[index];

                if(index == 0)
                    buffer += $"\t\t: ";
                else
                    buffer += $"\t\t, ";

                switch (info.Type)
                {
                    case ValueType.NVarChar:
                        buffer += $"m{info.Name}({index + 1}, {info.Length})\n";
                        break;
                    default:
                        buffer += $"m{info.Name}({index + 1})\n";
                        break;
                }
            }

            return buffer;
        }

        private String WriteSqlMember()
        {
            String buffer = String.Empty;

            foreach(var info in mValues)
            {
                buffer += $"\tDataBase::ODBC::{info.Type.toSqlTypeString()} mSql{info.Name};\n";
            }

            return buffer;
        }

        private String WriteMember()
        {
            String buffer = String.Empty;

            foreach (var info in mValues)
            {
                buffer += $"\t{info.Type.toTypeString()} m{info.Name};\n";
            }

            return buffer;
        }

        public String MakeBody()
        {
            String buffer = $@"
#include <pch.h>

ErrorResult {mTableName}Result::Bind()
{{
{WriteBindMember()}

	return ErrorResult::Success;
}}

ErrorResult {mTableName}Result::Fetch()
{{
{WriteFetchMember()}
	mResults.push_back(result);

	return ErrorResult::Success;
}}
";
            return buffer;
        }

        public String WriteBindMember()
        {
            string buffer = string.Empty;  
            
            foreach (var info in mValues)
            {
                buffer += $"\tmSqlData.m{info.Name}.onBindCol(mQuery->GetStmt());\n";
            }

            return buffer;
        }

        public String WriteFetchMember()
        {
            string buffer = $"\tstd::shared_ptr<{this.mTableName}Data> result = MakeShared<{this.mTableName}Data>();";

            foreach (var info in mValues)
            {
                switch (info.Type)
                {
                    case ValueType.NVarChar:
                        buffer += $"result->m{info.Name} = mSqlData.m{info.Name}.GetValue().c_str()";
                        break;
                    default:
                        buffer += $"result->m{info.Name} = mSqlData.m{info.Name}.GetValue()";
                    break;
                }
            }

            return buffer;
        }
    }
}