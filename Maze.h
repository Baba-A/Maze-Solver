//ABUBAKAR BABA AWUMBILA
//IMPLEMENTATION OF THE 'RIGHT-HAND RULE' MAZE SOLVING ALGORITHM


//MAZE SOLVER HEADER FILE


#include <iostream>
using namespace std;


//MAZE CLASS
class Maze
{
	public:
	Maze(); //Initializes maze object
	void randomMaze(); // generates a random maze
	void printMaze(); // prints out maze
	void crossOutPos(); // crosses out a current position 
	void updateDirectionRight(); //updates the direction when the maze is traversed towrads the right
	void updateDirectionDown(); //updates the direction when the maze is traversed downward
	void updateDirectionLeft(); //updates the direction when the maze is traversed towrds the left
	void updateDirectionUp(); //updates the direction when the maze is traversed upward
	void deadEnd(); // checks if the current position is a dead end
	bool checkRight( char ); // checks the right character in the array
	bool checkDown( char ); // checks the lower charcter in the array
	bool checkLeft( char ); // checks the left charcter in the array
	bool checkUp( char ); // checks the upper charcter in the array
	void moveRight(); //traverses the array rightward by one postion
	void moveDown(); //traverses the array downward by one postion
	void moveLeft(); //traverses the array leftward by one postion
	void moveUp(); //traverses the array upward by one postion
	void complete(); //checks if the maze has been cmpleted
	void traverseMaze(); //traverses the array in the next available direction according to the right wall algoritm


	//VARIABLE DECLARATIONS	
	char maze[12][12]; // 12 x 12 character array for maze
	int start[2]; // stores atrt position
	int currPos[2]; // stores current position
	int direction; // stores current direction
	int finish; // 0 = not complete, 1 = complete 

};


//END OF MAZE SOLVER HEADER FILE
	
