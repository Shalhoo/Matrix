#include "Manage.h"
#include <iostream>
#include "Explosion.h"
#include "Figure.h"
#include "ArrayList.h"

using namespace std;

	void Manager::start() {
		cout << "Welcome to the Matrix-zone" << endl << "Everything begins with choice" << endl;
		enter();
		create();
	}

	void Manager::enter() {
		cout << "Choose the frequence of the lines. ";
		frequency = readInt(1, 30);
		cout << "Choose the speed of the lines. ";
		speed = readInt(1, 30);
		cout << "Choose the length of the lines. ";
		length = readInt(1, 30);
		cout << "Input if you ready to play epilepsy mode or if not. ";
		epilepsy = readBool("Y|N");
		cout << "Choose the probability of explosion. ";
		probability = readInt(1, 1000);

		while (true)
		{
			cout << "Choose the min radius of explosion. ";
			minRadius = readInt(1, 10);
			cout << "Choose the max radius of explosion. ";
			maxRadius = readInt(1, 10);

			if (minRadius <= maxRadius) {
				break;
			}
			else
			{
				cout << "Lower radius mustn't be over higher | ";
			}
		}
		system("cls");
	}
	
	void Manager::create() {
		Vector<Figure*> figures;
		int prevTime = clock() - 1000;

		while (true)
		{
			if (clock() - prevTime >= 1000)
			{
				for (size_t i = 0; i < frequency; i++)
				{
					Line* l = new Line(1, Utils::getRandom(Utils::getConsoleData().height), speed, length, epilepsy, probability);
					figures.push_back(l);
				}
				prevTime = clock();
			}
			for (size_t i = 0; i < figures.list_size(); i++)
			{
				if (clock() >= figures[i]->getMoveTime())
				{
					figures[i]->draw();
					figures[i]->moveTimeInc();
					if (figures[i]->isLine())
					{
						if (figures[i]->checkExp())
						{
							coords XY = (figures[i]->getCoords());
							Explosion* e = new Explosion(XY.x, XY.y, minRadius, maxRadius);
							
							figures.push_back(e);
						}
					}
				}				
				if (figures[i]->isEnded())
				{
					if (!figures[i]->isLine())
					{
						figures[i]->draw();
					}
					delete figures[i];
					figures.erase(i);
				}
			}
		}
	}

	int Manager::readInt(int a,int b) {
		while (true)
		{
			string str;
			cout << "Input the value from: " << a << " to " << b << ":";
			cin >> str;
			if (Manager::checkNum(str))
			{
				if (atoi(str.c_str()) < a || atoi(str.c_str()) > b)
				{
					cout << "Error. Input the value from the range: " << endl;
				}
				else
				{
					return atoi(str.c_str());
				}
			}
			else
			{
				cout << "Integers only. " << endl;
			}
		}
	}

	bool Manager::readBool(string message) {
		while (true)
		{
			char ch;
			cout << message << ": ";
			cin >> ch;
			if (ch == 'Y' or ch == 'y')
			{
				return true;
			}
			else if (ch == 'N' or ch == 'n') {
				return false;
			}
			else
			{
				cout << "Wrong insert data, write Y or N!!" << endl;
			}
		}
	}

	bool Manager::checkNum(string str) {
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
				return false;
		}
		return true;
	}
