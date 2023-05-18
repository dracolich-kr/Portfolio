#pragma once

namespace DataBase::ODBC
{
	class SqlValue
	{
	public:
		SqlValue(Int32 column_index) 
			: mColumnIndex(column_index)
		{}
		virtual ~SqlValue() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) { return ErrorResult::Success; }

		Int32 GetColumnIndex() { return mColumnIndex; }

	protected:
		Int32 mColumnIndex = 0;
	};

	//using SharedSqlValue = std::shared<SqlValue>;
}