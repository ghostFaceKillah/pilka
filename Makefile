runme: main.cpp GameState.cpp GameState.h Player.h Player.cpp
	g++ -o runme main.cpp GameState.cpp Player.cpp
	./runme
clean:
	rm *.o *.GameState
