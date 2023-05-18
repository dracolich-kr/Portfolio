#include <Pch.h>

void LogManager::Initalize()
{
	mConfig.configure();
}

SharedLogger LogManager::GetLogger(DefWString logger_name)
{
	return MakeShared<Logger>(Logger(log4cplus::Logger::getInstance(logger_name.c_str())));
}

SharedLogger LogManager::GetLogger(DefString logger_name)
{
	return GetLogger(toWString(logger_name));
}