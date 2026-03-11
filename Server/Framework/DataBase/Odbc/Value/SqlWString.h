#pragma once

namespace DataBase::ODBC
{
	class SqlWString : public SqlValue
	{
	public:
		SqlWString(Int32 column_index, Int32 buffer_length)
			: SqlValue(column_index)
		{
			mLength = buffer_length;
			mValue = (SQLWCHAR*)MemoryPool::GetInstance()->Allocate(sizeof(SQLWCHAR) * mLength);
		}

		virtual ~SqlWString()
		{
			MemoryPool::GetInstance()->Deallocate(mValue);
			mLength = 0;
		}

		virtual ErrorResult onBindCol(SqlHandleStmt stmt) override;

		DefWString GetValue() { return DefWString(mValue, mLength); }

	private:
		SQLWCHAR* mValue;
		Int32 mLength;
	};

}