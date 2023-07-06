#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

typedef struct{ //answer == ans
    char question[100];
    char ans1[50];
    char ans2[50];
    char ans3[50];
    int right_ans;
} questions; //creating a quetions sturct with 4 var

void main()
{
    questions MCQ[20] = { //Creating a table type question , 20 vars
        {"Which of the following is the correct syntax for a single-line comment in C?", "1) // This is a comment", "2) /* This is a comment */", "3) <!-- This is a comment -->", 1},
        {"Which header file should be included to work with input/output operations in C?", "1) stdio.h", "2) math.h", "3) string.h", 1},
        {"Which operator is used to access the value at a specific memory address in C?", "1) *", "2) %", "3) &", 1},
        {"What is the correct way to declare a constant in C?", "1) const int x = 5;", "2) int x = constant 5;", "3) int constant x = 5;", 1},
        {"Which loop structure allows execution of a block of code multiple times?", "1) if", "2) for", "3) Switch", 2},
        {"Which data type is used to store a single character in C?", "1) float", "2) int", "3) char", 3},
        {"What is the purpose of the `sizeof` operator in C?", "1) perform arithmetic operations", "2) calculate the size of a variable or data type", "3) compare two values", 2},
        {"Which function is used to read a character from the standard input in C?", "1) getchar()", "2) scanf()", "3) gets()", 1},
        {"What does the break statement do in a loop or switch statement?", "1) Skips the current iteration and continues with the next iteration", "2) Returns a value from the function", "3) Terminates the loop or switch statement and transfers control to the next statement", 3},
        {"What is the correct way to dynamically allocate memory for an integer variable in C?", "1) malloc(sizeof(int))", "2) calloc(1, sizeof(int))", "3) new int", 1},
        {"What is the purpose of the const keyword inthe following code?", "1) Make a variable read-only", "2) Declare a constant variable", "3) Restrict pointer arithmetic", 1},
        {"Which function is used to compare two strings in C?", "1) strcmp()", "2) strlen()", "3) strcat()", 1},
        {"What is the purpose of the static keyword in C?", "1) Define a global variable", "2) Declare a function prototype", "3) Preserve the value of a variable between function calls", 3},
        {"Which standard library function is used to convert a string to an integer in C?", "1) atoi()", "2) itoa()", "3) atof()", 1},
        {"What is the difference between a recursion and an iteration?", "1) A recursion is a method of solving a problem by calling itself, while an iteration is a method of solving a problem by repeating a set of instructions.", "2) A recursion is a recursive function, while an iteration is a loop.", "3) A recursion is more efficient than an iteration, while an iteration is more flexible than a recursion.", 1},
        {"What is the purpose of the continue statement in a loop?", "1) Terminates the loop and transfers control to the next statement", "2) Skips the current iteration and continues with the next iteration", "3) Returns a value from the function", 3},
        {"Which function is used to write a character to the standard output in C?", "1)  putchar()", "2) printf()", "3) puts()", 1},
        {"Which keyword is used to define a function that does not return a value in C?", "1) int", "2) void", "3) char", 2},
        {"What is the relationship between pointers and arrays in C?", "1) Pointers and arrays are completely unrelated concepts in C.", "2) Pointers can be used to access elements of an array.", "3) Arrays can be used to store pointers.", 2},
        {"What is the size, in bytes, of the double data type in C?", "1) 2", "2) 4", "3) 8", 3}
    };

    int nbr_right_ans; // number of the correct ansers
    int score = 0;
    int game_number = 0;
    int answer, count;
    char Q_Aanswer;

    printf("\n\tC language | Q&A GAME \n\n");
    sleep(1);

    while(1)
    {
        printf("Are you ready? (y/n) : ");
        fflush(stdin);
        scanf("%c", &answer);
        char lowerCase = tolower(answer); //i used the lowercase function, to change the user's input if it is upperCase

        if (lowerCase == 'n') //checking if the answer equal to 'n'
            goto end; //if its true then goto end below
            game_number++; //increment the number of games
            nbr_right_ans = 0;

            for(int i = 0; i <=19 ; i++)
            {
                printf("\n%s\n", MCQ[i].question);
                printf("\n%s\n", MCQ[i].ans1);
                printf("%s\n", MCQ[i].ans2);
                printf("%s\n", MCQ[i].ans3);

                printf("\nWhat is your answer : ");
                scanf("%d", &Q_Aanswer);

                if(Q_Aanswer == MCQ[i].right_ans) //check if the answer inserted by user is iqual to the right answer (sturct)
                {
                    printf("That's the correct answer!\n\n");
                    nbr_right_ans++; //if the answer is right then number_of_answers it will increments
                    score += 5; // also the score will have the new value 5 and so on
                }
                else
                {
                    printf("Sorry that's incorrect!\n\n");
                }
            }

            printf("You have played %d Q&A games \n", game_number);
            sleep(1);
            printf("Your score is : %d%%\n", score);
            sleep(1);
            printf("The correct number of answers is %d from 20 question \n\n", nbr_right_ans);
    }

    end :
        sleep(1);
        printf("\nOKEY! bye bye :/ \n\n");
}

