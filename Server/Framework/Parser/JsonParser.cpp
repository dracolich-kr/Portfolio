#include <Pch.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

std::string JsonInfo::ToString(bool isPretty)
{
	StringBuffer buffer;

	if (isPretty == false)
	{
		Writer<StringBuffer> write(buffer);
		mRoot.Accept(write);
	}
	else
	{
		PrettyWriter<StringBuffer> write(buffer);
		mRoot.Accept(write);
	}

	return buffer.GetString();
}
