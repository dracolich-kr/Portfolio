using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;

namespace DataBaseParser
{
    public enum InoutType
    {
        None
        , Input
        , OutPut
        , InoutPut
    }

    public class SqlParameter
    {
        public SqlValue Value { get; set; } = new SqlValue();
        public InoutType InoutType { get; set; } = InoutType.None;
    }

    public class SqlCommand
    {
        public List<SqlParameter> Parameters { get; set; } = new List<SqlParameter>();

        public void Work(String buffer)
        {

        }

        public String WriteParameter()
        {
            String buffer = String.Empty;

            for(Int32 index = 0; index < Parameters.Count;index++)
            {
                buffer += "?";

                if (index > Parameters.Count - 1)
                    buffer += ",";
            }

            return buffer;
        }

        public String WriteHeader(String file_name)
        {
            String buffer = $@"#pragma once

class {file_name}Command 
    : public DataBase::ODBC::Command
{{
public:
    {file_name}Command(DataBase::ODBC::SharedQuery query)
        : Command(query)
    {{
    }}
    
    virtual ~{file_name}Command()
    {{
    }}
    
	virtual ErrorResult Prepare() override;

    {WriteSetFunc()}

private:
    {WriteMember()}
}};
";
            return buffer;
        }

        private String WriteSetFunc()
        {
            String buffer = String.Empty;

            foreach (var member in Parameters)
            {
                buffer += $@"\tvoid Set{member.Value.Name}({member.Value.Type.toTypeString()} value) {{ m{member.Value.Name} = value }}\n";
            }
            return buffer;
        }

        private String WriteMember()
        {
            String buffer = String.Empty;

            foreach (var member in Parameters)
            {
                buffer += $@"\tm{member.Value.Name};\n";
            }

            return buffer;
        }

        public String WriteBody(String file_name)
        {
            String buffer = $@"
#include <pch.h>

ErrorResult {file_name}Parameter::Prepare()
{{
    ErrorResult result = ErrorResult::Success;
{WriteBind()}
    
    return ErrorResult::Success;;
}}
";
            return buffer;
        }

        private String WriteBind()
        {
            String buffer = String.Empty;
            foreach(var info in Parameters)
            {
                buffer += $"\tresult = BindParam({info.InoutType.toString()}, m{info.Value.Name});\n";
                buffer += $"\tIF_RETURN(result != ErrorResult::Success, result)\n\n";
            }

            return buffer;
        }
    }
}