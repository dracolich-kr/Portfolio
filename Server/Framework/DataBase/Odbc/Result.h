#pragma once

namespace DataBase::ODBC
{
	// Bind Cols : https://learn.microsoft.com/ko-kr/sql/odbc/reference/syntax/sqlbindcol-function?view=sql-server-ver16
	class Result
		: public DataBase::Result
	{
	public:
		Result(SharedQuery query)
			: mQuery(std::static_pointer_cast<DataBase::ODBC::Query>(query))
			, mLength(1)
		{
		}

		virtual ErrorResult Bind() PURE;
		virtual ErrorResult Fetch() PURE;
		virtual ErrorResult onResult() override;

	protected:
		SharedQuery mQuery;
		Int32 mLength;
	};

	using SharedResult = std::shared_ptr<DataBase::ODBC::Result>;
}