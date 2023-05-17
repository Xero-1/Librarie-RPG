CC = g++

IDIR = ./inc/
SRCDIR = ./src/

all: project run clean

project:
	$(CC) $(SRCDIR)*.cpp -I$(IDIR) -o $@
run:
	./project
clean:
	rm project
	clear
