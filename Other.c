//This program counts everything else (white space, punc, digits)
#include <ctype.h>
#include <stdio.h>
int other(const char* sentence){
    int oCount = 0;
    for(int i = 0; sentence[i]; i++){
        char c = sentence[i];
        if(!((c >= 65 && c < 91) || (c >= 97 && c < 123) || c == '\n'))    
            oCount++;                                                           
    }   
    return oCount;
}

int main(int argc, const char* argv[]){
     //make this a function
     const char* sentence = argv[1];
     return other(sentence);
}

