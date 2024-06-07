#pragma once

#include <iostream>
#include <string>

#define LOG(x) Log::GetInstance()->Print(x)
#define DLOG(x) Log::GetInstance()->IncreaseIndent(2)->Print(x)->DecreaseIndent(2)
#define LOG_DECONSTRUCT delete Log::GetInstance()

enum LogLevel
{
	INFO,
	WARNING,
	ERROR
};

class Log
{
public:
	static Log* GetInstance();
	Log* SetIndent(int indent);
	Log* IncreaseIndent(int indent);
	Log* DecreaseIndent(int indent);
	Log* Print(std::string message);
	int GetIndent() const;

private:
	Log() = default;
	Log(const LogLevel logLevel);

private:
	static inline Log* s_Instance;
	int m_Indent = 0;
	LogLevel m_LogLevel;
};