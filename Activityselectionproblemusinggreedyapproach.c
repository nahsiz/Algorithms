#include <stdio.h>
#include <stdlib.h>
// Activity structure
struct Activity {
int start;
int finish;
int index;  // Original index
};
// Comparison function for sorting
int compare(const void *a, const void *b) {
return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}
// Activity Selection function
void activitySelection(struct Activity activities[], int n) {
// Sort activities by finish time
qsort(activities, n, sizeof(activities[0]), compare);
printf("Selected Activities (0-based index):\n");
printf("%d ", activities[0].index);  // First activity always selected
int last_finish = activities[0].finish;
for (int i = 1; i < n; i++) {
if (activities[i].start >= last_finish) {
printf("%d ", activities[i].index);
last_finish = activities[i].finish;
}
}
}
int main() {
int n;
printf("Enter number of activities: ");
scanf("%d", &n);
struct Activity activities[n];
printf("Enter start and finish times (start finish):\n");
for (int i = 0; i < n; i++) {
scanf("%d %d", &activities[i].start, &activities[i].finish);
activities[i].index = i;  // Store original index
}
activitySelection(activities, n);
return 0;
}
