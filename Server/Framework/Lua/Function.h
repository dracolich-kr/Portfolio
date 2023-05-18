#pragma once

namespace Lua
{
	// 루아 함수 로드
	class Function
	{
	public:
		Function(DefString func_name)
			: mFuncName(func_name)
		{}
		virtual ~Function() {}

		ErrorResult AddParameter(::Bool value);
		ErrorResult AddParameter(::Int8 value);
		ErrorResult AddParameter(::Int16 value);
		ErrorResult AddParameter(::Int32 value);
		ErrorResult AddParameter(::Int64 value);
		ErrorResult AddParameter(::Float value);
		ErrorResult AddParameter(::Double value);
		ErrorResult AddParameter(DefString value);

		const DefString GetFuncName() { return mFuncName; }

		const ::Size GetParamSize() { return mParams.size(); }
		const List<std::shared_ptr<BaseValue>> GetParams() { return mParams; }

		const ::Size GetResultSize() { return mResult.size(); }
		const List<std::shared_ptr<BaseValue>> GetResults() { return mResult; }

	private:
		List<std::shared_ptr<BaseValue>> mParams;
		List<std::shared_ptr<BaseValue>> mResult;
		DefString mFuncName;

	};
}