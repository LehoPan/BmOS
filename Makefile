output: main.o BmOS.o
	g++ main.o BmOS.o -o BmoOutput

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

BmOS.o: ./src/BmOS.cpp ./include/BmOS.h
	g++ -c ./src/BmOS.cpp

clean:
	rm *.o BmoOutput