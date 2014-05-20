runme: main.cpp state.cpp state.h
	g++ -o runme main.cpp state.cpp
	./runme
clean:
	rm *.o *.state
