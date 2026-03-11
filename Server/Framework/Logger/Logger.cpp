#include <Pch.h>

ErrorResult LogManager::Initalize()
{
	mConfig.configure();

	return ErrorResult::Success;
}

log4cplus::Logger LogManager::GetLogger(DefWString logger_name)
{
	return log4cplus::Logger::getInstance(logger_name.c_str());
}

log4cplus::Logger LogManager::GetLogger(DefString logger_name)
{
	return GetLogger(toWString(logger_name));
}