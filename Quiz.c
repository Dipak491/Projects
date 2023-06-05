#include<stdio.h>
#include<string.h>

int sum = 0;    // global variable declaration
void quiz()
{
    int choice =0;
    int no = 4;
    int count = 0;
    
    int entry = 0;

    printf("Please enter 1 to start quiz \n");
    scanf("%d",&entry);
    if(entry == 1)
    {
        printf("Welcome to Quiz...\n");
        printf("1. Which is programming language \n");
        printf("1: A\n2: B\n3: C\n4: D\n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 3)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
        printf("--------------------------------------------------------------------------------\n");
    //2nd 
        printf("2. Who is the father of C language?\n");
        printf("1: Steve Jobs\n2: James Gosling\n3: Dennis Ritchie \n4: Rasmus Lerdorf \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 3)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
    printf("--------------------------------------------------------------------------------\n");
    // 3rd

    printf("3.Which of the following declaration is not supported by C language?\n");
        printf("1: String str;\n2: char *str;\n3: float str = 3e2; \n4: Both “String str;” and “float str = 3e2;” \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
    printf("--------------------------------------------------------------------------------\n");
    //4rth

        printf("4. Which keyword is used to prevent any changes in the variable within a C program?\n");
        printf("1: immutable\n2: mutable\n3: const \n4: volatile \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 3)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
        printf("--------------------------------------------------------------------------------\n");
    //5th 

    printf("5. What is an example of iteration in C?\n");
        printf("1: for\n2: while\n3: do-while\n4: all of the mentioned \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 4)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
        printf("--------------------------------------------------------------------------------\n");
    //6th
        printf("6.What is #include <stdio.h>?\n");
        printf("1: Preprocessor directive\n2: Inclusion directive\n3: File inclusion directive \n4: None of the mentioned\n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
        printf("--------------------------------------------------------------------------------\n");
    //7th 

        printf("7. The C-preprocessors are specified with _________ symbol.\n");
        printf("1:  #\n2: $\n3: & \n4: * \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Right answer \n");
            count++;
            sum = count + count;
            printf("You earned %d\n",sum);
        }
        else if(choice >= no)
        {
            printf("Enter valid input\n");
        }
        else
        {
            printf("Wrong answer \n ");
        }
    printf("--------------------------------------------------------------------------------\n");

    }
    else
    {
        printf("Please enter valid input\n");
    }

    if(sum >= 10)
    {
        
        printf("Your eligible for secound round \n");
    }
    else
    {
        printf("Your not eligible \n");
    }

    
}

int main()
{

    char name[10];
    printf("Enter Your Name :");
    scanf("%s",&name);

    // admin and student login 
    char  A = 'A';
    char  S = 'S';
    char ch = '\0';

    FILE *fp;   //to store data 
    char str1[800];

    char Username[15];
    char Password[15];

    printf("Press A for admin login or S for student login \n");
    scanf(" %c",&ch);

    if(A == ch)
    {
            printf("Enter username:\n");
            scanf("%s",&Username);
            printf("Enter password:\n");
            scanf("%s",&Password);
            
            
            if(strcmp(Username, "Admin")==0 )
            {
                if(strcmp(Password,"Admin")==0) 
                {
                    printf("Welcome Admin...\n");
                    
                    //file handling 
                    fp = fopen("data.txt","a");
                    fprintf(fp,"Admin User name is :%s\n",Username);
                    fprintf(fp,"Admin password is : %s\n",Password);
                   printf("Your name is appended in data.txt file\n");
                     quiz();
                   fprintf(fp,"score is  : %d\n",sum);
                    fclose(fp);

                }
                 else
                {
                    printf("\n Wrong passord \n");
                }
            }
            
    }
    
    else if(S == ch)
    {
          
            //file handling 
            fp = fopen("data.txt","a");
            printf("Enter student name:\n");
            scanf(" %s",&str1);
            fprintf(fp, "Student name is: %s\n",str1);
                
            printf("Your name is appended in data.txt file");
             quiz();
            fprintf(fp,"score is  : %d\n",sum);
            fclose(fp);
            
           
    }
    else
    {
        printf("wrong password");
    }

  

    return 0;
}