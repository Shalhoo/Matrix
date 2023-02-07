#include "Line.h"
#include <ctime>
#include "Utils.h"
#include "Structs.h"

Line::Line(int x, int y, int speed, int leng, bool epil, int probab) : Figure(x, y, speed), length(leng), epilepsy(epil), probability(probab){
	moveTime = clock() + Utils::getRandom(999);
	line = true;
};

void Line::draw() {
	if (x < console.width + length + 1) {
		if (!borderTouched()) {
			const int white = 7;
			int color = white;
			int oldColor = 2;
			int charCode = Utils::getRandom(33, 127);

			if (epilepsy)
			{
				oldColor = Utils::getRandom(1, white - 1);
			}

			Symbol s(x - 1, y);
			s.setColor(oldColor);
			s.print(prevChar);
			prevChar = charCode;

			if (x <= console.width - 1)
			{
				Symbol s(x, y);
				s.setColor(color);
				s.print(charCode);
			}
		}

		int newX = x - length - 1;
		Symbol s(newX + 1, y);
		s.print(' ');
	} 
	else 
	{
		changeStatus();
	}
	x++;
}

bool Line::checkExp() {
	if (Utils::probabilityCheck(probability) && !borderTouched())
	{
		length--;
		x++;

		if (length <= 0) {
			changeStatus();
		}
		return true;
	}
		return false;
}

bool Line::borderTouched() {
	if (x > console.width) {
		return true;
	}
	else {
		return false;
	}
}

Line::~Line() {
}
