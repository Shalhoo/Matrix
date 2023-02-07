#pragma once
#include <string>
#include "Structs.h"
#include "Utils.h"
#include "Line.h"

class Manager {

public:
	void start();
	void enter();
	int readInt(int a, int b);	
	bool readBool(std::string message);
	bool checkNum(std::string str);
	void create();

private:
	int length, frequency, speed, probability, minRadius, maxRadius;
	bool epilepsy;
	};