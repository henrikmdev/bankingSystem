#include <stdio.h>
#include "bank.h"

int main() {
    double balance = 1000.0;
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
            printf("Enter amount to deposit (min: $10.00, max: $5000.00): ");
            scanf("%lf", &amount);
            balance = deposit(balance, amount);
        } 
        else if (choice == 3) {
            printf("Enter amount to withdraw (max: $500.00): ");
            scanf("%lf", &amount);
            balance = withdraw(balance, amount, &withdrawal_attempts);

            if (withdrawal_attempts >= 3) {  
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
