#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold destination details
struct Destination {
    char name[100];
    char location[100];
    char startDate[20];
    char endDate[20];
    float cost;
};

// Function to add a destination to the trip
void addDestination(struct Destination *trip, int *count) {
    printf("\nEnter the name of the destination: ");
    fgets(trip[*count].name, sizeof(trip[*count].name), stdin);
    trip[*count].name[strcspn(trip[*count].name, "\n")] = '\0';  // Remove newline

    printf("Enter the location of the destination: ");
    fgets(trip[*count].location, sizeof(trip[*count].location), stdin);
    trip[*count].location[strcspn(trip[*count].location, "\n")] = '\0';  // Remove newline

    printf("Enter the start date (DD/MM/YYYY): ");
    fgets(trip[*count].startDate, sizeof(trip[*count].startDate), stdin);
    trip[*count].startDate[strcspn(trip[*count].startDate, "\n")] = '\0';  // Remove newline

    printf("Enter the end date (DD/MM/YYYY): ");
    fgets(trip[*count].endDate, sizeof(trip[*count].endDate), stdin);
    trip[*count].endDate[strcspn(trip[*count].endDate, "\n")] = '\0';  // Remove newline

    printf("Enter the cost of the destination: ");
    scanf("%f", &trip[*count].cost);
    getchar();  // To consume the trailing newline character after scanf

    (*count)++;
    printf("Destination added successfully!\n");
}

// Function to display all destinations
void viewDestinations(struct Destination *trip, int count) {
    if (count == 0) {
        printf("\nNo destinations added yet.\n");
        return;
    }

    printf("\nDestinations in your travel plan:\n");
    for (int i = 0; i < count; i++) {
        printf("\nDestination %d:\n", i + 1);
        printf("Name: %s\n", trip[i].name);
        printf("Location: %s\n", trip[i].location);
        printf("Start Date: %s\n", trip[i].startDate);
        printf("End Date: %s\n", trip[i].endDate);
        printf("Cost: %.2f\n", trip[i].cost);
    }
}

// Function to remove a destination
void removeDestination(struct Destination *trip, int *count) {
    int index;
    if (*count == 0) {
        printf("\nNo destinations to remove.\n");
        return;
    }

    printf("\nEnter the index of the destination to remove (1 to %d): ", *count);
    scanf("%d", &index);
    getchar();  // To consume the trailing newline character after scanf

    if (index < 1 || index > *count) {
        printf("\nInvalid index. Please try again.\n");
        return;
    }

    // Shift all elements after the removed destination
    for (int i = index - 1; i < *count - 1; i++) {
        trip[i] = trip[i + 1];
    }

    (*count)--;
    printf("Destination removed successfully!\n");
}

// Function to calculate and display the total cost
void totalCost(struct Destination *trip, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += trip[i].cost;
    }
    printf("\nTotal cost of the trip: %.2f\n", total);
}

int main() {
    struct Destination trip[10];  // Array to hold up to 10 destinations
    int destinationCount = 0;
    int choice;

    while (1) {
        printf("\nTravel Planner Menu:\n");
        printf("1. Add Destination\n");
        printf("2. View Destinations\n");
        printf("3. Remove Destination\n");
        printf("4. Total Trip Cost\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after scanf

        switch (choice) {
            case 1:
                addDestination(trip, &destinationCount);
                break;
            case 2:
                viewDestinations(trip, destinationCount);
                break;
            case 3:
                removeDestination(trip, &destinationCount);
                break;
            case 4:
                totalCost(trip, destinationCount);
                break;
            case 5:
                printf("Exiting Travel Planner. Have a great trip!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
