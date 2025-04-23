#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "persistence.h"
#include "security.h"
#include "transactions.h"
#include "ui.h"
int main() {
int choice;
Account current;
    while (1) {
        showMainMenu();
            scanf("%d", &choice);
            getchar();
if (choice == 1) {
    if (createAccount(&current)) {
            saveAccount(&current);
}
} else if (choice == 2) {
    char acc_num[20], pin[10];
        printf("Enter Account Number: ");
        fgets(acc_num, sizeof(acc_num), stdin);
acc_num[strcspn(acc_num, "\n")] = 0;
if (loadAccount(acc_num, &current)) {
    printf("Enter PIN: ");
    fgets(pin, sizeof(pin), stdin);
pin[strcspn(pin, "\n")] = 0;
if (verifyPin(pin, current.pin)) {
    printf("Login successful. Balance: %.2f KES\n", current.balance);
} else {
   printf("Invalid PIN.\n");
}
} else {
    printf("Account not found.\n");
}
} else if (choice == 3) {
    printf("Goodbye!\n");
break;
} else {
    printf("Invalid choice.\n");
}
}
return 0;
}