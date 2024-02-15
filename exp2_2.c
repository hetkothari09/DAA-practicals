#include <stdio.h>
#include <stdlib.h>

// Function to compare fruits based on their value per unit weight
int compare(const void *a, const void *b) {
    double *fruit1 = (double *)a;
    double *fruit2 = (double *)b;
    double ratio1 = fruit1[1] / fruit1[0];
    double ratio2 = fruit2[1] / fruit2[0];
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Function to calculate the maximum total nutritional value
double fractionalKnapsack(double fruits[][2], int n, double capacity) {
    // Sort fruits based on their value-to-weight ratio
    qsort(fruits, n, sizeof(fruits[0]), compare);

    double totalValue = 0.0; // Initialize total value in the knapsack

    // Fill the knapsack with fractional parts of fruits
    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            break;
        if (fruits[i][0] <= capacity) {
            // Take the whole fruit
            totalValue += fruits[i][1];
            capacity -= fruits[i][0];
        } else {
            // Take a fractional part of the fruit
            totalValue += (fruits[i][1] / fruits[i][0]) * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int n;
    double capacity;

    printf("Enter the number of fruits: ");
    scanf("%d", &n);

    double fruits[n][2];

    // Input each fruit's weight and nutritional value
    for (int i = 0; i < n; i++) {
        printf("Enter weight of fruit %d: ", i + 1);
        scanf("%lf", &fruits[i][0]);
        printf("Enter nutritional value of fruit %d: ", i + 1);
        scanf("%lf", &fruits[i][1]);
    }

    printf("Enter the capacity of the backpack: ");
    scanf("%lf", &capacity);

    double maxValue = fractionalKnapsack(fruits, n, capacity);
    printf("Maximum total nutritional value: %.2lf\n", maxValue);

    return 0;
}
