#pragma once

namespace DataBase::ODBC
{
	class SqlUInt64 : public SqlValue
	{
	public:
		SqlUInt64(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlUInt64() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		UInt64 GetValue() { return mValue; }

	private:
		UInt64 mValue;
	};
}