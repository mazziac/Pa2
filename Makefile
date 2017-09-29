CC=gcc -Wall -Wfatal-errors
all: Vowels Consonants Other Initiator
Vowels: Vowels.c
	$(CC) -o Vowels Vowels.c

Consonants: Consonants.c
	$(CC) -o Consonants Consonants.c

Other: Other.c
	$(CC) -o Other Other.c

Initiator: Initiator.c
	$(CC) -o Initiator Initiator.c

clean:
	rm -f *.o Vowels Consonants Other Initiator
