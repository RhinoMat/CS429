CC = gcc
DEFINES = -lm -lX11 
DEBUG = -g
CFLAGS = $(DEFINES) $(DEBUG) -Wall
PROG1 = sierpinski_triangle_ryan_matthews
PROG2 = pythagoras_tree_ryan_matthews
PROG3 = koch_curve_ryan_matthews
PROG4 = color_blend
PROGS = $(PROG1) $(PROG2) $(PROG3) $(PROG4)
all: $(PROGS)

$(PROG1): $(PROG1).o
	$(CC) $(CFLAGS) -o $(PROG1) $(PROG1).o

$(PROG1).o: $(PROG1).c
	$(CC) $(CFLAGS) -c $(PROG1).c

$(PROG2): $(PROG2).o
	$(CC) $(CFLAGS) -o $(PROG2) $(PROG2).o
 
$(PROG2).o: $(PROG2).c
	$(CC) $(CFLAGS) -c $(PROG2).c

$(PROG3): $(PROG3).o
	$(CC) $(CFLAGS) -o $(PROG3) $(PROG3).o
 
$(PROG3).o: $(PROG3).c
	$(CC) $(CFLAGS) -c $(PROG3).c

$(PROG4): $(PROG4).o
	$(CC) $(CFLAGS) -o $(PROG4) $(PROG4).o
 
$(PROG4).o: $(PROG4).c
	$(CC) $(CFLAGS) -c $(PROG4).c

clean cls:
	rm -f *.o $(PROGS) *.bmp *~ \#*

