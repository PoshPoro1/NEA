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
	if(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos-1].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos-1]);
	}
	if(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos+1].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos][currentCell.zPos+1]);
	}
	if(matrix[currentCell.xPos][currentCell.yPos+1][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos+1][currentCell.zPos]);
	}
	if(matrix[currentCell.xPos][currentCell.yPos-1][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos][currentCell.yPos-1][currentCell.zPos]);
	}
	if(matrix[currentCell.xPos+1][currentCell.yPos][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos+1][currentCell.yPos][currentCell.zPos]);
	}
	if(matrix[currentCell.xPos-1][currentCell.yPos][currentCell.zPos].visited == false){
		neighbours.push_back(matrix[currentCell.xPos-1][currentCell.yPos][currentCell.zPos]);
	}
	return neighbours;

}
//Adds the unvisited neighbours of a cell to the frontier
void maze::addFrontier(cell currentCell){

}
//Generates the matrix of the maze
void maze::generateMatrix(){
}
