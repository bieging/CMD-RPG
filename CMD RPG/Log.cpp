#include "Log.h"

Log::Log()
{

}

Log::~Log()
{

}

void Log::writeLine(std::string str)
{
	std::cout << str << std::endl;
}

void Log::writeLine(std::string str, std::string arg0)
{
	if (str.size() > 3)
	{
		std::string newString;

		for (size_t i = 0; i < str.size() - 2; i++)
		{
			if
				(
					str.at(i + 0) == '{' &&
					str.at(i + 1) == '0' &&
					str.at(i + 2) == '}'
					)
			{
				for (size_t j = 0; j < arg0.size(); j++)
				{
					newString.push_back(arg0.at(j));
				}
			}
			else
			{
				newString.push_back(str.at(i));
			}
		}

		std::cout << newString << std::endl;
	}
	else
	{
		std::cout << str << std::endl;
	}
}

void Log::writeLine(std::string str, std::string arg0, std::string arg1)
{

}

void Log::writeLine(std::string str, std::string arg0, std::string arg2, std::string arg3)
{

}

void Log::breakLine()
{
	std::cout << std::endl;
}

void Log::waitForReturn()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//std::cin.get();
}
