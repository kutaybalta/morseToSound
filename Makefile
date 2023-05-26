morse : morse.c
	gcc -o morse morse.c

clean : 
	rm morse
	clear

check :
	which aplay