CC = g++

UNI = pjm2119
Theme = 03
Milestone = 02

SRC = main.cpp
TARGET = main_t$(Theme)m$(Milestone)

OBJS = main.o
INCLUDE = NormalVector.h Coordinate.h

INCDIRS = -I/usr/include -I/usr/local/include
LIBDIRS = -L/usr/lib -L/usr/local/lib

CFLAGS = -g $(INCDIRS)
LFLAGS = -lglut -lGL -lGLU -lm

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LFLAGS)
main.o: $(SRC) $(INCLUDE)
	$(CC) -c $(SRC) $(INCLUDE)

clean:
	rm -f $(TARGET) $(TARGET_CREATIVE) $(OBJS)