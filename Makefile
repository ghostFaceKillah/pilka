runme: main.cpp state.cpp state.h
	g++ -o runme main.cpp state.cpp
clean:
	rm *.o *.state
