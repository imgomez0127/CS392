#"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
TARGET = libcs392string.so
CC = gcc
OBJS = cs392_strlen.o cs392_memcpy.o
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -O0 -shared -o $(TARGET)
cs392_memcpy.o : cs392_memcpy.c
	gcc -c cs392_memcpy.c
cs392_strlen.o : cs392_strlen.c
	gcc -c cs392_strlen.c
clean :
	rm *.so *.o

