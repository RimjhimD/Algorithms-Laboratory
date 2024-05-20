
#include <stdio.h>
#include <stdlib.h>

struct Object {
    double profit;
    double weight;
    double ratio;
};

// Structure to represent an object

int compare(const void *a, const void *b) {
    double ratio_a = ((struct Object *)a)->ratio;
    double ratio_b = ((struct Object *)b)->ratio;
    if (ratio_a < ratio_b)
        return 1;
    else if (ratio_a > ratio_b)
        return -1;
    else
        return 0;
}

double fractionalKnapsack(double profit[], double weights[], double capacity, int n) {
    struct Object objects[n];

    // Initialize the objects with profit, weight, and their ratio
    for (int i = 0; i < n; ++i) {
        objects[i].profit = profit[i];
        objects[i].weight = weights[i];
        objects[i].ratio = (double)profit[i] / weights[i];
    }
    //compare based on ratio
    qsort(objects, n, sizeof(objects[0]), compare);

    double maxProfit = 0.0;

    for (int i = 0; i < n; ++i) {
        if (capacity > 0 && objects[i].weight <= capacity) {
            maxProfit += objects[i].profit;
            capacity -= objects[i].weight;
        } else {
            // Calculate profit fractionally for the remaining capacity
            maxProfit += (capacity * objects[i].ratio);
            break;
        }
    }

    return maxProfit;
}


int main() {
    int n;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    double profit[n];
    double weights[n];
    double capacity;

    // Input profit and weight of each item
    printf("Enter the profits and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit and weight of item %d: ", i + 1);
        scanf("%lf %lf", &profit[i], &weights[i]);
    }

    // Input capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    // Calculate maximum value using fractional knapsack algorithm
    printf("Maximum value: %.2f\n", fractionalKnapsack(profit, weights, capacity, n));

    return 0;
}
