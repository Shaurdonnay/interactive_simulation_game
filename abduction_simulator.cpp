// Natasha Johnson, CSC C++ class, July 12th 2021
// This is my text based game for the assignment C++ Learning Functions with Interactive Simulation
// I tried to get the sleep function to work to "take a break" before the next line but it wouldn't work so I googled it and it said to use these preprocessors to make usleep work
// The Windows.h is saying for the program to run in windows... This was not working for me
#ifdef _WIN32
#include <Windows.h>
// The next lines tell the program to run unistd.h (linux) if the user is not using Windows
#else
#include <unistd.h>
#endif
/* The next line is a preprocessor directive, it is indicated with the # symbol. The preprocessor
runs before the compiler and substitutes text based on various directived. The # is telling the 
program to include the contents of the iostream and string, which are part of the standard library */
#include <iostream>
#include <cstdlib>
// The folowing is for my srand function to work properly
#include <ctime>
#include "ProjectInteractiveGameRedo.h"
// The next line indicates that I want to use the standard namespace for the entire program
// It makes the text shorter and when you type a lot makes your code a little easier
using namespace std;
/* The next line is the header of a function of main(). Int indicates that the function will
return a value, in this case it indicates that the functions will return an integer value */
// The following are my functions for the game

int main()
{
// The following line makes use of the computer's internal clock to control the choice of the seed. Since time is continually changing, the seed is going to forever changing.
    srand(time(NULL));
// Intro to the game, all text strings are placed in "" because that is what I want the text to say, word for word
/* As stated in my previus assignment, cout is an object, and is used to send data to the standart output string. The << says
to send the string to cout. At the end the endl string is being sent to the standard output with the << and is the same as saying 
"hit the enter button" It is used throughout the program as it is a text based game and outputs many strings*/
    std::cout << "▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒\n";
    std::cout << "▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒\n";
    std::cout << "▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒\n";
    std::cout << "▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒\n";
    std::cout << "▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒\n\n\n";
// The following usleep function is telling the program to delay before posting the next line. It is in ms though unlike the sleep function.
    usleep(1500000);
    callGame();
    
// The following sleep function is telling the program to delay before posting the next line.
    usleep(2000000);
    std::cout << "The goal of Abduction is not to get abducted. If you do, you lose!\n\n\n";
// The following usleep function is telling the program to delay before posting the next line.
    usleep(2000000);
// This starts the questions in the game.
    
   questionOne(); 
    std::cout << "A)  Run the opposite direction\n";
    std::cout << "B)  Post it on TikTok\n";
    std::cout << "C)  Wave a white flag and surrender\n\n\n";

    std::cout << "Type your answer according to the letter....ie. A, B, or C\n\n\n";
// The following char keyword is used to declare character type variables. A character variable can store only a single character.
    char userinput;
// Bool is a type that can hold only two values: true and false . I used it to determine what to do based on if the asking is true or false.
    bool asking = true;
// The while statement will execute a block of code as long as a specified condition is reached, ie which answer was given.
    while(asking){
        
        std::cin >> userinput;
// I used the switch statement to select one of three options to be executed based on the userinput. 
        switch (userinput)
        {
// If case A, B, or C is chosen for the first question, the program will print the case accordingly and another question is asked based on the answer. 
        case 'A':
            
            questionTwo();
            asking = false;
        break;
        case 'B':
            questionThree();
            asking = false;
        break;

        case 'C':
            questionFour();
            asking = false;
        break;
// If any userinput did not equal A, B, or C, then the following will print informing the user that their answer was invalid.
        default:
            std::cout <<"Invalid, try to type 'A','B' or 'C'\n";
            asking = true;
            break;
        }
    }
// If the user selects option A, the following cout lines will be printed out. This will give the user 3 more questions to answer.
    if (userinput == 'A')
    {
        std::cout <<"A) Run even faster.\n";
        std::cout <<"B) Post this to TikTok. It will go viral!\n";
        std::cout <<"C) Throw a rock at it.\n";
// In the following lines... The char keyword is used to declare character type variables. A character variable can store only a single character.
// Bool is a type that can hold only two values: true and false . I used it to determine what to do based on if the asking is true or false.
// The while statement will execute a block of code as long as a specified condition is reached, ie which answer was given.
// I used the switch statement to select one of three options to be executed based on the userinput. 
        bool asking2 = true;
        while (asking2)
        {
        char input2;
        std::cin >> input2;
        
        switch (input2)
        {
// If case A, B, or C is chosen for the case A question, the program will print the case accordingly.
        case 'A':
            std::cout <<"You ran faster\n";
            usleep(10000);
            std::cout <<"=========================================================================================\n";
            std::cout <<"==The spaceship is faster than you and has caught up to you and you have been abducted.==\n";
            std::cout <<"=========================================================================================\n";
            usleep(100000);
            asking2 = false;
            return 0;
            break;
        case 'B':
            std::cout << "You go viral! However, \n";
            usleep(300000);
            std::cout <<"========================================================================================\n";
            std::cout <<"The spaceship has beemed you up and you have now been abducted. Views are worthless now!\n";
            std::cout <<"========================================================================================\n";
            
            usleep(100000);
            asking2 = false;
            return 0;
            
            break;
        case 'C':
            std::cout << "You throw a rock at it\n";
            usleep(100000);
            int chance;
            chance = rand() % 100;
            if(chance < 30){
                std::cout <<"=============================================================\n";
                std::cout <<"==By a stroke of luck, the spaceship flys right past you==\n";
                std::cout <<"=============================================================\n";
                usleep(200000);
                std::cout <<"=========================================\n";
                std::cout <<"============You have survived!===========\n";
                std::cout <<"=========================================\n";
                 
                usleep(300000);
                asking2 = false;
                return 0;           
                }
            else{
                
                std::cout <<"====================================================================================\n";
                std::cout <<"==You have made the aliens mad and have now been beemed up for testing! You failed==\n";
                std::cout <<"====================================================================================\n";
                usleep(100000);
                asking2 = false;
                return 0;
            }
            break;
            default:
                std::cout << "Invalid, try to type 'A','B' or 'C'\n";
                asking2 = true;
            break;
                
        }
        }
    }
// If the user selects option B to the main question, the following cout lines will be printed out. This will give the user 3 more questions to answer.
        if (userinput == 'B')
        {
        usleep(100000);
        std::cout <<"A) Continue to post this on TikTok! It will make you famous when it goes viral!\n";
        std::cout <<"B) Scream.\n";
        std::cout <<"C) Throw a rock at it.\n";
// In the following lines... The char keyword is used to declare character type variables. A character variable can store only a single character.
// Bool is a type that can hold only two values: true and false . I used it to determine what to do based on if the asking is true or false.
// The while statement will execute a block of code as long as a specified condition is reached, ie which answer was given.
// I used the switch statement to select one of three options to be executed based on the userinput.         
        char input3;
        
        bool asking3 = true;
        while (asking3)
        {
        std::cin >> input3;
        switch (input3)
        {
        case 'A':
            std::cout <<"The spaceship stops and you film the aliens coming out. Suddenly they start dancing!\n";
            usleep(500000);
            std::cout <<"==============================================================================\n";
            std::cout <<"==However, they the remember they are here to capture people and abduct you.==\n";
            std::cout <<"==============================================================================\n";
            usleep(100000);
            asking3 = false;
            return 0;
            break;
        case 'B':
            std::cout << "You scream a lot.\n";
            usleep(300000);
            std::cout <<"==============================================================================\n";
            std::cout <<"==The aliens think you are crazy! They don't like your screams and fly away.==\n";
            std::cout <<"==============================================================================\n";
            usleep(100000);
            std::cout <<"===================================\n";
            std::cout <<"============You Survive!===========\n";
            std::cout <<"===================================\n";
            asking3 = false;
            usleep(300000);
            return 0;
            break;
        case 'C':
            std::cout << "You throw a rock\n";
            usleep(100000);
            int chance2;
            chance2 =  rand() % 100;
            if(chance2 < 40){
                std::cout <<"==========================================================\n";
                std::cout <<"==By a stroke of luck, the spaceship flys right past you==\n";
                std::cout <<"==========================================================\n\n\n";
                usleep(200000);
                std::cout <<"=========================================\n";
                std::cout <<"============You have survived!===========\n";
                std::cout <<"=========================================\n";
                usleep(300000);
                asking3 = false;
                return 0;
            }
            else{
                
                std::cout <<"=====================================================================================\n";
                std::cout <<"==You have made the aliens mad and have now been beemed up for testing! You failed.==\n";
                std::cout <<"=====================================================================================\n";
                usleep(100000);
                asking3 = false;
                return 0;
            }
            
        default:
            std::cout << "Invalid, try to type 'A','B' or 'C'\n";
            asking3 = true;
            break;
        }
        }  
    }
    if (userinput == 'C')
        {
        usleep(100000);
        std::cout <<"A) Play Dead\n";
        std::cout <<"B) Scream.\n";
        std::cout <<"C) Walk backwards slowly.\n";
// In the following lines... The char keyword is used to declare character type variables. A character variable can store only a single character.
// Bool is a type that can hold only two values: true and false . I used it to determine what to do based on if the asking is true or false.
// The while statement will execute a block of code as long as a specified condition is reached, ie which answer was given.
// I used the switch statement to select one of three options to be executed based on the userinput.        
        char input4;
        
        bool asking4 = true;
        while (asking4)
        {
        std::cin >> input4;
        switch (input4)
        {
        case 'A':
            std::cout <<"You lay on the ground in front of the spaceship.\n";
            usleep(500000);
            std::cout <<"===========================================================================================================================\n";
            std::cout <<"========The aliens know you are weak and will not fight.. They have decided to study you! You have been abducted.==========\n";
            std::cout <<"===========================================================================================================================\n";
            usleep(100000);
            asking4 = false;
            return 0;
            break;
        case 'B':
            std::cout << "You scream a lot.\n";
            usleep(300000);
            std::cout <<"==============================================================================\n";
            std::cout <<"==The aliens think you are crazy! They don't like your screams and fly away.==\n";
            std::cout <<"==============================================================================\n";
            usleep(100000);
            std::cout <<"=========================================\n";
            std::cout <<"============You have survived!===========\n";
            std::cout <<"=========================================\n";
            asking4 = false;
            usleep(300000);
            return 0;
            break;
        case 'C':
            std::cout << "You back away slowy\n";
            usleep(100000);
// The following is creating a random number so that the win/lose is determined by chance. 
            int chance3;
// If the roll is greater than 50 then you win and if it is less then you lose. 
            chance3 =  rand() % 100;
            if(chance3 < 50){
                std::cout <<"==============================================\n";
                std::cout <<"===The aliens have given up on abducting you==\n";
                std::cout <<"==============================================\n\n\n";
                usleep(200000);
                std::cout <<"=========================================\n";
                std::cout <<"============You have survived!===========\n";
                std::cout <<"=========================================\n";
                usleep(300000);
                asking4 = false;
                return 0;
            }
            else{
                
                std::cout <<"======================================================================================\n";
                std::cout <<"==You have made the aliens mad and have now been beemed up for testing! You failed..==\n";
                std::cout <<"======================================================================================\n";
                usleep(100000);
                asking4 = false;
                return 0;
             
        }  
    }
}
