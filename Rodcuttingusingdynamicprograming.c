#include <stdio.h>
#include <limits.h>
// Function to find maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}
// Rod Cutting function
int rodCutting(int prices[], int n) {
int dp[n + 1];
dp[0] = 0;
for (int i = 1; i <= n; i++) {
int max_val = INT_MIN;
for (int j = 1; j <= i; j++) {
max_val = max(max_val, prices[j - 1] + dp[i - j]);
}
dp[i] = max_val;
}
return dp[n];
}
int main() {
int n;
printf("Enter length of rod: ");
scanf("%d", &n);
int prices[n];
printf("Enter prices for pieces (1 to %d units):\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &prices[i]);
}
int max_profit = rodCutting(prices, n);
printf("Maximum obtainable value = %d\n", max_profit);
return 0;
}
