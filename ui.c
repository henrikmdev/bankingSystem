#include <stdio.h>
#include "bank.h"

void display_menu() {
    printf("\nBanking System Menu:\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

void display_balance(double balance) {
    printf("Your current balance is: $%.2f\n", balance);
}
