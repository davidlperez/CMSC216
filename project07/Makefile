#
# Macro definitions
#
CC = gcc
CFLAGS = -g -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

#
# all makefile creates all 3 top-level programs
#
all: public01.x public02.x public03.x public04.x public05.x public06.x \
	public07.x public08.x public09.x public10.x

#
# make commands for object and executable files
#
string-graph.o: string-graph.c string-graph.h string-graph-datastructure.h
	$(CC) $(CFLAGS) -c string-graph.c

public01.x: string-graph.o public01.o
	$(CC) public01.o string-graph.o -o public01.x

public01.o: public01.c string-graph.h
	$(CC) $(CFLAGS) -c public01.c

public02.x: string-graph.o public02.o
	$(CC) public02.o string-graph.o -o public02.x

public02.o: public02.c string-graph.h
	$(CC) $(CFLAGS) -c public02.c

public03.x: string-graph.o public03.o
	$(CC) public03.o string-graph.o -o public03.x

public03.o: public03.c string-graph.h
	$(CC) $(CFLAGS) -c public03.c

public04.x: string-graph.o public04.o compare-vertex-lists.o
	$(CC) public04.o string-graph.o compare-vertex-lists.o -o public04.x

public04.o: public04.c string-graph.h compare-vertex-lists.h
	$(CC) $(CFLAGS) -c public04.c

public05.x: string-graph.o public05.o
	$(CC) public05.o string-graph.o -o public05.x

public05.o: public05.c string-graph.h
	$(CC) $(CFLAGS) -c public05.c

public06.x: string-graph.o public06.o
	$(CC) public06.o string-graph.o -o public06.x

public06.o: public06.c string-graph.h
	$(CC) $(CFLAGS) -c public06.c

public07.x: string-graph.o public07.o
	$(CC) public07.o string-graph.o -o public07.x

public07.o: public07.c string-graph.h
	$(CC) $(CFLAGS) -c public07.c

public08.x: string-graph.o public08.o
	$(CC) public08.o string-graph.o -o public08.x

public08.o: public08.c string-graph.h
	$(CC) $(CFLAGS) -c public08.c

public09.x: string-graph.o public09.o
	$(CC) public09.o string-graph.o -o public09.x

public09.o: public09.c string-graph.h
	$(CC) $(CFLAGS) -c public09.c

public10.x: string-graph.o public10.o
	$(CC) public10.o string-graph.o -o public10.x

public10.o: public10.c string-graph.h
	$(CC) $(CFLAGS) -c public10.c

#
# clean command invoked by calling "make clean" removes all object and 
# executable files except for 'compare-vertex-lists.o'
#
clean:
	- rm *.x string-graph.o public01.o public02.o public03.o public04.o \
		public05.o public06.o public07.o public08.o public09.o public10.o