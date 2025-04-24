#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "account.h"
void deposit(Account *acc, float amount);
int withdraw(Account *acc, float amount);
#endif