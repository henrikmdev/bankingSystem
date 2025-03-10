#include <stdio.h>
#include "bank.h"

double deposit(double balance, double amount) {
    if (amount < MIN_DEPOSIT) {
        printf("Deposit failed: Amount too small! Minimum deposit is $%.2f.\n", MIN_DEPOSIT);
    } 
    else if (amount > MAX_DEPOSIT) {
        printf("Deposit failed: Amount too large! Maximum deposit is $%.2f.\n", MAX_DEPOSIT);
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
    else if (amount > MAX_WITHDRAWAL) {
        printf("Withdrawal failed: Exceeds max withdrawal limit of $%.2f!\n", MAX_WITHDRAWAL);
        (*withdrawal_attempts)++;
    } 
    else {
        balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", balance);
        *withdrawal_attempts = 0;
    }
    return balance;
}
