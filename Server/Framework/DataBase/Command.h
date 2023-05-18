#pragma once

namespace DataBase
{
	class Command
	{
	public:
		virtual ErrorResult BindParam(Int16 inout_type, Int64 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, UInt64 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Int32 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, UInt32 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Int16 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, UInt16 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Int8 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, UInt8 value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Char value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Float value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, Double value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, DefString value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, DefWString value) PURE;
		virtual ErrorResult BindParam(Int16 inout_type, DateTime value) PURE;

		const DefWString GetCommand() { return mCommand; }

	private:
		DefWString mCommand;
	};
}