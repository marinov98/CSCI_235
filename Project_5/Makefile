    CXXFLAGS=-std=c++14
    main: main.o SortingTests.o
		g++ -o main $(CXXFLAGS) main.o SortingTests.o

    main.o: main.cpp SortingTests.hpp
		g++ $(CXXFLAGS) -c main.cpp

    SortingTests.o: SortingTests.cpp SortingTests.hpp
		g++ $(CXXFLAGS) -c SortingTests.cpp

    clean: 
		rm -f main.o SortingTests.o main

    debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

    debug: main

    run:
	./main
