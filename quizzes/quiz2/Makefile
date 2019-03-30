#"I pledge my honor that I have abided by the Stevens honor system" -igomez1 Ian Gomez
C = gcc
OBJS = main.o sum.o
HEADERS = sum.h
prog : main.o sum.o
	$(C) -O0 -o prog $(OBJS)
$(OBJS) : $(HEADERS)

clean:
	rm $(OBJS) prog
