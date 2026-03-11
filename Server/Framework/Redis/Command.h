#pragma once


namespace Redis
{
	static constexpr Int32 gBufferSize = 10'384;

	class BaseCommand
	{
	public:
		BaseCommand(DefString command)
			: mCommand(command)
		{
			mKey.reserve(128);
			mErrorCode.reserve(128);
			mErrorMessage.reserve(128);
		}

		virtual ~BaseCommand() {}

		void SetCommand(DefString& command) { mCommand = command; }
		void SetKey(DefString& key) { mKey = key; }

		DefString& GetCommmand() { return mCommand; }
		DefString& GetKey() { return mKey; }

		size_t GetSize() { return 1 + mValues.size(); }

		const StringList& GetBuffer() { return mValues; }

		template<class T>
		void AddValue(T value);

		void AddValue(bool value);
		void AddValue(Int8 value);
		void AddValue(UInt8 value);
		void AddValue(Int16 value);
		void AddValue(UInt16 value);
		void AddValue(Int32 value);
		void AddValue(UInt32 value);
		void AddValue(Int64 value);
		void AddValue(UInt64 value);
		void AddValue(Double value);
		void AddValue(Float value);

		void AddValue(const char* str, Size size);
		void AddValue(DefString value);

		void AddValue(const wchar_t* str, Size size);
		void AddValue(DefWString value);

	public:
		virtual ErrorResult onResult(RedisReply reply) PURE;

	protected:
		DefString mCommand;
		DefString mKey;

		StringList mValues;

		DefString mErrorCode;
		DefString mErrorMessage;

	};

	using Command = std::shared_ptr<BaseCommand>;
}

#include "Command.hpp"