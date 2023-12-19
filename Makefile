PROG = main.exe 
SRC = main.cpp src/AppManager.cpp src/Card.cpp src/Collection.cpp src/DisplayManager.cpp src/InputManager.cpp
CC=g++
CFLAGS = -g
LIBS = 

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean