#pragma once

namespace DataBase::ODBC
{
	class SqlUInt8 : public SqlValue
	{
	public:
		SqlUInt8(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlUInt8() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		UInt8 GetValue() { return mValue; }

	private:
		UInt8 mValue;
	};
}