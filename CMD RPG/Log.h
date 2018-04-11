#ifndef LOG_H
#define LOG_H

#pragma once

#include <iostream>
#include <string>

class Log
{
public:
	Log();
	~Log();

	static void writeLine(std::string str);
	static void writeLine(std::string str, std::string arg0);
	static void writeLine(std::string str, std::string arg0, std::string arg1);
	static void writeLine(std::string str, std::string arg0, std::string arg2, std::string arg3);

	static void breakLine();

	static void waitForReturn();
private:
};

#endif // !LOG_H