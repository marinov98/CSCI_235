CXXFLAGS=-std=c++14
main: main.o PlayList.o Song.o #Node.o
	g++ -o main main.o PlayList.o Song.o #Node.o

main.o: main.cpp PlayList.h Song.h
	g++ $(CXXFLAGS) -c main.cpp

PlayList.o: PlayList.cpp PlayList.h
	g++ $(CXXFLAGS) -c PlayList.cpp

Song.o:Song.cpp Song.h
	g++ $(CXXFLAGS) -c Song.cpp

#Node.o: Node.cpp Node.h
	#g++ $(CXXFLAGS) -c Node.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g

debug: main

clean:
	rm -f main.o PlayList.o Song.o Node.o main

run:
	./main