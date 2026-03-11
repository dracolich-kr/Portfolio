#pragma once

namespace DataBase::ODBC
{
	class SqlInt8 : public SqlValue
	{
	public:
		SqlInt8(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0) 
		{}
		virtual ~SqlInt8() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Int8 GetValue() { return mValue; }

	private:
		Int8 mValue;
	};
}