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
    struct user user;
    int option; 
    FILE *file;
    char filename[50],phone[50],passwrd[50];

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
        file = fopen(strcat(filename,".txt"), "r");
        fread(&user,sizeof(struct user),1,file);
        fclose(file);
        printf("check to see if logged in");
        if(!strcmp(passwrd,user.password))
        {
            printf("\n Password matched");
        } else {
            printf("\n Invalid password");
        }
    }

    return 0;
} 