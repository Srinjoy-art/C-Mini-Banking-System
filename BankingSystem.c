#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char name[50];
    int pin;
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

/* Create a new account */
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nBank is full. Cannot create more accounts.\n");
        return;
    }

    struct Account newAccount;

    printf("\n===== CREATE ACCOUNT =====\n");

    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);

    printf("Create a 4-digit PIN: ");
    scanf("%d", &newAccount.pin);

    newAccount.accountNumber = 1001 + accountCount;
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("\nAccount created successfully!\n");
    printf("Your Account Number is: %d\n", newAccount.accountNumber);
    printf("Please remember your account number and PIN.\n");
}

/* Find account */
int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }

    return -1;
}

/* Deposit money */
void deposit(int index) {
    float amount;

    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[index].balance += amount;

    printf("₹%.2f deposited successfully.\n", amount);
    printf("New Balance: ₹%.2f\n", accounts[index].balance);
}

/* Withdraw money */
void withdraw(int index) {
    float amount;

    printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;

    printf("₹%.2f withdrawn successfully.\n", amount);
    printf("Remaining Balance: ₹%.2f\n", accounts[index].balance);
}

/* Display account details */
void accountDetails(int index) {
    printf("\n===== ACCOUNT DETAILS =====\n");
    printf("Account Number : %d\n", accounts[index].accountNumber);
    printf("Name           : %s\n", accounts[index].name);
    printf("Balance        : ₹%.2f\n", accounts[index].balance);
}

/* User dashboard */
void dashboard(int index) {
    int choice;

    do {
        printf("\n========== BANK MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Account Details\n");
        printf("5. Logout\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nCurrent Balance: ₹%.2f\n",
                       accounts[index].balance);
                break;

            case 2:
                deposit(index);
                break;

            case 3:
                withdraw(index);
                break;

            case 4:
                accountDetails(index);
                break;

            case 5:
                printf("\nLogged out successfully.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 5);
}

/* Login */
void login() {
    int accountNumber;
    int pin;
    int index;

    printf("\n========== LOGIN ==========\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accountNumber);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (accounts[index].pin != pin) {
        printf("Incorrect PIN.\n");
        return;
    }

    printf("\nLogin successful!\n");
    printf("Welcome, %s!\n", accounts[index].name);

    dashboard(index);
}

/* Main function */
int main() {

    int choice;

    printf("====================================\n");
    printf("       WELCOME TO MINI BANK         \n");
    printf("====================================\n");

    do {

        printf("\n========== MAIN MENU ==========\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("===============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                printf("\nThank you for using Mini Bank!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

