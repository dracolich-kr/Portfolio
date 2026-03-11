#include <Pch.h>

namespace Lua
{

	ErrorResult Function::AddParameter(::Bool value)
	{
		mParams.push_back(MakeShared<Bool>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Int8 value)
	{
		mParams.push_back(MakeShared<Int8>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Int16 value)
	{
		mParams.push_back(MakeShared<Int16>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Int32 value)
	{
		mParams.push_back(MakeShared<Int32>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Int64 value)
	{
		mParams.push_back(MakeShared<Int64>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Float value)
	{
		mParams.push_back(MakeShared<Float>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(::Double value)
	{
		mParams.push_back(MakeShared<Double>(value));

		return ErrorResult::Success;
	}

	ErrorResult Function::AddParameter(DefString value)
	{
		mParams.push_back(MakeShared<String>(value));

		return ErrorResult::Success;
	}
}