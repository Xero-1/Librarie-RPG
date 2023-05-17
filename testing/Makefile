CC = g++

IDIR = ../inc/
SRCDIR = ../src/

all: project run clean

project:
	$(CC) -g $(SRCDIR)*.cpp -I$(IDIR) -o $@
run:
	valgrind --leak-check=yes ./project
clean:
	rm project
