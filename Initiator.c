
//this class read text from textfile.txt, save it in a string, and the sends it to the child processes for further processing. Responsible for fork,exec and wait.
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

//This function does the real work
int forktoChild(const char* prg, const char* sentence){
    pid_t child;
    int value = 0;
        
    child = fork();
        
    if(child < 0){ //Error
        printf("ForkFailed");
        exit(127);
    }   
    else if (child == 0){ //child
        printf("Initiator: forked process with ID %d.\n",getpid()); 
        execlp(prg,prg, sentence,(char* ) NULL);
        //printf("vowels: %d", vowels);
        return EXIT_FAILURE;   
    }   
    else { //Parent
        int waitstatus;
        waitpid(child, &waitstatus,0);
        //In parent
        printf("Initiator: waiting for process [%d].\n",child); 
        wait(&waitstatus); //Wait
        value = WEXITSTATUS(waitstatus);   
        printf("Initiator: child process %d returned %d.\n",child,value);
    }   
return value;	
}

int main(int argc, const char* argv[]){
	char* sentence = NULL;					//Get the sentence
	FILE* fp; 
	fp = fopen("textfile.txt", "r");		//Open file
	
	//Change this to go through each line in the file//////
	size_t len = 0;
	ssize_t read;
	
	int vowels,cons,other;
	vowels = cons = other = 0;
	while((read = getline(&sentence,&len,fp)) != -1){
	//printf("%s", sentence);
	//send sentence to childs
		vowels = forktoChild("Vowels", sentence);
		cons = forktoChild("Consonants", sentence);
		other = forktoChild("Other", sentence);
	}

	fclose(fp);
	free(sentence);
	printf("The number of vowels is %d\n",vowels);
	printf("The number of consonants is %d\n",cons);
	printf("The number of other characters is  %d\n",other);

	exit(EXIT_SUCCESS);
}
