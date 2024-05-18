#include <stdio.h>

struct BankAccount {
    char name[50];
    int accountNumber;
    float balance;
};

// Function to create a new bank account
void createAccount(struct BankAccount *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);

    printf("Enter your account number: ");
    scanf("%d", &account->accountNumber);

    account->balance = 0.0;

    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(struct BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposit successful. Your new balance is: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(struct BankAccount *account, float amount) { 
    if (amount > account->balance) {
        printf("Insufficient funds. Withdrawal failed.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. Your new balance is: %.2f\n", account->balance);
    }
}

// Function to check account balance
void checkBalance(struct BankAccount *account) {
    printf("Your current balance is: %.2f\n", account->balance);
}

int main() {
    struct BankAccount userAccount;
    int choice;
    float amount;

    // Main menu
    printf("Welcome to the Basic Bank Management System\n");

    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&userAccount);
                break;
            case 2:
                printf("Enter the deposit amount: ");
                scanf("%f", &amount);
                deposit(&userAccount, amount);
                break;
            case 3:
                printf("Enter the withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(&userAccount, amount);
                break;
            case 4:
                checkBalance(&userAccount);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
