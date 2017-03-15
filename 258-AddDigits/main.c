#include <stdio.h>


int addDigits(int num) {
    /*
    if(num < 10){
        return num;
    } else if(num <=18) {
        return num-9;
    } else{
        int re = (num-18)%9;
        return re == 0 ? 9:re;

    */
    int re = num%9;
    if(re == 0 && num != 0)
        return 9;
    return re;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}