

first: passgen passread
	

passgen: Make_New.c
	gcc Make_New.c -o ~/bin/passgen-c

passread: Read.c
	gcc Read.c -o ~/bin/passread-c
