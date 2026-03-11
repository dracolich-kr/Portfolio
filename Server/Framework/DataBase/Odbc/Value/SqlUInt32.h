#pragma once

namespace DataBase::ODBC
{
	class SqlUInt32 : public SqlValue
	{
	public:
		SqlUInt32(Int32 column_index) 
			: SqlValue(column_index) 
			, mValue(0)
		{}
		virtual ~SqlUInt32() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		UInt32 GetValue() { return mValue; }

	private:
		UInt32 mValue;
	};
}