#pragma once

namespace DataBase::ODBC
{
	class SqlString : public SqlValue
	{
	public:
		SqlString(Int32 column_index, Int32 length)
			: SqlValue(column_index)
		{
			mLength = length;
			mValue = (SQLCHAR*)MemoryPool::GetInstance()->Allocate(sizeof(SQLCHAR) * mLength);
		}
		virtual ~SqlString() 
		{
			MemoryPool::GetInstance()->Deallocate(mValue);
			mLength = 0;
		}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		DefString GetValue() { return DefString((char*)mValue, mLength); }

	private:
		SQLCHAR* mValue;
		Int32 mLength;
	};

}