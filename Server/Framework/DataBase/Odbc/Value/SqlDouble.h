#pragma once

namespace DataBase::ODBC
{
	class SqlDouble : public SqlValue
	{
	public:
		SqlDouble(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0.0F)
		{}
		virtual ~SqlDouble() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		Double GetValue() { return mValue; }

	private:
		Double mValue;
	};
}