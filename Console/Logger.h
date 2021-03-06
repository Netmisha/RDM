#ifndef _LOGGER_H_
#define _LOGGER_H_

#ifndef MYLIBRARY_EXPORT_LOG 
#define MYLIBRARY_EXPORT_LOG __declspec(dllexport)
#else  
#define MYLIBRARY_EXPORT_LOG __declspec(dllimport)
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef WIN32
#include <Windows.h>
#include <process.h>
#else
#include <errno.h>
#include <pthread.h>
#endif

namespace CPlusPlusLogging
{
#define LOG_ERROR(x)    Logger::getInstance()->error(x)
#define LOG_ALARM(x)	Logger::getInstance()->alarm(x)
#define LOG_ALWAYS(x)   Logger::getInstance()->always(x)
#define LOG_INFO(x)     Logger::getInstance()->info(x)
#define LOG_BUFFER(x)   Logger::getInstance()->buffer(x)
#define LOG_TRACE(x)    Logger::getInstance()->trace(x)
#define LOG_DEBUG(x)    Logger::getInstance()->debug(x)

	typedef enum LOG_LEVEL
	{
		DISABLE_LOG = 1,
		LOG_LEVEL_INFO = 2,
		LOG_LEVEL_BUFFER = 3,
		LOG_LEVEL_TRACE = 4,
		LOG_LEVEL_DEBUG = 5,
		ENABLE_LOG = 6,
	}LogLevel;

	typedef enum LOG_TYPE
	{
		NO_LOG = 1,
		CONSOLE = 2,
		FILE_LOG = 3,
	}LogType;

	class MYLIBRARY_EXPORT_LOG Logger
	{
	public:
		static Logger* getInstance() throw ();

		void error(const char* text) throw();
		void error(std::string& text) throw();
		void error(std::ostringstream& stream) throw();

		void alarm(const char* text) throw();
		void alarm(std::string& text) throw();
		void alarm(std::ostringstream& stream) throw();

		void always(const char* text) throw();
		void always(std::string& text) throw();
		void always(std::ostringstream& stream) throw();

		void buffer(const char* text) throw();
		void buffer(std::string& text) throw();
		void buffer(std::ostringstream& stream) throw();

		void info(const char* text) throw();
		void info(std::string& text) throw();
		void info(std::ostringstream& stream) throw();

		void trace(const char* text) throw();
		void trace(std::string& text) throw();
		void trace(std::ostringstream& stream) throw();

		void debug(const char* text) throw();
		void debug(std::string& text) throw();
		void debug(std::ostringstream& stream) throw();

		void updateLogLevel(LogLevel logLevel);
		void enaleLog();  
		void disableLog();

		void updateLogType(LogType logType);
		void enableConsoleLogging();
		void enableFileLogging();

	protected:
		Logger();
		~Logger();

		void lock();
		void unlock();

		std::string getCurrentTime();

	private:
		void logIntoFile(std::string& data);
		void logOnConsole(std::string& data);
		Logger(const Logger& obj) {}
		void operator=(const Logger& obj) {}

	private:
		static Logger*          m_Instance;
		std::ofstream           m_File;

#ifdef	WIN32
		CRITICAL_SECTION        m_Mutex;
#else
		pthread_mutexattr_t     m_Attr;
		pthread_mutex_t         m_Mutex;
#endif

		LogLevel                m_LogLevel;
		LogType                 m_LogType;
	};

} 

#endif