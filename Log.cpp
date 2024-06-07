#include "Log.h"

Log::Log()
	: m_LogLevel(LogLevel::INFO)
{
}

Log::Log(const LogLevel logLevel)
{
	// Set the log level.
	m_LogLevel = logLevel;
}

/**
 * Static method to get the instance of the Log class.
 */
Log* Log::GetInstance()
{
	if (!Log::s_Instance)
		s_Instance = new Log();

	return s_Instance;
}

/**
 * Set the indent of the Log class.
 */
Log* Log::SetIndent(int indent)
{
	m_Indent = indent;

	return this;
}

/**
 * Increase the indent of the Log class.
 */
Log* Log::IncreaseIndent(int indent)
{
	m_Indent += indent;

	return this;
}

/**
 * Decrease the indent of the Log class.
 */
Log* Log::DecreaseIndent(int indent)
{
	m_Indent -= indent;

	return this;
}

/**
 * Print a message to the console.
 */
Log* Log::Print(std::string message)
{
	// Print the indentation first
	for (int i = 0; i < m_Indent; i++)
		std::cout << " ";

	// Print the message.
	std::cout << message << std::endl;

	return this;
}

/**
 * Get the indent of the Log class.
 */
int Log::GetIndent() const
{
	return m_Indent;
}