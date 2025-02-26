#include <stdio.h>

int main() {
    double balance = 1000.0;  // Initial balance
    int choice;
    double amount;
    int withdrawal_attempts = 0;

    while (1) {
        // Display menu
        printf("\nBanking System Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Display balance
            printf("Your current balance is: $%.2f\n", balance);
        } 
        else if (choice == 2) {
            // Deposit money
            printf("Enter amount to deposit (Min: $10.00, Max: $5000.00): ");
            scanf("%lf", &amount);
            if (amount < 10.0) {
                printf("Deposit failed: Amount too small!\n");
            } else if (amount > 5000.0) {
                printf("Deposit failed: Amount too large!\n");
            } else {
                balance += amount;
                printf("Deposit successful! New balance: $%.2f\n", balance);
            }
        } 
        else if (choice == 3) {
            // Withdraw money
            printf("Enter amount to withdraw (Max per transaction: $500.00): ");
            scanf("%lf", &amount);
            if (amount > balance) {
                printf("Withdrawal failed: Insufficient funds!\n");
                withdrawal_attempts++;
            } else if (amount > 500.0) {
                printf("Withdrawal failed: Exceeds max withdrawal limit!\n");
                withdrawal_attempts++;
            } else {
                balance -= amount;
                printf("Withdrawal successful! New balance: $%.2f\n", balance);
                withdrawal_attempts = 0;  // Reset on success
            }

            if (withdrawal_attempts >= 3) {
                printf("Too many failed withdrawals! Account locked.\n");
                return 0;
            }
        } 
        else if (choice == 4) {
            // Exit program
            printf("Exiting program.\n");
            return 0;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
