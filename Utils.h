#pragma once
#include <string>
#include "Structs.h"


class Utils {
public:
	static consoleWH getConsoleData();
	static bool isNumber(std::string str);
	static int getRandom(int left, int right);
	static int getRandom(int right);
	static bool probabilityCheck(int prob);
};