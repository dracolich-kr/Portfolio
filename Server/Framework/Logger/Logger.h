#pragma once

enum class LoggerType
{
	Trace = 0
	, Debug = 1
	, Info = 2
	, Warning = 3
	, Error = 4
	, Fatel = 5
};

class Logger;
using SharedLogger = std::shared_ptr<Logger>;

class LogManager : public Singleton<LogManager>
{
private:
	friend Singleton<LogManager>;

	LogManager() {}

public:
	void Initalize();

	SharedLogger GetLogger(DefWString logger_name);
	SharedLogger GetLogger(DefString logger_name);

private:
	log4cplus::Initializer mInitalizer;
	log4cplus::BasicConfigurator mConfig;
};

// 걍 디파인으로 써먹는게 좋은거 같긴함 밑에 매크로를 써먹질 못하니..
// __FILE__, __LINE__, __FUNC__ ....
class Logger
{
public:
	Logger(log4cplus::Logger logger) 
		: mLogger(logger)
	{
	}

	log4cplus::Logger& GetLogger() { return mLogger; }

private:
	log4cplus::Logger mLogger;
};

#define LOG_TRACE(logger, log_event) LOG4CPLUS_TRACE(logger->GetLogger(), log_event)
#define LOG_DEBUG(logger, log_event) LOG4CPLUS_DEBUG(logger->GetLogger(), log_event)
#define LOG_INFO(logger, log_event) LOG4CPLUS_INFO(logger->GetLogger(), log_event)
#define LOG_WARN(logger, log_event) LOG4CPLUS_WARN(logger->GetLogger(), log_event)
#define LOG_ERROR(logger, log_event) LOG4CPLUS_ERROR(logger->GetLogger(), log_event)
#define LOG_FATAL(logger, log_event) LOG4CPLUS_FATAL(logger->GetLogger(), log_event)

#define LOG_TRACE_FMT(logger, ...) LOG4CPLUS_TRACE_FMT(logger->GetLogger(), __VA_ARGS__)
#define LOG_DEBUG_FMT(logger, ...) LOG4CPLUS_DEBUG_FMT(logger->GetLogger(), __VA_ARGS__)
#define LOG_INFO_FMT(logger, ...) LOG4CPLUS_INFO_FMT(logger->GetLogger(), __VA_ARGS__)
#define LOG_WARN_FMT(logger, ...) LOG4CPLUS_WARN_FMT(logger->GetLogger(), __VA_ARGS__)
#define LOG_ERROR_FMT(logger, ...) LOG4CPLUS_ERROR_FMT(logger->GetLogger(), __VA_ARGS__)
#define LOG_FATAL_FMT(logger, ...) LOG4CPLUS_FATAL_FMT(logger->GetLogger(), __VA_ARGS__)
