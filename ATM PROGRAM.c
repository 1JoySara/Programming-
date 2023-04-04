#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[100];
    int account_number;
    float balance;
};
/*This defines a struct type 'account' that has three fields*/

void display_menu(struct account *a) {
    printf("\nHello, Welcome %s to the ATM\n", a->name);
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}
/*This function simply displays a menu of options for the user to choose from*/


void check_balance(struct account *a) {
    printf("Account Balance: %.2f\n", a->balance);
}
/*This function takes a pointer to an 'account' struct as an argument
 and prints out the current balance of the account*/

void deposit(struct account *a) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    a->balance += amount;
    printf("Deposit successful. Account balance is now %.2f\n", a->balance);
}
/*This function takes a pointer to an 'account' struct as an argument
 and asks the user to enter the amount they want to deposit. It then adds this amount
to the accounts balance and prints out the new balance */

void withdraw(struct account *a) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > a->balance) {
        printf("Insufficient funds. Withdrawal unsuccessful.\n");
    } else {
        a->balance -= amount;
        printf("Withdrawal successful. Account balance is now %.2f\n", a->balance);
    }
}
/*This function takes a pointer to an 'account' struct as an argument
 and asks the user to enter the amount they want to withdraw.If the account does not have enough
funds it prints an error message otherwise it subtracts the withdrawal amount from the account's
balance and prints out the new balance*/

int main() {
    struct account my_account = {"Fiona Omanyo", 123456789, 20000.00};
    int pin=1234,input;

    do{
        printf("Enter your pin:");
        scanf("%d",&input);
    if (input != pin){
            printf("Incorrect pin.Please Try Again\n");}
    }while(input!=pin);
    printf("Access Granted\n");
    /*This code runs an endless loop until the correct pin is entered*/

     int choice;
    do {
        display_menu(&my_account);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                check_balance(&my_account);
                break;
            case 2:
                deposit(&my_account);
                break;
            case 3:
                withdraw(&my_account);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
    }
/*This is the main function of the program.
It first creates an 'account' struct called 'my_account'
It then uses a do-while loop to display the menu and allow the user
to choose an option repeatedly until they choose to exit(option 4).
Depending on the user's choice it calls one of the three functions*/

/*The 'a->balance' is an expression that refers to the value of the 'balance'
 member of a struct pointed to by the pointer 'a'.
 The '->' operator is used to access the member of the pointed to object*/
