CC = g++
SRC = main.cpp system.cpp box.cpp
EXEC = myviscek

$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC)
