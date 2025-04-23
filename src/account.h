#ifndef ACCOUNT_H
#define ACCOUNT_H
typedef struct {
    char full_name[100];
    char id_number[20];
    char kra_pin[20];
    char phone_number[15];
    char email[50];
    char gender[10];
    char DOB[15];
    char account_number[20];
    float balance;
    char account_status[20];
    char pin[10];
} Account;
int createAccount(Account *acc);
void generateAccountNumber(char *account_number);
int loadAccount(const char *account_number, Account *acc);
int updateAccount(const Account *acc);
int deleteAccount(const char *account_number);
#endif
