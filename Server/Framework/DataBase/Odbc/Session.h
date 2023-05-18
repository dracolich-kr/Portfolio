#pragma once

namespace DataBase::ODBC
{
	using SqlReturn = SQLRETURN;

	using SqlDateStruct = SQL_DATE_STRUCT;
	using SqlTimeStampStruct = SQL_TIMESTAMP_STRUCT;

	using SqlLen = SQLLEN;

	using SqlHandleEnv = SQLHENV;
	using SqlHandleDbc = SQLHDBC;
	using SqlHandleStmt = SQLHSTMT;
	using SqlInputType = Int16;

	// ODBC 정보
	// https://learn.microsoft.com/ko-kr/sql/odbc/reference/odbc-programmer-s-reference?view=sql-server-ver16

	class Session 
		: public DataBase::Session
	{
	public:
		Session()
			: mHandleEnv(nullptr)
			, mHandleDbc(nullptr)
			, mTransactionMode(false)
		{}
		virtual ~Session() {}

		ErrorResult Init();
		ErrorResult Release();

		ErrorResult Connect(DefWString db_name, DefWString ip, Port port, DefWString user, DefWString password);
		ErrorResult Connect(DefWString file_name);
		ErrorResult ReConnect();

		ErrorResult Disconnect();

		SqlHandleEnv& GetEnv() { return mHandleEnv; }
		SqlHandleDbc& GetDBC() { return mHandleDbc; }

		// MBCS 데이터를 교환할 때 드라이버가 클라이언트와 서버 코드 페이지 간에 문자를 변환합니다. 
		// 특성은 SQL Server char, varchar 및 텍스트 열에 저장된 데이터에만 영향을 줍니다.
		// ErrorResult SetTranslate(bool is_onoff);

	public:
		// Transcation
		ErrorResult BeginTrans();
		ErrorResult EndTrans(bool is_roll_back);

	private:
		ErrorResult GetError(SqlReturn result);
	private:
		SqlHandleEnv mHandleEnv;
		SqlHandleDbc mHandleDbc;
		DefWString mFileName;

		bool mTransactionMode;
	};

	using SharedSession = std::shared_ptr<DataBase::ODBC::Session>;
};