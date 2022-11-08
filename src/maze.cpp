#include "maze.hpp"

//Default size if none specified by the user
maze::maze(){
	width_ = 20;
	length_ = 20;
	height_ = 20;

	maze::generateMatrix();
}
//Specified user input
maze::maze(unsigned width, unsigned length, unsigned height){
	width_ = width;
	length_ = length;
	height_ = height;

	maze::generateMatrix();
}

//Gets neighbours for a node
std::list<cell> maze::getNeighbours(cell currentCell){
	std::list<cell> neighbours;
	if(currentCell.zPos-1 != -1 && matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos-1].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos-1]);
	}
	if(currentCell.zPos+1 != length_ && matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos+1].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos+1]);
	}
	if(currentCell.yPos+1 != height_ && matrix[currentCell.xPos][currentCell.yPos+1][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos+1][currentCell.zPos]);
	}
	if(currentCell.yPos-1 != -1 &&matrix[currentCell.xPos][currentCell.yPos-1][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos-1][currentCell.zPos]);
	}
	if(currentCell.xPos+1 != width_ && matrix[currentCell.xPos+1][currentCell.yPos][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos+1][currentCell.yPos][currentCell.zPos]);
	}
	if(currentCell.xPos-1 != -1 && matrix[currentCell.xPos-1][currentCell.yPos][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos-1][currentCell.yPos][currentCell.zPos]);
	}
	return neighbours;

}
//Adds the unvisited neighbours of a cell to the frontier
void maze::addFrontier(cell currentCell){
	std::list<cell> neighbours = getNeighbours(currentCell);
	for(cell x : neighbours){
		if(std::find(frontier.begin(), frontier.end(), x) != frontier.end()){
			frontier.push_back(x);
		}
	}

}
cell getRandomMember(std::list<cell> memberList){
	int randomNum = rand() % memberList.size();
	std::list<cell>::iterator iterator = memberList.begin();
	std::advance(iterator, rand);
	return *iterator;
}

//Generates the matrix of the maze
void maze::generateMatrix(){
	srand(time(NULL)); // Generate seed for random numbers called here so that when a new maze is generated there is a new seed
	
	// Populate the maze with coords
	for(int i = 0; i < width_; i++){
		for(int j = 0; j < height_; j++){
			for(int k = 0; k < length_; k++){
				matrix[i][j][k].xPos = i;
				matrix[i][j][k].yPos = j;
				matrix[i][j][k].zPos = k;
			}
		}
	}
	cell startCell = matrix[0][0][0];
	addFrontier(startCell);
	startCell.visited = true;

	while(frontier.empty() == false){
		cell current = getRandomMember(frontier);
		std::list<cell>::iterator myIterator = frontier.begin();
		bool popped = false;
		while(popped){
			if(current.xPos == myIterator->xPos && current.yPos == myIterator->yPos && current.zPos == myIterator->zPos){
				frontier.erase(myIterator);
				popped =  true;

			}
			std::advance(myIterator, 1);
		}
		matrix[current.xPos][current.yPos][current.zPos].visited = true;
		if(current.xPos != 0 && matrix[current.xPos-1][current.yPos][current.zPos].visited == true){
			matrix[current.xPos-1][current.yPos][current.zPos].right = false;
		}
		if(current.xPos != width_ && matrix[current.xPos+1][current.yPos][current.zPos].visited == true){
			matrix[current.xPos][current.yPos][current.zPos].right = false;
		}
		if(current.yPos != 0 && matrix[current.xPos][current.yPos+1][current.zPos].visited == true){
			matrix[current.xPos][current.yPos][current.zPos].up = false;
		}
		if(current.yPos != height_ && matrix[current.xPos][current.yPos-1][current.zPos].visited == true){
			matrix[current.xPos][current.yPos-1][current.zPos].up = false;
		}
		if(current.zPos != 0 && matrix[current.xPos][current.yPos][current.zPos+1].visited == true){
			matrix[current.xPos][current.yPos][current.zPos].forward = false;
		}
		if(current.zPos != length_ && matrix[current.xPos][current.yPos][current.zPos-1].visited == true){
			matrix[current.xPos][current.yPos][current.zPos-1].forward = false;
		}

	}
}

