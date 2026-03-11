#pragma once

namespace DataBase::ODBC
{
	class SqlInt32 : public SqlValue
	{
	public:
		SqlInt32(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlInt32() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Int32 GetValue() { return mValue; }

	private:
		Int32 mValue;
	};
}