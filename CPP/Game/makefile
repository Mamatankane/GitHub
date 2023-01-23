mainP2: Object.o Floor.o Player.o Wall.o ObjectList.o  Map.o Game.o mainP2.o MessageQueue.o Door.o Lamp.o Exit.o Message.o
	g++ -g -static Object.o Floor.o MessageQueue.o Door.o Lamp.o Exit.o Player.o Wall.o Message.o ObjectList.o Map.o Game.o mainP2.o -o mainP2
ObjectList.o: ObjectList.cpp ObjectList.h
	g++ -g -c ObjectList.cpp
mainP2.o: mainP2.cpp 
	g++ -g -c mainP2.cpp

Door.o: Door.cpp Door.h
	g++ -g -c Door.cpp

Lamp.o: Lamp.cpp Lamp.h
	g++ -g -c Lamp.cpp

Exit.o: Exit.cpp Exit.h
	g++ -g -c Exit.cpp

Message.o: Message.cpp Message.h
	g++ -g -c Message.cpp

Floor.o: Floor.cpp Floor.h
	g++ -g -c Floor.cpp

Player.o: Player.cpp Player.h
	g++ -g -c Player.cpp

Wall.o: Wall.cpp Wall.h
	g++ -g -c Wall.cpp


Object.o: Object.cpp Object.h
	g++ -g -c Object.cpp

Map.o: Map.cpp Map.h
	g++ -g -c Map.cpp 

Game.o: Game.cpp Game.h
	g++ -g -c Game.cpp

MessageQueue.o: MessageQueue.cpp MessageQueue.h
	g++ -g -c MessageQueue.cpp

run:
	./mainP2

clean: 
	rm *.o mainP2
	
