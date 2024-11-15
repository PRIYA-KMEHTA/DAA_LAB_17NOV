/* Greedy Approach
Sort the activities by their finish times in ascending order.
Select the first activity (earliest finishing time).
For subsequent activities, select an activity only if its start time is greater than or equal to the finish time of the previously selected activity.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

void activitySelection(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities (start, finish):\n");

    int lastFinishTime = activities[0].finish;
    printf("(%d, %d)\n", activities[0].start, activities[0].finish);

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish;
        }
    }
}

int main() {
    Activity activities[] = {
        {1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 9}, {8, 10}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
