#include <iostream>
#include "Symbol.h"
#include "Utils.h"


Symbol::Symbol(int x, int y) : x(x), y(y) {
	
};

void Symbol::setColor(int col) {
		this->color = col;
	}

void Symbol::print(char charCode) {
		printf("\033[%d;%dH\033[0;%d;%dm%c", y, x, 30 + color, 40, charCode);
	}
