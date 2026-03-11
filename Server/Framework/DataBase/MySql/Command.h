#pragma once

namespace DataBase::MySql
{
	class Command
		: public DataBase::Command
	{
	public:
		Command()
			: mSet(nullptr)
			, mCall(nullptr)
			, mSelect(nullptr)
		{
		}

		ErrorResult Init(DataBase::SharedSession session, DefWString procedure);
		ErrorResult Release();

		ErrorResult BindParam(Int16 inout_type, Int64 value) override;
		ErrorResult BindParam(Int16 inout_type, UInt64 value) override;
		ErrorResult BindParam(Int16 inout_type, Int32 value) override;
		ErrorResult BindParam(Int16 inout_type, UInt32 value) override;
		ErrorResult BindParam(Int16 inout_type, Int16 value) override;
		ErrorResult BindParam(Int16 inout_type, UInt16 value) override;
		ErrorResult BindParam(Int16 inout_type, Int8 value) override;
		ErrorResult BindParam(Int16 inout_type, UInt8 value) override;
		ErrorResult BindParam(Int16 inout_type, Char value) override;
		ErrorResult BindParam(Int16 inout_type, Float value) override;
		ErrorResult BindParam(Int16 inout_type, Double value) override;
		ErrorResult BindParam(Int16 inout_type, DefString value) override;
		ErrorResult BindParam(Int16 inout_type, DefWString value) override;

		virtual ~Command() {}

	private:
		DefString mMessage;
		std::shared_ptr<DataBase::MySql::Session> mSession;

		MYSQL_STMT* mSet;
		MYSQL_STMT* mCall;
		MYSQL_STMT* mSelect;
	};
}