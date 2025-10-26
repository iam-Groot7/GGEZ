#include<stdio.h>
#include<unistd.h>

void checkBalance(float balance);
float deposit();
float withdraw(float numbers);

int main(){
    int choice;
    float balance;
    
    printf("*** WELCOME TO THE BANK ***\n");

    do{
        printf("\nSelect an option\n\n1. Check Balance\n2. Deposit money\n3. Withdraw Money\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("\nThank you for using the Bank!\n");
                break;
            default:
                printf("\nInvalid Choice!! Please select 1 - 4\n");
        }
    }while(choice != 4);
    sleep(5);
    return 0;
}

void checkBalance(float balance){
    printf("\nYour current balance is: $%.2f\n",balance);
}
float deposit(){
    float amount;
    printf("\nEnter amount to deposit: $");
    scanf("%f",&amount);
    if(amount<0){
        printf("\nInvalid Amount!!\n");
        return 0.0f;
    }
    else{
        printf("\nSuccessfully Deposited $%.2f!\n", amount);
        return amount;
    }
    return 0.0f;
}
float withdraw(float balance){
    float amount;

    printf("\nEnter amount to withdraw: $");
    scanf("%f",&amount);

    if(amount<0){
        printf("\nInvalid Amount!!\n");
        return 0.0f;
    }
    else if(amount>balance){
        printf("Insufficient amount! Your balance is: $%.2f\n", balance);
        return 0.0f;
    }
    else{
        printf("\nSuccessfully Withdrew $%.2f!\n", amount);
        return amount;
    }
    return 0.0f;
}