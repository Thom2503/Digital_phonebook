#include <stdio.h>
#include <string.h>
#include <unistd.h>

int choice;

int main()
{
    FILE *fp;

    char input[256], firstName[256], lastName[256];
    int value, phoneNumber;

    printf("Welcome to your personal digital phonebook!\n");
    printf("Do you want to view (type 0) your phonebook or add (type 1) someone?\n");

    fgets(input, 256, stdin);
    sscanf(input, "%d", &choice);

    if(choice == 1)
    {
        printf("You choose to add someone.\n");
        
        fp = fopen("contacts.txt", "a");

        printf("Please enter the first name of the person you want to add:\n");

        fgets(input, 256, stdin);
        sscanf(input, "%s", firstName);

        printf("Now what's their last name?\n");
        fgets(input, 256, stdin);
        sscanf(input, "%s", lastName);

        printf("What's %s %s's phone number?\n", firstName, lastName);
        while(1)
        {
            fgets(input, 256, stdin);
            if(sscanf(input, "%d", &phoneNumber) == 1) break;
            printf("That's not a number... try again\n");
        }   

        printf("I've added %s %s with phonenumber %d to the phonebook.\n", firstName, lastName, phoneNumber);
        fprintf(fp, "%s %s - %d\n", firstName, lastName, phoneNumber);
    
    } else
    {
        fp = fopen("contacts.txt", "rb");

        while(1)
        {
            value = fgetc(fp);
            if(value == EOF) break;
            else printf("%c", value);
        }
    }

    fclose(fp);
}
