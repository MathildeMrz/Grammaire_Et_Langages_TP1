main : test.o main.o lexer.o  automate.o symbole.o state.o
	g++ -o automate test.o main.o state.o lexer.o automate.o symbole.o 

test.o: test.cpp
	g++ -c test.cpp

main.o: main.cpp
	g++ -c main.cpp

automate.o: automate.cpp
	g++ -c automate.cpp

state.o: state.cpp
	g++ -c state.cpp

lexer.o: lexer.cpp
	g++ -c lexer.cpp

symbole.o: symbole.cpp
	g++ -c symbole.cpp