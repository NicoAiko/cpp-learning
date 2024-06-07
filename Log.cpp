#include "Log.h"

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
	this->m_Indent += indent;

	return this;
}

/**
 * Decrease the indent of the Log class.
 */
Log* Log::DecreaseIndent(int indent)
{
	this->m_Indent -= indent;

	return this;
}

/**
 * Print a message to the console.
 */
Log* Log::Print(std::string message)
{
	for (int i = 0; i < m_Indent; i++)
		std::cout << " ";

	std::cout << message << std::endl;

	return this;
}