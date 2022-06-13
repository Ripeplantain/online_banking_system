#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct user- Is the the structure used to save a user entity
//     main- Output code logic


struct user {
    char account[50];
    char phoneNumber[50];
    char password[50];
    double balance;
};

int main()
{
    struct user user,user1;
    int option,choice; 
    FILE *file;
    char filename[50],phone[50],passwrd[50];
    char cont = 'y';
    float amount;

    printf("\n Welcome to Cal Bank Services");
    printf("\n \n What do you want to do today?");
    printf ("\n\n 1- Register an account");
    printf("\n\n 2- Login into an account\n\n");
    scanf("%d",&option);

    if(option == 1)
    {
        system("clear");

        printf("\n Enter your account number\n");
        scanf("%s",user.account);
        printf("Enter your phone number\n");
        scanf("%s", user.phoneNumber);
        printf("Enter your password\n");
        scanf("%s", user.password);

        user.balance = 0;     
        strcpy(filename , user.phoneNumber);
        file = fopen(strcat(filename,".txt"),"w");
        fwrite(&user,sizeof(struct user),1,file);
        if(fwrite != 0)
        {
            printf("Welcome to the family!\n");
        } else {
            printf("Something went wrong\n");
        }
        fclose(file);
    } else {
        system("clear");
        printf("Enter your phone number: \t");
        scanf("%s", &phone);
        printf("\n Enter your password: \t");
        scanf("%s", &passwrd);
        file = fopen(strcat(filename,".txt"),"w");
        if (file == NULL){
            printf("Account not registered.\n");
        } else {
            fread(&user,sizeof(struct user),1,file);
        fclose(file);
        if(strcmp(passwrd,user.password)){
            while(cont == 'y'){
                system("clear");
                printf("\n Press 1 to check balance");
                printf("\n Press 2 to deposit amount");
                printf("\n Press 3 to withdraw amount");
                printf("\n Press 4 to transfer amount");
                printf("\n Press 5 to change your password \n");

                printf("\n Your choice: \t");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        printf("\n Your balance is $ %2f",user.balance);
                        break;
                    case 2:
                        printf("\n How much do you want to deposit?\t");
                        scanf("%f",&amount);
                        user.balance += amount;
                        file = fopen(filename,"w");
                        fwrite(&user,sizeof(struct user),1,file);
                        if (fwrite != NULL){
                             printf("\n Succesfully deposited");
                             printf("\n You are balance is $%2f",user.balance);

                        }
                        fclose(file);
                        break;
                    case 3:
                        printf("\n How much do you want to withdraw?\t");
                        scanf("%f",&amount);
                        user.balance -= amount;
                        file = fopen(filename,"w");
                        fwrite(&user,sizeof(struct user),1,file);
                        if (fwrite != NULL) {
                            printf("\n You have withdrawn $%2f",amount);
                            printf("\n You are balance is $%2f",user.balance);
                        }
                        fclose(file);
                        break; 
                    case 4:
                        printf("\n Please enter phone number of recipient:\t");
                        scanf("%s",&phone);
                        printf("\n Please enter amount you want to transfer:\t");
                        scanf("%f",&amount);
                       
                        strcpy(filename,phone);
                        file = fopen(strcat(filename,".txt"),"w");
                        if(file == NULL) printf("\n Phone number is not registered");      

                        else{   
                            fread(&user1,sizeof(struct user),1,file);
                        fclose(file);
                        if(amount > user.balance) printf("/n Insufficient funds");
                        else{
                            file = fopen(filename,"w");
                            user1.balance += amount;
                            fwrite(&user1,sizeof(struct user),1,file);
                            fclose(file);
                            if(fwrite != NULL){
                                printf("\n You have successfully transfered $%2f to %s",amount,phone);
                                strcpy(filename,user.phoneNumber);
                                fopen(strcat(filename,".txt"),"w");
                                user.balance -= amount;
                                fwrite(&user,sizeof(struct user),1,file);
                                fclose(file);
                        }
                        }
                        }                   
                        break;

                    case 5:
                        printf("\n Enter your new password");
                        scanf("%s",&passwrd);
                        file = fopen(filename,"w");
                        strcpy(user.password,passwrd);
                        fwrite(&user,sizeof(struct user),1,file);
                        if (fwrite != NULL){
                            printf("\n Password has been changed successfully");
                        }
                        break;
                        default:
                            printf("\n Invalid option");
                }

                printf("\n Press do you wnat to continue transaction y/n \t");
                scanf("%s", &cont);
            }
        } else {
            printf("Wrong password");
        }
        }


        
    }

    return 0;
} 