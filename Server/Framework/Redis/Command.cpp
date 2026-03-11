#include <Pch.h>

namespace Redis
{
	void BaseCommand::AddValue(bool value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Int8 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(UInt8 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Int16 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(UInt16 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Int32 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(UInt32 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Int64 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(UInt64 value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Double value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(Float value)
	{
		mValues.push_back(DefString(std::to_string(value)));
	}

	void BaseCommand::AddValue(const char* str, Size size)
	{
		mValues.push_back(DefString(str, size));
	}

	void BaseCommand::AddValue(DefString value)
	{
		mValues.push_back(value);
	}

	void BaseCommand::AddValue(const wchar_t* str, Size size)
	{
		mValues.push_back(toString(DefWString(str, size)));
	}

	void BaseCommand::AddValue(DefWString value)
	{
		mValues.push_back(toString(value));
	}
}