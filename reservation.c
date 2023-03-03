#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50    // maximum number of available seats
#define MAX_NAME_LEN 20 // maximum length of passenger names

int available_seats = MAX_SEATS;               // number of available seats
char passenger_names[MAX_SEATS][MAX_NAME_LEN]; // array to store passenger names

void print_seats() {
  printf("Available seats: %d\n", available_seats);
  printf("Passenger list:\n");
  for (int i = 0; i < MAX_SEATS; i++) {
    if (strlen(passenger_names[i]) > 0) {
      printf("Seat %d: %s\n", i + 1, passenger_names[i]);
    }
  }
}

void reserve_seat() {
  if (available_seats > 0) {
    int seat_number;
    char passenger_name[MAX_NAME_LEN];

    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > MAX_SEATS) {
      printf("Invalid seat number.\n");
      return;
    }
    if (strlen(passenger_names[seat_number - 1]) > 0) {
      printf("Seat already reserved.\n");
      return;
    }

    printf("Enter passenger name: ");
    scanf("%s", passenger_name);

    strncpy(passenger_names[seat_number - 1], passenger_name, MAX_NAME_LEN);
    available_seats--;

    printf("Seat reserved for %s.\n", passenger_name);
  } else {
    printf("All seats are taken.\n");
  }
}

void cancel_reservation() {
  int seat_number;

  printf("Enter seat number (1-%d): ", MAX_SEATS);
  scanf("%d", &seat_number);

  if (seat_number < 1 || seat_number > MAX_SEATS) {
    printf("Invalid seat number.\n");
    return;
  }

  if (strlen(passenger_names[seat_number - 1]) == 0) {
    printf("Seat is not reserved.\n");
    return;
  }
char passenger_name[MAX_NAME_LEN];
strncpy(passenger_name, passenger_names[seat_number - 1], MAX_NAME_LEN);
  memset(passenger_names[seat_number - 1], 0, MAX_NAME_LEN);
  available_seats++;

  printf("Reservation cancelled for %s.\n", passenger_name);
}

int main() {
  int choice;
  do {
    printf("\nTrain ticket reservation system\n");
    printf("1. Reserve seat\n");
    printf("2. Cancel reservation\n");
    printf("3. Print available seats\n");
    printf("4. Exit\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      reserve_seat();
      break;
    case 2:
      cancel_reservation();
      break;
    case 3:
      print_seats();
      break;
    case 4:
      printf("Goodbye!\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
    }
  } while (choice != 4);

  return 0;
}