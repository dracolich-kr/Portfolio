#pragma once

namespace DataBase::ODBC
{
	class SqlFloat : public SqlValue
	{
	public:
		SqlFloat(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0.0f)
		{}
		virtual ~SqlFloat() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Float GetValue() { return mValue; }

	private:
		Float mValue;
	};
}