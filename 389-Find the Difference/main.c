#include <stdio.h>
//#include <tkDecls.h>
#include <stdlib.h>
#include <string.h>


char findTheDifference(char* s, char* t) {
    char p = 0;
    int lens = (int)strlen(s);
    while(lens > 0) {
        p ^= *s;
        p ^= *t;
        s ++;
        t ++;
        lens --;
    }
    p ^= *t;
    return p;
}

int main() {

    char a[] = "abcd";
    char a2[] = "abcde";

    char s = findTheDifference(a,a2);
    printf("%c \n", s);


    return 0;
}