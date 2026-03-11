#pragma once

namespace DataBase::ODBC
{
	class SqlDateTime : public SqlValue
	{
	public:
		SqlDateTime(Int32 column_index)
			: SqlValue(column_index)
			, mValue({0,})
		{}
		virtual ~SqlDateTime() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		DateTime GetValue();

	private:
		SQL_TIMESTAMP_STRUCT mValue;
	};
}