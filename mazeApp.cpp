//ABUBAKAR BABA AWUMBILA
//IMPLEMENTATION OF THE 'RIGHT-HAND RULE' MAZE SOLVING ALGORITHM

//MAZE SOLVER APPLICATION FILE

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "Maze.h"
using namespace std;


//direction function - helper function to print out current direction
string direction( int dir )
{
	//Return  string indicating the direction based on the number input
	if( dir == 1 )
	{
	    return "NORTH";
	}
	else if( dir == 2)
	     {
		return "EAST";
	     }
	     else if( dir == 3 )
		  {
			return "SOUTH";
		  }
		  else if( dir == 4 )
		       {

			   return "WEST";
			}
			else{ return "DEAD END"; }

}

// end of direction function		
	

// main function
int main()
{




	//variable declaratin
	string cont = "yes"; // used in while loop to repeat traversal of a new random maze
	string start = "no";



	// initialize random seed generator using system time
        srand( time( 0 )); 

	
	// Print out program header and contract

	cout << "\n\n====================================================================================================" << endl;
	cout << "\n\nTHIS PROGRAM TRAVERSES A RANDOM MAZE USING THE RIGHT-HAND RULE / RIGHT-WALL FOLLOWING ALGORITHM." << endl;
	cout << "WRITTEN BY ABUBAKAR BABA AWUMBILA\n\n" << endl;

	cout << "NOTES : " << endl;
	cout << "1. THE PROGRAM WILL FIRST GENERATE A RANDOM MAZE AND THEN TRAVERSE IT USING THE ABOVE MENTIONED ALGORITHM" << endl;
	cout << "2. THE PROGRAM WILL THEN PROMPT THE USER TO DECIDE IF IT SHOULD QUIT OR TRAVERSE ANOTHER RANDOM MAZE" << endl;
	cout << "3. #'S INDICATE THE WALLS OF THE MAZE" << endl;
	cout << "4. '.''S INDICATE THE MAZE PATHS" << endl;
	cout << "5. 'X' INDICATES ALREADY TRAVERSED PORTIONS OF THE MAZE." << endl;
	cout << "6. '$' INDICATES THE CURRENT POSITION OF THE MAZE TRAVERSAL ALGORITHM." << endl;
	cout << "7. EACH MAZE WILL HAVE 1, 2 OR 3 EXITS. THE NUMBER OF EXITS IS RANDOMLY DECIDED. " << endl;
	cout << "   IF MY ALGORITHM IS CORRECT, IT SHOULD ALWAYS EXIT FROM THE LOWEST POSSIBLE EXIT." << endl;


	cout << "\n\n PLEASE MAXIMIZE YOUR WINDOW FOR A BETTER VIEW OF THE PROGRAM" << endl;


	cout << "\n\n======================================================================================================\n\n" << endl;


	cout << "\n\nWould you like to begin? (Input yes or no)\n" << endl;
	
	cin >> start;

	if( start == "yes" || start == "YES")
	{




	// while loop for repeating traversal of random maze
	while(cont == "yes" || cont == "YES")
	{

		// initialize maze object
		Maze maze;
	

		cout << "\n\n===========================================================================================" << endl;


		cout << "\nTHE RANDOMLY GENERATED MAZE IS : " << endl;

		maze.printMaze();

		cout << "Start Row : " << maze.currPos[0] << ", Start Column : " << maze.currPos[1] << endl;

		cout << "Start Direction : " << direction(maze.direction) << endl;

		maze.crossOutPos();

		cout << "\n\n==> ABOUT TO START TRAVERSAL.\n\n" << endl;


		cout << "-----------------------------------------------------------------------------------------------" << endl;

		sleep(2); 

		// while loop to traverse the maxe till completeion
		while(maze.finish == 0)
		{

		maze.printMaze();

		cout << "Current Row : " << maze.currPos[0] << ", Current Column : " << maze.currPos[1] << endl;
	
		cout << "Current Direction : " << direction(maze.direction) << endl;

		maze.maze[maze.currPos[0]][maze.currPos[1]] = 'x';
	
		maze.traverseMaze();
	
		sleep(1); // time deleay to enable observation of traversal
	
		maze.maze[maze.currPos[0]][maze.currPos[1]] = '$';// used to indicate current position in array
		
		maze.complete();


		cout << "\n-----------------------------------------------------------------------------------------------" << endl;

	
		}
	
		maze.printMaze();
	
		cout << "Current Row : " << maze.currPos[0] << ", Current Column : " << maze.currPos[1] << endl;
	
		cout << "Current direction : " << maze.direction << endl;
	
		cout << "\n\nMAZE TRAVERSED\n\n" << endl;

		//prompt user to continue or end program
		cout << "\nDO YOU WANT TO TRAVERSE ANOTHER RANDOMLY GENERATED MAZE? (Input yes or no)\n" << endl;

		cin >> cont;



		cout << "\n\n===========================================================================================\n\n\n" << endl;

	}

	}

	cout << "\n\n THANK YOU FOR TAKING THE TIME TO VIEW THIS PROGRAM. \n\n\n\n" << endl;

	

} // end of main function

//END OF APPLICATION FILE

