#include <stdio.h>
#define MAX 100

struct Package {
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};

struct Package p[MAX];
int n = 0;
float capacity = 0;
int detailsEntered = 0;
int solutionFound = 0;

void enterDetails() {
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of packages!\n");
        n = 0;
        detailsEntered = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].fraction = 0;

        printf("\nEnter value of package %d: ", i + 1);
        scanf("%f", &p[i].value);

        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &p[i].weight);

        if (p[i].value < 0 || p[i].weight <= 0) {
            printf("Invalid value or weight! Enter details again.\n");
            i--;
            continue;
        }

        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nEnter vehicle carrying capacity: ");
    scanf("%f", &capacity);

    if (capacity < 0) {
        printf("Invalid capacity!\n");
        n = 0;
        detailsEntered = 0;
        return;
    }

    detailsEntered = 1;
    solutionFound = 0;

    printf("\nPackage details entered successfully!\n");
}

void displayDetails() {
    int i;

    if (!detailsEntered) {
        printf("\nPlease enter package details first.\n");
        return;
    }

    printf("\nPackage Details:\n");
    printf("ID\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value,
               p[i].weight, p[i].ratio);
    }

    printf("\nVehicle Capacity: %.2f\n", capacity);
}

// Function to calculate value/weight ratio
void calculateRatio() {
    int i;

    if (!detailsEntered) {
        printf("\nPlease enter package details first.\n");
        return;
    }

    printf("\nValue/Weight Ratios:\n");

    for (i = 0; i < n; i++) {
        p[i].ratio = p[i].value / p[i].weight;
        printf("Package %d: %.2f\n", p[i].id, p[i].ratio);
    }
}

void sortPackages() {
    int i, j;
    struct Package temp;

    if (!detailsEntered) {
        printf("\nPlease enter package details first.\n");
        return;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    solutionFound = 0;

    printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
}

void findMaximumValue() {
    int i;
    float remaining, totalValue = 0;

    if (!detailsEntered) {
        printf("\nPlease enter package details first.\n");
        return;
    }
    remaining = capacity;
    for (i = 0; i < n; i++) {
        p[i].fraction = 0;
    }

    for (i = 0; i < n; i++) {
        if (remaining <= 0)
            break;

        if (p[i].weight <= remaining) {
            p[i].fraction = 1.0;
            remaining -= p[i].weight;
            totalValue += p[i].value;
        } else {
            p[i].fraction = remaining / p[i].weight;
            totalValue += p[i].value * p[i].fraction;
            remaining = 0;
        }
    }

    solutionFound = 1;

    printf("\nMaximum value obtained: %.2f\n", totalValue);
    printf("Total weight used: %.2f\n", capacity - remaining);
}

void displaySelectedPackages() {
    int i;

    if (!detailsEntered || !solutionFound) {
        printf("\nPlease find the maximum value first.\n");
        return;
    }
    printf("\nSelected Packages:\n");
    printf("ID\tValue\tWeight\tFraction\tSelected Value\n");
    for (i = 0; i < n; i++) {
        if (p[i].fraction > 0) {
            printf("%d\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
                   p[i].id,
                   p[i].value,
                   p[i].weight,
                   p[i].fraction,
                   p[i].value * p[i].fraction);
        }
    }
}

int main() {
    int choice;

    while(choice!=7) {
        printf("\n===== SMART DELIVERY PLANNING =====\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterDetails();
                break;
			case 2:
                displayDetails();
                break;

  			   case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                sortPackages();
                findMaximumValue();
                break;

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("\nExiting program. Thank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } 
    return 0;
}
