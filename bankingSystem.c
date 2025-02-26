#include <stdio.h>
#include "bank.h"

/**
 * Main function that drives the banking system.
 * Users can check their balance, deposit, withdraw, or exit.
 * Withdrawal attempts are limited to MAX_WITHDRAWAL_ATTEMPTS.
 */
int main() {
    double balance = INITIAL_BALANCE;
    int withdrawal_attempts = 0;
    int choice;
    double amount;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            display_balance(balance);
        } 
        else if (choice == 2) {
            printf("Enter amount to deposit (min: $%.2f, max: $%.2f): ", MIN_DEPOSIT, MAX_DEPOSIT);
            scanf("%lf", &amount);
            balance = deposit(balance, amount);
        } 
        else if (choice == 3) {
            printf("Enter amount to withdraw (max: $%.2f): ", MAX_WITHDRAWAL);
            scanf("%lf", &amount);
            balance = withdraw(balance, amount, &withdrawal_attempts);

            if (withdrawal_attempts >= MAX_WITHDRAWAL_ATTEMPTS) {
                printf("Too many failed withdrawals! Account locked.\n");
                return 0;
            }
        } 
        else if (choice == 4) {
            printf("Exiting program.\n");
            return 0;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
