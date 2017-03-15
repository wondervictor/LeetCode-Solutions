#include <stdio.h>

/**
 Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

 * */

int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 0)
        return 0;
    int min = prices[0];
    int max = 0;

    for(int i = 1; i < pricesSize; i ++){
        int newMax = prices[i]-min;
        max = max>newMax ? max:newMax;
        min = min<prices[i]?min:prices[i];
    }
    return max;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}