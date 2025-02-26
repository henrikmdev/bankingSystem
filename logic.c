#include <stdio.h>
#include "bank.h"

double deposit(double balance, double amount) {
    if (amount < 10.0) {
        printf("Deposit failed: Amount too small! Minimum deposit is $10.00.\n");
    } 
    else if (amount > 5000.0) {
        printf("Deposit failed: Amount too large! Maximum deposit is $5000.00.\n");
    } 
    else {
        balance += amount;
        printf("Deposit successful! New balance: $%.2f\n", balance);
    }
    return balance;
}

double withdraw(double balance, double amount, int *withdrawal_attempts) {
    if (amount > balance) {
        printf("Withdrawal failed: Insufficient funds!\n");
        (*withdrawal_attempts)++;
    } 
    else if (amount > 500.0) {
        printf("Withdrawal failed: Exceeds max withdrawal limit of $500.00!\n");
        (*withdrawal_attempts)++;
    } 
    else {
        balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", balance);
        *withdrawal_attempts = 0;
    }
    return balance;
}
