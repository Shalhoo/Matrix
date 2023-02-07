#include "Explosion.h"
#include <stdio.h>
#include "Utils.h"
#include "Symbol.h"
#include <ctime>
#include "Structs.h"

Explosion::Explosion(int x,int y,int minRad, int maxRad) : Figure(x,y){
	moveTime = clock() + 1000 / speed;
	radius = Utils::getRandom(minRad, maxRad);
}

Explosion::~Explosion()
{

}

void Explosion::draw() {
	const int space = 32;
	for (int i = -currentRadius; i <= currentRadius; i++)
	{
		for (int j = -currentRadius; j <= currentRadius; j++)
		{
			
			int charCode = space;
			int length = abs(i) + abs(j);
			int newX = x + i, newY = y + j;
			
			if (!borderTouched(newX,newY))
			{
				if (length == currentRadius)
				{
					if (!isEnded())
					{
						charCode = Utils::getRandom(space + 1, 127);
					}
					Symbol s(newX, newY);
					s.setColor(Utils::getRandom(1, 6));
					s.print(charCode);
				}
				else if (length == currentRadius-1) {
					Symbol s(newX, newY);
					s.print(space);
				}
			}		
		}
	}
	if (currentRadius >= radius)
	{
		changeStatus();
	}
	currentRadius++;
}
