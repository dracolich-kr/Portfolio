#pragma once

namespace DataBase::ODBC
{
	class SqlInt16 : public SqlValue
	{
	public:
		SqlInt16(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlInt16() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Int16 GetValue() { return mValue; }

	private:
		Int16 mValue;
	};
}