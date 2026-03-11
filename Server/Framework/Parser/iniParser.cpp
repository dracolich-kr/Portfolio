#include <Pch.h>

ErrorResult IniParser::Open(std::string file_name)
{
	Int32 result = mFile.Load(file_name);

	return ErrorResult::Success;
}