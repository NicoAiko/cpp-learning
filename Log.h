#pragma once

#include <iostream>
#include <string>

#define LOG(x) Log::GetInstance()->Print(x)
#define DLOG(x) Log::GetInstance()->IncreaseIndent(2)->Print(x)->DecreaseIndent(2)

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
	static inline Log* s_Instance;
	int m_Indent = 0;
};