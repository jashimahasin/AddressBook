#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"



/*void initialize(AddressBook *addressBook)
{
    initialize contactCount = 0;
    /* 1.open contact.txt file in read mode 
    2. Run a loop until it reach the  EOF
    {
        1. read name from the file upto comma use selevtive scanf([^,]) and store to addressbook->contacts[i]. name
        2. read phone from the file and store to addressBook->
        3. read mail from the file and store to addressBook->
        4. inc addressBook->contactCount++

    }
    3. close the  file 
    // we face one issue, scanf will read upto , not comma , so the next parameter needs to be read so find that logic and include it
}


/*void createContact(AddressBook *addressBook)
{
	// Define the logic to create a Contacts 


/*void createContact(AddressBook *addressBook)
{
    /* 1. read name
        {
            char temp_name[30];
        }
        2.validate
            To validate 1) chaeck upper case , lowercase , n  no of spaces but space shouls not be at first and last and b/w name  more than 1 space is not allowed. if
        if inavlid means  -->
             go to step no 1
        valid yes -->
            3. read phone char temp_phone[15];
        4.check strlen = 10, all are '0' - '9'
        invalid no -->
            go to step 3
        valid yes -->
        5.read mail char temp--> mail[30];
        6.validate 
            check '@' present , ".com"(To check .com string use strstr fn),all are need to be in lowercase, after @ there should be min 1 char present
        if invalid no -- > count chance 
            go to step 5
        valid yes -- >
        7.Store temp_name,temp-phone,temp_mail to  addressBook-> contacts[addressbook--->contactCount]
        8.increment contactCount
        9.stop
       
}*/

void initialize(AddressBook *addressBook)
{
  
   FILE* fr=fopen("contacts.txt","r");

    addressBook->contactCount=0;
    if(fr==NULL)
    {
        printf("file not opened");
        return;
    }
    printf("File found");
    
    while(fscanf(fr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,
        addressBook->contacts[addressBook->contactCount].email)!=EOF)
    {
        addressBook->contactCount++;
    } 
   
   fclose(fr);
    
}

void listContacts(AddressBook *addressbook)
{
    printf("Name\t\tPhonenumber\tEmail\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        printf("%-15s %-15s %s\n",
               addressbook->contacts[i].name,
               addressbook->contacts[i].phone,
               addressbook->contacts[i].email);
    }
}
void createContact(AddressBook *addressbook)
{

    char temp_name[30];
    char temp_phone[15];
    char temp_email[30];
    int attempts;

    
    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your name: ");
        scanf(" %[^\n]", temp_name);

        int valid = 1;

        if (temp_name[0] == ' ')
            valid = 0;

        for (int i = 0; temp_name[i] != '\0'; i++)
        {
            if (!((temp_name[i] >= 'A' && temp_name[i] <= 'Z') ||
                  (temp_name[i] >= 'a' && temp_name[i] <= 'z') ||
                  temp_name[i] == ' '))
            {
                valid = 0;
                break;
            }

            if (temp_name[i] == ' ' && temp_name[i + 1] == ' ')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            break;

        printf("Invalid name... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

   
    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your number: ");
        scanf(" %s", temp_phone);

        int valid = 1;

        if (strlen(temp_phone) != 10)
            valid = 0;

        for (int i = 0; temp_phone[i] != '\0'; i++)
        {
            if (!(temp_phone[i] >= '0' && temp_phone[i] <= '9'))
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            break;

        printf("Invalid phone number... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

    
    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your email: ");
        scanf(" %s", temp_email);

        int valid = 1;

        for (int i = 0; temp_email[i] != '\0'; i++)
        {
            if (!((temp_email[i] >= 'a' && temp_email[i] <= 'z') ||
                  temp_email[i] == '@' || temp_email[i] == '.'))
            {
                valid = 0;
                break;
            }
        }

        if (strstr(temp_email, ".com") == NULL)
            valid = 0;

        if (valid)
            break;

        printf("Invalid email... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

    
    strcpy(addressbook->contacts[addressbook->contactCount].name, temp_name);
    strcpy(addressbook->contacts[addressbook->contactCount].phone, temp_phone);
    strcpy(addressbook->contacts[addressbook->contactCount].email, temp_email);

    addressbook->contactCount++;
    printf("Contact Added Successfully...\n");
}
void searchContact(AddressBook *addressbook)
{
    printf("Tell based on which criteria u want to search\n");

    int option;
    scanf("%d", &option);

    switch(option)
    {
        case 1:   
        {
            char name[50];   
            printf("Enter the name: ");
            scanf(" %[^\n]", name);

            int flag = 0;   

            for(int i = 0; i < addressbook->contactCount; i++)
            {
                if(strstr(addressbook->contacts[i].name, name) != NULL)
                {
                    printf("%d %s %s %s\n",i + 1,addressbook->contacts[i].name,addressbook->contacts[i].phone,
                           addressbook->contacts[i].email);
                    flag = 1; 
                }
            }

            if(flag == 0)
                printf("No User found..\n");

            break;
        }

        case 2:     
        {
            char number[50];
            printf("Enter the phone Number: ");
            scanf(" %[^\n]", number);

            int flag = 0;  

            for(int i = 0; i < addressbook->contactCount; i++)
            {
                if(strstr(addressbook->contacts[i].phone, number) != NULL)
                {
                    printf("%d %s %s %s\n",i + 1,addressbook->contacts[i].name,addressbook->contacts[i].phone,
                           addressbook->contacts[i].email);
                    flag = 1;  
            }

            if(flag == 0)
                printf("No User found..\n");

            break;
        }
    }

        case 3:     
        {
            char mail[50];
            printf("Enter the Mail: ");
            scanf(" %[^\n]", mail);

            int flag = 0;  

            for(int i = 0; i < addressbook->contactCount; i++)
            {
                if(strstr(addressbook->contacts[i].email, mail) != NULL)
                {
                    printf("%d %s %s %s\n",i + 1,addressbook->contacts[i].name,addressbook->contacts[i].phone,
                           addressbook->contacts[i].email);
                    flag = 1; 
                }
            }

            if(flag == 0)
                printf("No User found..\n");

            break;
        }

        default:
            printf("Invalid option\n");
    }
}


void editContact(AddressBook *addressbook)
{
    char temp_name[30];
    int index = -1;
    int attempts;

    printf("Enter name to edit: ");
    scanf(" %[^\n]", temp_name);

    
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(addressbook->contacts[i].name, temp_name) == 0)
        {
            index = i;  
            break;
        }
    }

    if (index == -1)  
    {
        printf("Name not found\n");
        return;
    }

    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter new name: ");
        scanf(" %[^\n]", temp_name);

        int valid = 1;
        if (temp_name[0] == ' ')
            valid = 0;

        for (int i = 0; temp_name[i] != '\0'; i++)
        {
            if (!((temp_name[i] >= 'A' && temp_name[i] <= 'Z') ||
                  (temp_name[i] >= 'a' && temp_name[i] <= 'z') ||
                  temp_name[i] == ' '))
            {
                valid = 0;
                break;
            }

            if (temp_name[i] == ' ' && temp_name[i + 1] == ' ')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            break;

        printf("Invalid name... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

    char temp_phone[30];
    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your number: ");
        scanf(" %s", temp_phone);

        int valid = 1;
        if (strlen(temp_phone) != 10)
            valid = 0;

        for (int i = 0; temp_phone[i] != '\0'; i++)
        {
            if (!(temp_phone[i] >= '0' && temp_phone[i] <= '9'))
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            break;

        printf("Invalid phone number... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

    char temp_email[30];
    attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your email: ");
        scanf(" %s", temp_email);

        int valid = 1;
        for (int i = 0; temp_email[i] != '\0'; i++)
        {
            if (!((temp_email[i] >= 'a' && temp_email[i] <= 'z') ||
                  temp_email[i] == '@' || temp_email[i] == '.'))
            {
                valid = 0;
                break;
            }
        }

        if (strstr(temp_email, ".com") == NULL)
            valid = 0;

        if (valid)
            break;

        printf("Invalid email... Try again\n");
        attempts++;
    }

    if (attempts == 3)
        return;

    strcpy(addressbook->contacts[index].name, temp_name);
    strcpy(addressbook->contacts[index].phone, temp_phone);
    strcpy(addressbook->contacts[index].email, temp_email);

    printf("Contact updated successfully\n");
}


void deleteContact(AddressBook *addressbook)
{
    char temp_name[30];
    int count = 0;

    while (count < 3)
    {
        printf("Enter name to delete: ");
        scanf(" %[^\n]", temp_name);

        int foundIndex = -1;

        for (int i = 0; i < addressbook->contactCount; i++)
        {
            if (strcmp(addressbook->contacts[i].name, temp_name) == 0)
            {
                foundIndex = i;

                for (int k = i; k < addressbook->contactCount - 1; k++)
                {
                    strcpy(addressbook->contacts[k].name,addressbook->contacts[k + 1].name);
                    strcpy(addressbook->contacts[k].phone,addressbook->contacts[k + 1].phone);
                    strcpy(addressbook->contacts[k].email,addressbook->contacts[k + 1].email);
                }

                addressbook->contactCount--;
                printf("Contact deleted successfully\n");
                return;
            }
        }

        if (foundIndex == -1)
        {
            printf("Contact not found. Try again\n");
            count++;
        }
    }

    printf("Invalid input. Maximum attempts reached\n");
}
void save(AddressBook *addressbook)
{
    FILE *fr = fopen("contacts.txt","w");
    for(int i = 0; i < addressbook->contactCount; i++)
    {
        
        fprintf(fr,"%s,",addressbook->contacts[i].name);
        fprintf(fr,"%s,",addressbook->contacts[i].phone);
        fprintf(fr,"%s",addressbook->contacts[i].email);
        fprintf(fr,"\n");

    }
    fclose(fr);
    printf("Contact saved successfully....");
}











	
   

