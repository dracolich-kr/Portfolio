#pragma once

namespace DataBase::ODBC
{
	class SqlUInt16 : public SqlValue
	{
	public:
		SqlUInt16(Int32 column_index)
			: SqlValue(column_index)
			, mValue(0)
		{}
		virtual ~SqlUInt16() {}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		UInt16 GetValue() { return mValue; }

	private:
		UInt16 mValue;
	};
}