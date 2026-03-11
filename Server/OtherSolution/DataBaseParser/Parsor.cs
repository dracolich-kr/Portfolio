using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;

namespace DataBaseParser
{
    class Parsor
    {
        private SqlCommand mParamWriter = new SqlCommand();
        private List<SqlResult> mResults = new List<SqlResult>();
        private String OutPutPath { get; set; } = String.Empty;
        private String FileName { get; set; } = String.Empty;

        private void Work(String file_path, String output_path)
        {

        }

        private bool paringParameter()
        {

            return false;
        }

        private bool parsingResults()
        {

            return false;
        }

        public String MakeHeader(String table_name)
        {
            String buffer = string.Empty;

            return buffer;
        }

        public String makeHeaderQuery(String file_name)
        {
            String buffer = 
$@"class {file_name}Query : public DataBase::ODBC::Query
{{
public:
	virtual ErrorResult Initalize(DataBase::ODBC::SharedSession session)
	{{
		ErrorResult result = DataBase::ODBC::Query::Initalize(session);

		mCommand = MakeShared<{file_name}Parameter>(GetStmt());
		mCommand->Init(mSession, L""{{CALL dbo.{file_name}({mParamWriter.WriteParameter()})}}"");

		mResults.push_back(MakeShared<{file_name}Result>(GetStmt()));

		return result;
	}}

	virtual ErrorResult Release()
	{{
		ErrorResult result = DataBase::ODBC::Query::Release();
		return result;
	}}
    
private:
    
}}";
            return buffer;
        }

        public String MakeBody()
        {
            String buffer = String.Empty;
            return buffer;
        }

        public static String GetDirName(String path)
        {
            Int32 index = path.LastIndexOf("\\") + 1;
            return path.Substring(index, path.Length - index);
        }

    }
}