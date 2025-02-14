# Compiler settings
CC = g++
CFLAGS = -Wall -std=c++14 -g

# Default target: compiles both versions
all: list_josephus vector_josephus

# Compile and link ListMyJosephus version
list_josephus: ListMyJosephus.o Destination.o TestListMyJosephus.o
	$(CC) $(CFLAGS) -o list_josephus ListMyJosephus.o Destination.o TestListMyJosephus.o

# Compile and link VectorMyJosephus version
vector_josephus: VectorMyJosephus.o Destination.o TestVectorMyJosephus.o
	$(CC) $(CFLAGS) -o vector_josephus VectorMyJosephus.o Destination.o TestVectorMyJosephus.o

# Compile ListMyJosephus source file
ListMyJosephus.o: ListMyJosephus.cpp ListMyJosephus.h
	$(CC) $(CFLAGS) -c ListMyJosephus.cpp

# Compile VectorMyJosephus source file
VectorMyJosephus.o: VectorMyJosephus.cpp VectorMyJosephus.h
	$(CC) $(CFLAGS) -c VectorMyJosephus.cpp

# Compile Destination source file
Destination.o: Destination.cpp Destination.h
	$(CC) $(CFLAGS) -c Destination.cpp

# Compile test file for ListMyJosephus
TestListMyJosephus.o: TestListMyJosephus.cpp
	$(CC) $(CFLAGS) -c TestListMyJosephus.cpp

# Compile test file for VectorMyJosephus
TestVectorMyJosephus.o: TestVectorMyJosephus.cpp
	$(CC) $(CFLAGS) -c TestVectorMyJosephus.cpp

# Clean compiled files
clean:
	rm -f *.o list_josephus vector_josephus
