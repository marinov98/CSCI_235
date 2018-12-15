CXXFLAGS=-std=c++14

    main: main.o ladders.o
		g++ -o main $(CXXFLAGS) main.o ladders.o

    main.o: main.cpp ladders.hpp
		g++ $(CXXFLAGS) -c main.cpp

    ladders.o: ladders.cpp ladders.hpp
		g++ $(CXXFLAGS) -c ladders.cpp

    clean: 
		rm -f main.o ladders.o main

    debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

    debug: main

    run:
	./main
