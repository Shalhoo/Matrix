#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <random>
#include "Structs.h"
#include "Utils.h"

using namespace std;

	consoleWH Utils::getConsoleData() {
		HANDLE hWndConsole;
		if (hWndConsole = GetStdHandle(-12))
		{
			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
			GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo);
			int widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
			consoleWH consoleData;
			consoleData.height = height;
			consoleData.width = widht;
			return consoleData;
		}
	}

	int Utils::getRandom(int left, int right) {
		int l = left, r = right;
		if (left > right)
		{
			r = left;
			l = right;
		}
		random_device rgen;
		unsigned seed = rgen();
		default_random_engine rgenE(seed);
		uniform_int_distribution<int> myUnifIntDist(l, r);
		return myUnifIntDist(rgenE);
	};

	int Utils::getRandom(int right) {
		return Utils::getRandom(0, right);
	}

	bool Utils::probabilityCheck(int prob) {
		if (getRandom(1000) > prob) {
			return false;
		}
		else
		{
			return true;
		}
	}