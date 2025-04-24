#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "account.h"
#define ACCOUNT_FILE "accounts.dat"
void generateAccountNumber(char *account_number) {
static int seeded = 0;
if (!seeded) {
srand(time(NULL));
seeded = 1;
}
sprintf(account_number, "10");
for (int i = 2; i < 10; i++) {
account_number[i] = '0' + rand() % 10;
}
account_number[10] = '\0';
}
int createAccount(Account *acc) {
    printf("========================================\n");
    printf("Welcome to Kingdom bank account creation\n");
    printf("========================================\n");
    printf("Enter your fullname: ");
    fgets(acc->full_name, sizeof(acc->full_name), stdin);
    acc->full_name[strcspn(acc->full_name, "\n")] = 0;
    printf("Enter your ID number: ");
    fgets(acc->id_number, sizeof(acc->id_number), stdin);
    acc->id_number[strcspn(acc->id_number, "\n")] = 0;
    printf("Enter your KRA PIN: ");
    fgets(acc->kra_pin, sizeof(acc->kra_pin), stdin);
    acc->kra_pin[strcspn(acc->kra_pin, "\n")] = 0;
    printf("Enter your Phone number: ");
    fgets(acc->phone_number, sizeof(acc->phone_number), stdin);
    acc->phone_number[strcspn(acc->phone_number, "\n")] = 0;
    printf("Enter your E-mail address: ");
    fgets(acc->email, sizeof(acc->email), stdin);
    acc->email[strcspn(acc->email, "\n")] = 0;
    printf("Enter your Gender (Male/Female): ");
    fgets(acc->gender, sizeof(acc->gender), stdin);
    acc->gender[strcspn(acc->gender, "\n")] = 0;
    printf("Enter your Date Of Birth: ");
    fgets(acc->DOB, sizeof(acc->DOB), stdin);
    acc->DOB[strcspn(acc->DOB, "\n")] = 0;
    printf("Please create your pin: ");
    fgets(acc->pin, sizeof(acc->pin), stdin);
    acc->pin[strcspn(acc->pin, "\n")] = 0;
    acc->balance = 0;
    generateAccountNumber(acc->account_number);
    strcpy(acc->account_status, "Active");
    FILE *file = fopen(ACCOUNT_FILE, "ab");
        if (!file) {
            perror("Failed to open file");
return 0;
}
    fwrite(acc, sizeof(Account), 1, file);
    fclose(file);
    printf("Account successfully created\n");
    printf("Account number: %s\n", acc->account_number);
return 1;
}
int loadAccount(const char *account_number, Account *acc) {
FILE *file = fopen(ACCOUNT_FILE, "rb");
if (!file) return 0;
while (fread(acc, sizeof(Account), 1, file)) {
if (strcmp(acc->account_number, account_number) == 0) {
fclose(file);
return 1;
}
}
fclose(file);
return 0;
}
int updateAccount(const Account *acc) {
FILE *file = fopen(ACCOUNT_FILE, "rb+");
if (!file) return 0;
Account temp;
while (fread(&temp, sizeof(Account), 1, file)) {
if (strcmp(temp.account_number, acc->account_number) == 0) {
    fseek(file, -sizeof(Account), SEEK_CUR);
    fwrite(acc, sizeof(Account), 1, file);
fclose(file);
return 1;
}
}
fclose(file);
return 0;
}
int deleteAccount(const char *account_number) {
FILE *file = fopen(ACCOUNT_FILE, "rb");
if (!file) return 0;
FILE *tempFile = fopen("temp.dat", "wb");
if (!tempFile) {
    fclose(file);
return 0;
}
Account acc;
int found = 0;
while (fread(&acc, sizeof(Account), 1, file)) {
if (strcmp(acc.account_number, account_number) != 0) {
fwrite(&acc, sizeof(Account), 1, tempFile);
} else {
found = 1;
}
}
    fclose(file);
    fclose(tempFile);  
    remove(ACCOUNT_FILE);
    rename("temp.dat", ACCOUNT_FILE);
return found;
}