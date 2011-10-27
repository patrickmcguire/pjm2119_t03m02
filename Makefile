CC = g++

UNI = pjm2119
Theme = 03
Milestone = 02

SRC = main.cpp
TARGET = main_t$(Theme)m$(Milestone)

OBJS = main.o
HEADERS = halfedge.h

INCDIRS = -I/usr/include -I/usr/local/include
LIBDIRS = -L/usr/lib -L/usr/local/lib -L/opt/local/lib
CFLAGS = -Wall -g $(INCLUDE)
LDFLAGS = -lglut -lGL -lGLU -lm

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
INCDIRS := $(INCDIRS) -I/opt/local/include
LIBDIRS = $(LIBDIRS) -L/opt/local/lib/boost
LDFLAGS = -framework GLUT -framework OpenGL                                                                                                                                    
CFLAGS = -Wall -g $(INCDIRS) $(LIBDIR) -framework GLUT -framework OpenGL $(LDFLAGS)
endif

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LFLAGS)
main.o: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRC) $(HEADERS)

clean:
	rm -f $(TARGET) $(TARGET_CREATIVE) $(OBJS) *.gch
