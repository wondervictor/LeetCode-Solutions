#include <stdio.h>
#include <tkDecls.h>


int countSegments(char* s) {
    int flag = 0;
    int num = 0;
    while(1) {
        if(*s == ' ') {
            if(flag)
                num ++;
            flag = 0;
        }
        else {
            flag = 1;
        }
        s++;
        if(s == '\0') {
            num = flag ? num + 1:num;
            break;
        }
    }
    return num;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}