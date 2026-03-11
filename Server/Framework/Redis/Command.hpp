#pragma once

namespace Redis
{
	template<class T>
	void BaseCommand::AddValue(T value)
	{
		flatbuffers::FlatBufferBuilder builder;
		builder.Finish(value);

		auto data = builder.GetBufferPointer();
		Int32 length = builder.GetSize();

		//mValues.push_back(DefString(data, length));
	}
}