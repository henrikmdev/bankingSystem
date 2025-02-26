#ifndef BANK_H
#define BANK_H

// Constants for transactions
#define MIN_DEPOSIT 10.0
#define MAX_DEPOSIT 5000.0
#define MAX_WITHDRAWAL 500.0
#define MAX_WITHDRAWAL_ATTEMPTS 3  
#define INITIAL_BALANCE 1000.0  

// UI Functions

/**
 * Displays the menu options to the user.
 */
void display_menu();

/**
 * Displays the current account balance.
 * @param balance The current balance in the account.
 */
void display_balance(double balance);

// Logic Functions

/**
 * Deposits an amount into the balance.
 * @param balance The current balance.
 * @param amount The amount to be deposited.
 * @return The updated balance after deposit.
 */
double deposit(double balance, double amount);

/**
 * Withdraws an amount from the balance, considering withdrawal attempts.
 * @param balance The current balance.
 * @param amount The amount to withdraw.
 * @param withdrawal_attempts Pointer to track failed withdrawal attempts.
 * @return The updated balance after withdrawal.
 */
double withdraw(double balance, double amount, int *withdrawal_attempts);

#endif
