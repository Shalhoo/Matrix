#include "Figure.h"
#include "Symbol.h"
#include "Utils.h"

Figure::Figure(int x, int y, int sp) : x(x), y(y), speed(sp){
	console = Utils::getConsoleData();
}

int Figure::getMoveTime(){
	return moveTime;
}

void Figure::changeStatus(bool newStatus) {
	ended = newStatus;
}

void Figure::draw() {
	Symbol s(2,10);
	s.setColor(1);
	s.print('.');
}

void Figure::moveTimeInc() {
	moveTime += 1000 / speed;
}

bool Figure::isLine() {
	return line;
}

bool Figure::isEnded() {
	return ended;
}

bool Figure::borderTouched(int x, int y) {
	if (x > 0 && x < console.width && y > 0 && y < console.height)
	{
		return false;
	}
	return true;
}

bool Figure::checkExp() { 
	return false; 
}

coords Figure::getCoords() {
	coords c;
	c.x = x;
	c.y = y;
	return c;
}

Figure::~Figure()
{
}