#include <stdio.h>


int uniquePaths(int m, int n) {
    if(n == 0 || m == 0)
        return 1;
    int path[n];
    for(int i = 0; i < n; i ++)
        path[i] = 1;
    for(int i = 1; i < m; i ++) {
        path[0] = 1;
        for(int j = 1; j < n; j ++)
            path[j] = path[j-1]+path[j];
    }
    return path[n-1];
}



int main() {



    printf("Hello, World!\n");
    return 0;
}