CXXFLAGS=-std=c++14
main: main.o PlayList.o Song.o #Node.o
	g++ $(CXXFLAGS) -o main main.o PlayList.o Song.o

main.o: main.cpp PlayList.h Song.h
	g++ $(CXXFLAGS) -c main.cpp

PlayList.o: PlayList.cpp PlayList.h
	g++ $(CXXFLAGS) -c PlayList.cpp

Song.o:Song.cpp Song.h
	g++ $(CXXFLAGS) -c Song.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

debug: main

clean:
	rm -f main.o PlayList.o Song.o Node.o main

run:
	UBSAN_OPTIONS="print_stacktrace=1" ./main