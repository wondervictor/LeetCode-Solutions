#include <stdio.h>



int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int one = 1;
    int two = 2;
    for(int i = 3; i <= n; i ++) {
        int tmp = two;
        two = one + two;
        one = tmp;
    }
    return two;
    /*
    int a[n+1];
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i <= n; i ++)
        a[i] = a[i-1]+a[i-2];
    return a[n];
    */
}

/*
int climbStairs(int n) {
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    return climbStairs(n-1) + climbStairs(n-2);
}
*/




int main() {
    printf("Hello, World!\n");
    return 0;
}