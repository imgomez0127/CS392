cs392_shell : cs392_exec.o cs392_log.o
	gcc -o cs392_shell cs392_shell.c cs392_exec.o cs392_log.o
cs392_exec.o:cs392_exec.c
	gcc -c cs392_exec.c
cs392_log.o:cs392_log.c
	gcc -c cs392_log.c	
clean:
	rm *.o cs392_shell
