#pragma once

namespace DataBase::ODBC
{
	class Query;
	using SharedQuery = std::shared_ptr<Query>;

	class Command 
		: DataBase::Command
	{
	public:
		Command(SharedQuery query)
			: mQuery(std::static_pointer_cast<DataBase::ODBC::Query>(query))
			, mLength(1)
		{
		}

		ErrorResult Init(DefWString message);
		ErrorResult Release();

		virtual ErrorResult Prepare() PURE;	

		ErrorResult BindParam(SqlInputType type, Int64 value) override;
		ErrorResult BindParam(SqlInputType type, UInt64 value) override;
		ErrorResult BindParam(SqlInputType type, Int32 value) override;
		ErrorResult BindParam(SqlInputType type, UInt32 value) override;
		ErrorResult BindParam(SqlInputType type, Int16 value) override;
		ErrorResult BindParam(SqlInputType type, UInt16 value) override;
		ErrorResult BindParam(SqlInputType type, Int8 value) override;
		ErrorResult BindParam(SqlInputType type, UInt8 value) override;
		ErrorResult BindParam(SqlInputType type, Char value) override;
		ErrorResult BindParam(SqlInputType type, Float value) override;
		ErrorResult BindParam(SqlInputType type, Double value) override;
		ErrorResult BindParam(SqlInputType type, DefString value) override;
		ErrorResult BindParam(SqlInputType type, DefWString value) override;

		// 참고자료
		// https://learn.microsoft.com/ko-kr/sql/relational-databases/native-client-odbc-date-time/date-and-time-improvements-odbc?view=sql-server-ver16
		// https://learn.microsoft.com/ko-kr/sql/relational-databases/native-client-odbc-how-to/use-date-and-time-types?view=sql-server-ver16
		ErrorResult BindParam(SqlInputType type, DateTime value) override;

	private:
		ErrorResult checkResult(SqlReturn result);

	private:
		SharedQuery mQuery;
		Int32 mLength;
	};

	using SharedCommand = std::shared_ptr<Command>;
}