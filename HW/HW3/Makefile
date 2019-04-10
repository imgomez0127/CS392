#"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
cs392_shell : cs392_exec.o cs392_log.o cs392_signal.o
	gcc -o cs392_shell cs392_shell.c cs392_exec.o cs392_log.o cs392_signal.o
cs392_exec.o:cs392_exec.c
	gcc -c cs392_exec.c
cs392_log.o:cs392_log.c
	gcc -c cs392_log.c	
cs392_signal.o:cs392_signal.c
	gcc -c cs392_signal.c	
clean:
	rm *.o cs392_shell
