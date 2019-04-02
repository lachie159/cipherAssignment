#include <stdio.h>
#include <stdlib.h>
void rotate(char *letter);
void rotate2(char *letter);

int main(){   
    char letter[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    
    rotate(letter);
    rotate2(letter);
    
    for (i = 0; i <= 26; i++)
        printf("%c ", letter[i]);
    
    return 0;
}
//--------------------------------------------------------------------------//
void rotate(char *letter){
    int n;
    static int c = 0;
    for(n = 0; n <= (25 - c); n++){
        letter[n] = letter[n + 1 + c];
    }
    c++;
}

void rotate2(char *letter){
    int n;
    int d = 0;
    static int c = 0;
    for(n = 26; n >= (26 - c); n--){
        letter[n] = letter['A' + c + d];
        d--;
    }
}