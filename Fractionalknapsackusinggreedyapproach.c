
#include <stdio.h>
#include <stdlib.h>
// Structure for items
struct Item {
int value;
int weight;
};
// Comparison function for sorting
int compare(const void *a, const void *b) {
struct Item *item1 = (struct Item *)a;
struct Item *item2 = (struct Item *)b;
double ratio1 = (double)item1->value / item1->weight;
double ratio2 = (double)item2->value / item2->weight;
return (ratio2 > ratio1) ? 1 : -1;
}
// Fractional Knapsack function
double fractionalKnapsack(int capacity, struct Item items[], int n) {
// Sort items by value/weight ratio (descending)
qsort(items, n, sizeof(items[0]), compare);
double total_value = 0.0;
int current_weight = 0;
for (int i = 0; i < n; i++) {
if (current_weight + items[i].weight <= capacity) {
// Take whole item
current_weight += items[i].weight;
total_value += items[i].value;
} else {
// Take fraction of item
int remaining = capacity - current_weight;
total_value += items[i].value * ((double)remaining / items[i].weight);
break;
}
}
return total_value;
}
int main() {
int n, capacity;
printf("Enter number of items: ");
scanf("%d", &n);
struct Item items[n];
printf("Enter values and weights of items (value weight):\n");
for (int i = 0; i < n; i++) {
scanf("%d %d", &items[i].value, &items[i].weight);
}
printf("Enter knapsack capacity: ");
scanf("%d", &capacity);
double max_value = fractionalKnapsack(capacity, items, n);
printf("Maximum value in Knapsack = %.2f\n", max_value);
return 0;
}
