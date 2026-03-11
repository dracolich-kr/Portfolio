#pragma once

namespace DataBase::ODBC
{
	class SqlInt64 : public SqlValue
	{
	public:
		SqlInt64(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlInt64() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Int64 GetValue() { return mValue; }

	private:
		Int64 mValue;
	};
}