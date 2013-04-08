//ABUBAKAR BABA AWUMBILA
//IMPLEMENTATION OF THE 'RIGHT-HAND RULE' MAZE SOLVING ALGORITHM


//MAZE SOLVER IMPLEMENTATION FILE


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "Maze.h"
using namespace std;



// Maze constructor
Maze::Maze()
{

	randomMaze(); // generate random maze
	finish = 0; // set finish to 0, i.e. not finished
	

} // end od maze cnstructor




//random maze function - genrates a random maze to enable the testing of the rght-hand rule maze solver algorithm
void Maze::randomMaze()
{
	//fill out upper and lower boundaries with #'s
	for(int i = 0; i < 12; i++)
	{
		maze[0][i] = '#';
	}

	for(int i = 0; i < 12; i++)
	{
		maze[11][i] = '#';
	}	



	//fill out everything else with blank spaces
	for(int i = 1; i < 11; i++)
	{
		for(int j = 0; j < 12; j++)
		{

			maze[i][j] = ' ';
		}
	}	


	//variable declarations
	int start;
	int currRow = start;
	int currCol = 1;
	int num0Exits = ((rand() % 3) + 1); // determines the number of exits
	direction = 2;

	start = ((rand() % 10) + 1);

	for( int i = 0; i < num0Exits; i++)
	{

	// pick a random start row

	currRow = start;
	currCol = 1;


	//fill out first two positions with dots
	maze[start][0] = '.';
	maze[currRow][currCol] = '.';

 	
	//while we ar not at the en dof th emaze
	while(currCol != 11)
	{

		// randomly map out a maze while filling the mapped out maze with dots ( two dots at a time )
		switch(direction)
		{


		case 2:
		   maze[currRow][currCol + 1] = '.';	
		   currCol = (currCol + 1);
		   maze[currRow][currCol + 1] = '.';	
		   currCol = (currCol + 1);
		   direction = ((rand() % 4) + 1);
		break;

		case 3:
		   
		   maze[currRow+ 1][currCol] = '.';
		   currRow = (currRow + 1);
		   maze[currRow+ 1][currCol] = '.';
		   currRow = (currRow + 1);
		   direction = ((rand() % 4) + 1);		
		break;


		case 4:
		   maze[currRow][currCol - 1] = '.';
		   currCol = (currCol - 1);
		   maze[currRow][currCol - 1] = '.';
		   currCol = (currCol - 1);
		   direction = ((rand() % 4) + 1);
		break;


		case 1:
		    maze[currRow - 1][currCol] = '.';
		    currRow = (currRow - 1);
		    maze[currRow - 1][currCol] = '.';
		    currRow = (currRow - 1);
		    direction = ((rand() % 4) + 1);				
		break;

		}

		//ensure the maze doesnt exceed boundaries
		if(((currCol - 1) <= 0) | ((currCol - 2) <= 0)) // check left boundary
		{
			direction = 2;
		}
		
		///check upper boundary
		while(((maze[currRow - 2][currCol] == '#') | (maze[currRow - 1][currCol] == '#')) && (direction == 1))
		{
			direction = ((rand() % 4) + 1);
		}

		//check lower boundary
		while(((maze[currRow + 2][currCol] == '#') | (maze[currRow + 1][currCol] == '#')) && (direction == 3))
		{
			direction = ((rand() % 4) + 1);
		}

	

	}

	}




	//fill out everything else with #'s
	for(int i = 1; i < 11; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(maze[i][j] != '.')
			{	
				maze[i][j] = '#';
			}
		}
	}

	direction = 2;

	//find the start row and save it in the currPos matrix
	for(int i = 0; i < 12; i++)
	{

		if(maze[i][0] == '.')
		{
			
			currPos[0] = i;
		}
		//set the current cloumn to 0 
		currPos[1] = 0;
	}
}//end of randomMaze function





//PrintMaze function - print out the random maze
void Maze::printMaze()
{
	cout << endl;

	for(int i = 0; i < 12; i++)
	   {
		for(int j = 0; j < 12; j++)
		   {
			cout << maze[i][j] << " ";
		   }
		cout << endl;
	    }

	cout << endl;
} //end of printMaze function




//crossOutpos function - cross out a position once it has been traversed
void Maze::crossOutPos()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	maze[curr1][curr2] = 'x';
} //end of crossoutPos function



//updateDirectionRight function
void Maze::updateDirectionRight()
{
	//1 = up, 2 = right, 3 = south, 4 = left ,5 = deadend
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	 if(maze[curr1][curr2 - 1] == 'x')
	  	{
			direction = 2; //just moved right
	  	}


} // end of function




//updateDirectionDown function
void Maze::updateDirectionDown()
{
	//1 = up, 2 = right, 3 = south, 4 = left ,5 = deadend
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1 - 1][curr2] == 'x')
 	  {
        	   direction = 3; //just moved down
       }
} // end of function




//updateDirectionLeft function
void Maze::updateDirectionLeft()
{
	//1 = up, 2 = right, 3 = south, 4 = left ,5 = deadend
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1][curr2 + 1] == 'x')
 	  {
        	   direction = 4; //just moved left
       }
} // end of function




//updateDirectionUp function
void Maze::updateDirectionUp()
{
	//1 = up, 2 = right, 3 = south, 4 = left ,5 = deadend
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1 + 1][curr2] == 'x')
 	  {
        	   direction = 1; //just moved Up
       }
} // end of function




//deadEnd function
void Maze::deadEnd()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(((direction == 1) && (maze[curr1][curr2 + 1] == '#') && (maze[curr1 - 1][curr2] == '#') && (maze[curr1][curr2 - 1] == '#')) 
		| ((direction == 2) && (maze[curr1][curr2 + 1] == '#') && (maze[curr1 - 1][curr2] == '#') && (maze[curr1 + 1][curr2] == '#')) 
		| ((direction == 3) && (maze[curr1][curr2 + 1] == '#') && (maze[curr1][curr2 - 1] == '#') && (maze[curr1 + 1][curr2] == '#')) 
		| ((direction == 4) && (maze[curr1][curr2 - 1] == '#') && (maze[curr1 - 1][curr2] == '#') && (maze[curr1 + 1][curr2] == '#')) )
	  {
	      direction = 5;
	   }

} // end of function




//checkRight function
bool Maze::checkRight( char dotOrX )
{  //dotOrX = '.' or 'x'

	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1][curr2 + 1] == dotOrX)
	  {
		return true;
	  }
	else { return false;  }
} // end of function




//checkDown function
bool Maze::checkDown( char dotOrX )
{  //dotOrX = '.' or 'x'

	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1 + 1][curr2 ] == dotOrX)
	  {
		return true;
	  }
	else { return false;  }
} // end of function




//checkLeft function
bool Maze::checkLeft( char dotOrX )
{  //dotOrX = '.' or 'x'

	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1][curr2 - 1] == dotOrX)
	  {
		return true;
	  }
	else { return false;  }
} // end of function



//checkUp function
bool Maze::checkUp( char dotOrX )
{  //dotOrX = '.' or 'x'

	int curr1 = currPos[0];
	int curr2 = currPos[1];

	if(maze[curr1 - 1][curr2] == dotOrX)
	  {
		return true;
	  }
	else { return false;  }
} // end of function





// moveRight function		
void Maze::moveRight()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	
	maze[curr1][curr2 + 1] = 'x';
	currPos[0] = curr1;	
	currPos[1] = (curr2 + 1);
} // end of function



// moverDown function
void Maze::moveDown()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	
	maze[curr1 + 1][curr2] = 'x';
	currPos[0] = (curr1 + 1);	
	currPos[1] = curr2;
} // end of function



// moveLeft function
void Maze::moveLeft()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];


	maze[curr1][curr2 - 1] = 'x';
	currPos[0] = curr1;	
	currPos[1] = (curr2 - 1);
} // end of function


// moveUp function
void Maze::moveUp()
{
	int curr1 = currPos[0];
	int curr2 = currPos[1];

	
	maze[curr1 - 1][curr2] = 'x';
	currPos[0] = (curr1 - 1);	
	currPos[1] = curr2;

} // end of function




//complete function - checks to see if the maze has been completed
void Maze::complete()
{

	if(currPos[1] == 11)
	  {
		finish = 1;
	  }

} // end of function





// traverse maze function - traverses the maze using the right-hand rule/ right-wall following algorithm
void Maze::traverseMaze()
{

	//use right wall following algoritm to move to next position
	switch(direction)
	{
		case 2:
		   if(checkDown( '.' ))
	  		{
			moveDown();
			updateDirectionDown();
			  }
		   else if(checkRight( '.' ))
	       		{
		    	    moveRight();
			    updateDirectionRight();
	       		}
	  		else if(checkUp( '.' ))
	    	             {
		    	   	 moveUp();
				 updateDirectionUp();
	       	             }
		             else if(checkDown( 'x' ))
	      		    	  {
		   		     moveDown();
				     updateDirectionDown();
	       		           }
	    		    	  else if(checkRight( 'x' ))
	    	    		       {
	               		           moveRight();
					   updateDirectionRight();
	       	    		       }
				       else {  moveUp();  
					       updateDirectionUp(); }


		deadEnd();
		break;

		case 3:
		   if(checkLeft( '.' ))
	  		{
			moveLeft();
			updateDirectionLeft();
			  }
		   else if(checkDown( '.' ))
	       		{
		    	    moveDown();
			    updateDirectionDown();
	       		}
	  		else if(checkRight( '.' ))
	    	             {
		    	   	 moveRight();
				 updateDirectionRight();
	       	             }
		             else if(checkLeft( 'x' ))
	      		    	  {
		   		     moveLeft();
				     updateDirectionLeft();
	       		           }
	    		    	  else if(checkDown( 'x' ))
	    	    		       {
	               		           moveDown();
					   updateDirectionDown();
	       	    		       }
				       else {  moveRight();  
					       updateDirectionRight(); }
		
		deadEnd();
		break;


		case 4:
		   if(checkUp( '.' ))
	       		{
		    	    moveUp();
			    updateDirectionUp();
	       		}
	  		else if(checkLeft( '.' ))
	    	             {
		    	   	 moveLeft();
				 updateDirectionLeft();
	       	             }
			     else if(checkDown( '.' ))
	    	                  {
		    	   	     moveDown();
				     updateDirectionDown();
	       	                  }
	    		    	  else if(checkUp( 'x' ))
	    	                       {
	               	                   moveUp();
					   updateDirectionUp();
	       	    	               }
					else if(checkLeft( 'x' ))
	    	                       {
	               	                   moveLeft();
					   updateDirectionLeft();
	       	    	               }
				       else {  moveDown();  
					       updateDirectionDown(); }

		
		deadEnd();
		break;


		case 1:
		    if(checkRight( '.' ))
	       		{
		    	    moveRight();
			    updateDirectionRight();
	       		}
	  		else if(checkUp( '.' ))
	    	             {
		    	   	 moveUp();
				 updateDirectionUp();
	       	             }
			     else if(checkLeft( '.' ))
	    	                  {
		    	   	     moveLeft();
				     updateDirectionLeft();
	       	                  }
		             	  else if(checkRight( 'x' ))
	      		    	       {
		   		          moveRight();
				          updateDirectionRight();
	       		               }
	    		    	       else if(checkUp( 'x' ))
	    	    		            {
	               		               moveUp();
					       updateDirectionUp();
	       	    		            }
				       else {  moveLeft();   
					       updateDirectionLeft();}

		
		deadEnd();		
		break;


		case 5:
		    if(checkRight( 'x' ))
	       		{
		    	    moveRight();
			    updateDirectionRight();
	       		}
	  		else if(checkDown( 'x' ))
	    	             {
		    	   	 moveDown();
				 updateDirectionDown();	
	       	             }
			     else if(checkLeft( 'x' ))
	    	                  {
		    	   	     moveLeft();
				     updateDirectionLeft();
	       	                  }
				  else {  moveUp();   
					  updateDirectionUp();}

				
		break;
	}
} // end of function





//END OF IMPLENETATION FILE

		
	  			
	




		
