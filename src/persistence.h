#ifndef PERSISTENCE_H
#define PERSISTENCE_H
#include "account.h"
int saveAccount(const Account *acc);
int loadAllAccounts(Account *accounts, int max_accounts);
#endif