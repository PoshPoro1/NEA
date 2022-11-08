
#pragma once
#include <vector>
#include <list>
#include <time.h>
#include <random>
#include <algorithm>
struct cell{
	unsigned xPos, yPos, zPos;
	bool up=true;
	bool right=true;
	bool forward=true;
	bool visited;
};
class maze{
	private:
		unsigned width_, length_, height_;
		std::list<cell> frontier;
		std::vector<std::vector<std::vector<cell>>> matrix;
		std::list<cell> getNeighbours(cell currentCell);
		void addFrontier(cell currentCell);
		cell getRandomMember(std::list<cell> memberList);
		void generateMatrix();
	public:
		maze();
		maze(unsigned width, unsigned length);
		maze(unsigned width, unsigned length, unsigned height);
};
