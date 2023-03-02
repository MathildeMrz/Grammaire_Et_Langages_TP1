main : main.o lexer.o  automate.o symbole.o state.o
	g++ -o automate main.o state.o lexer.o automate.o symbole.o 

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