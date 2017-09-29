
//This progam counts the number of vowels
#include <ctype.h>
#include <stdio.h>

int vowel(const char* sentence){
    int vCount = 0;
    for(int i = 0; sentence[i] != '\0'; i++){
        char c = tolower(sentence[i]);
		//printf("%c \n", c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vCount++;
		//printf("%d \n", vCount);
    }   
	return vCount;  
}  
  
//This program counts the consaantsion
int main(int argc, const char* argv[]){
    //make this a function
    const char* sentence = argv[1];
	int vowelCount = vowel(sentence);
	//printf("vowels: %d \n", vowelCount); 
	return vowelCount;  
}   

