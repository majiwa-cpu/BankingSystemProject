#include <stdio.h>
#include "transactions.h"
void deposit(Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposited %.2f KES", amount);
}
int withdraw(Account *acc, float amount) {
    if (acc->balance >= amount) {
    acc->balance -= amount;
    printf("Withdrew %.2f KES", amount);
return 1;
} else {
    printf("Insufficient funds!");
        return 0;
        }
        }