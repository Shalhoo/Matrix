#pragma once
#include "Symbol.h"
#include "Structs.h"
#include "Figure.h"

class Line : public Figure {
public:
	Line(int x, int y, int speed, int leng, bool epil, int proba);
	~Line();
	void draw();
	bool checkExp();
	bool borderTouched();

private:
	int  length, prevChar = 32,probability;
	bool epilepsy, blowing = false;
	
};