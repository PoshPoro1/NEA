#pragma once
#include <vector>
#include <list>
#include "cell.hpp"
class maze{
	private:
		unsigned width_, length_, height_;
		std::list<cell> frontier;
		std::vector<std::vector<std::vector<cell>>> matrix;
		std::list<cell> getNeighbours(cell currentCell);
		void addFrontier(cell currentCell);
		void generateMatrix();
	public:
		maze();
		maze(unsigned width, unsigned length);
		maze(unsigned width, unsigned length, unsigned height);
};
