#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAINS 5
#define MAX_SEATS 50

// Structure to store train information
typedef struct {
    int trainNumber;
    char trainName[30];
    int availableSeats;
    int bookedSeats;
} Train;

// Array of trains
Train trains[MAX_TRAINS];

// Function to initialize train data
void initializeTrains() {
    trains[0] = (Train){101, "Express 101", MAX_SEATS, 0};
    trains[1] = (Train){102, "Shatabdi 102", MAX_SEATS, 0};
    trains[2] = (Train){103, "Rajdhani 103", MAX_SEATS, 0};
    trains[3] = (Train){104, "Superfast 104", MAX_SEATS, 0};
    trains[4] = (Train){105, "Vande Bharat 105", MAX_SEATS, 0};
}

// Function to display available trains
void displayTrains() {
    printf("\nAvailable Trains:\n");
    printf("Train No. | Train Name        | Available Seats\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("%8d | %-17s | %15d\n", trains[i].trainNumber, trains[i].trainName, trains[i].availableSeats - trains[i].bookedSeats);
    }
    printf("\n");
}

// Function to book a ticket
void bookTicket() {
    int trainNo, seatsToBook;

    printf("Enter train number: ");
    scanf("%d", &trainNo);

    int found = 0;
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].trainNumber == trainNo) {
            found = 1;
            printf("Train found: %s\n", trains[i].trainName);
            printf("Available seats: %d\n", trains[i].availableSeats - trains[i].bookedSeats);
            printf("Enter number of seats to book: ");
            scanf("%d", &seatsToBook);

            if (seatsToBook > (trains[i].availableSeats - trains[i].bookedSeats)) {
                printf("Not enough seats available!\n");
            } else {
                trains[i].bookedSeats += seatsToBook;
                printf("Booking successful! %d seats booked on %s.\n", seatsToBook, trains[i].trainName);
            }
            break;
        }
    }

    if (!found) {
        printf("Train number %d not found!\n", trainNo);
    }
}

// Function to cancel a booking
void cancelBooking() {
    int trainNo, seatsToCancel;

    printf("Enter train number: ");
    scanf("%d", &trainNo);

    int found = 0;
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].trainNumber == trainNo) {
            found = 1;
            printf("Train found: %s\n", trains[i].trainName);
            printf("Booked seats: %d\n", trains[i].bookedSeats);
            printf("Enter number of seats to cancel: ");
            scanf("%d", &seatsToCancel);

            if (seatsToCancel > trains[i].bookedSeats) {
                printf("Cannot cancel more seats than booked!\n");
            } else {
                trains[i].bookedSeats -= seatsToCancel;
                printf("Cancellation successful! %d seats canceled on %s.\n", seatsToCancel, trains[i].trainName);
            }
            break;
        }
    }

    if (!found) {
        printf("Train number %d not found!\n", trainNo);
    }
}

int main() {
    int choice;

    // Initialize train data
    initializeTrains();

    while (1) {
        // Menu
        printf("\nRailway Reservation System\n");
        printf("1. View Available Trains\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}