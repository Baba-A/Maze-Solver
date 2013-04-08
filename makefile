
#ABUBAKAR BABA AWUMBILA
#IMPLEMENTATION OF THE 'RIGHT-HAND RULE' MAZE SOLVING ALGORITHM
#MAKEFILE TO COMPILE AND BUILD EXECUTABLE PROGRAM

maze : maze.o mazeApp.cpp
	g++ -o  maze maze.o mazeApp.cpp

maze.o : maze.cpp maze.h
	g++ -c maze.cpp
  


clean: 
	rm *.o maze


#END OF MAKEFILE



