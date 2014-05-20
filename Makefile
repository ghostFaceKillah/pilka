runme: main.cpp GameState.cpp GameState.h
	g++ -o runme main.cpp GameState.cpp
	./runme
clean:
	rm *.o *.GameState
