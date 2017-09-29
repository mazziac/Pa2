#include <ctype.h>
#include <stdio.h>
//This program counts the consaantsion
int cons(const char* sentence){
    int cCount = 0;
    for(int i = 0; sentence[i]; i++){
        char c = tolower(sentence[i]);
        if((c >= 97 && c < 123) && 
		  !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')){
                 cCount++;
			}
    }   
return cCount;  

}

int main(int argc, const char* argv[]){
	const char* sentence = argv[1];
	return cons(sentence);	
}	

