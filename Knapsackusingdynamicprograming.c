
#include <stdio.h>
#include <stdlib.h>
// Utility function to find the maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}
// 0/1 Knapsack function
int knapsack(int capacity, int weights[], int values[], int n) {
int dp[n + 1][capacity + 1];
// Build DP table
for (int i = 0; i <= n; i++) {
for (int w = 0; w <= capacity; w++) {
if (i == 0 || w == 0)
dp[i][w] = 0;
else if (weights[i - 1] <= w)
dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
else
dp[i][w] = dp[i - 1][w];
}
}
return dp[n][capacity];
}
int main() {
int n, capacity;
printf("Enter number of items: ");
scanf("%d", &n);
int values[n], weights[n];
printf("Enter values of items:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &values[i]);
}
printf("Enter weights of items:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &weights[i]);
}
printf("Enter knapsack capacity: ");
scanf("%d", &capacity);
int max_value = knapsack(capacity, weights, values, n);
printf("Maximum value in Knapsack = %d\n", max_value);
return 0;
}
