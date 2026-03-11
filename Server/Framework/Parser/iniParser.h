#pragma once

class IniParser
{
public:
	IniParser() {}
	virtual ~IniParser() {}

	ErrorResult Open(std::string file_name);

private:
	INI::File mFile;

};