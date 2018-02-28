

 
CUSTOMSRC = $(wildcard customlibs/*.c)
CUSTOMOBJ = $(patsubst %c,%o,$(CUSTOMSRC))
CC = gcc -Wall -Wextra -ansi -std=c99 -lm

EXO = exo1 exo2 exo3

all: $(EXO)


$(EXO) : % : %.o $(CUSTOMOBJ)
	$(CC) -o $@ $^

.PHONY:clean
clean:
	rm -f *.o
	rm -f customlibs/*.o
	rm -f $(EXO)


