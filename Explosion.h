#pragma once
#include "Figure.h"

class Explosion : public Figure
{
public:
	Explosion(int x, int y, int minRad, int maxRad);
	~Explosion();
	void draw();
private:
	int radius,currentRadius = 0;
};

