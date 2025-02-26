#ifndef BANK_H
#define BANK_H

// UI Functions
void display_menu();
void display_balance(double balance);

// Logic Functions
double deposit(double balance, double amount);
double withdraw(double balance, double amount, int *withdrawal_attempts);

#endif
