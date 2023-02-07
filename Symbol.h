#pragma once

class Symbol {
public:
	int x;
	int y;

	Symbol(int x, int y);
	void setColor(int col);
	void print(char charCode);

private:
	int color = 15;
};