
# C Language Q&A Game

This code implements a simple question and answer game using C language. It presents a set of multiple-choice questions to the user and evaluates their answers. The code includes a data structure to store the questions and their corresponding choices and correct answers.

## Code Overview

The code can be summarized as follows:

-1 It includes necessary header files: `stdio.h`, `unistd.h`, and `ctype.h`.
-2 It defines a structure named `questions` to represent a question and its possible answers.
-3 The `main` function starts the execution of the program.
-4 It initializes an array of `questions` named `MCQ` with 20 predefined questions, choices, and correct answers.
-5 Variables `nbr_right_ans`, `score`, `game_number`, `answer`, `count`, and `Q_Aanswer` are declared.
-6 The program displays a welcome message.
-7 It asks the user if they are ready to play the game.
-8 If the user enters 'n', the program ends. Otherwise, the game continues.
-9 The program iterates through each question in the `MCQ` array.
-10 It displays the question and its choices to the user.
-11 The user enters their answer.
-12 The program checks if the answer is correct and updates the score accordingly.
-13 After answering all the questions, the program displays the number of games played, the score, and the number of correct answers.
-14 The program repeats the game loop until the user chooses to exit.
-15 If the user chooses to exit, the program displays a goodbye message and terminates.

## How to Run

To run the code, follow these steps:

1. Compile the code using a C compiler.
2. Execute the compiled program.
3. Answer the questions by entering the corresponding choice number.

## Contributions

Contributions to the code are welcome. Feel free to submit a pull request or open an issue for any improvements or bug fixes.

## Author✍️

For any inquiries or questions, you can reach out to the author at [oussama oulaydi](https://www.linkedin.com/in/oussamaoulaydi/).

