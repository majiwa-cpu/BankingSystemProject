#include <stdio.h>
#include "persistence.h"
int saveAccount(const Account *acc) {
    FILE *file = fopen("accounts.dat", "ab");
        if (!file) return 0;
            fwrite(acc, sizeof(Account), 1, file);
            fclose(file);
return 1;
}
int loadAllAccounts(Account *accounts, int max_accounts) {
    FILE *file = fopen("accounts.dat", "rb");
    if (!file) return 0;
    int count = 0;
        while (fread(&accounts[count], sizeof(Account), 1, file) && count < max_accounts) {
count++;
}
fclose(file);
return count;
}