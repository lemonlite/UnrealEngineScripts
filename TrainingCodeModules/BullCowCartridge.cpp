// Fill out your copyright notice in the Description page of Project Settings.
//simple word guessing with player lives and gameover conditions game loop you can use flowchart
#include "BullCowCartridge.h" //this includes the code module a different source file 

// !!NOTE!! source file and header files are generated by unreal engine based on templates THIS IS NOT MADE FORM COMPLETE SCRATCH!

//FString HiddenWord = TEXT("chicken"); //this is bad practice elevating it on the global scope because you need
                                        //we need to declare the varibale hiddenword across the class that means that each class that uses hiddenword
                                        // has its own unique hidden word "variable" just dont put stuff in a global scope. 
void UBullCowCartridge::BeginPlay()     // When the game starts NOTE the variable hiddenword is initialized on this function
{
    //Welcome banner
    Super::BeginPlay();
    SetupGame();                //Initialize game  
    
    
                                                                         //the %s searches a data type is string and * is the pointer? blob? it will search the stored data on variable Hiddenword in memory location which is a string data "chicken" amazing.                                                                                 
    // PrintLine ((TEXT("The HiddenWord is: %s"), *HiddenWord));      //This is the correct formatting for FSTring? in unreal engine This is a debugging line  printf is an option C legacy idk.


                                           //this is where the function is called and it executes whatever function inside the function
                                                                  
                        //prompt user to guess
}

void UBullCowCartridge::OnInput(const FString& Input)   // When the player hits enter
{
    
    
    //else checking player guess conditional.

    if (bGameOver)
    {
            ClearScreen();
            SetupGame();

    }
    else        //checking player guess
    {
        ProcessGuess(Input);
     
    }
    




   
    
}

void UBullCowCartridge::SetupGame()          //added and defining the SetupGame function creating the first funcition
{
    

     //Welcome player
    PrintLine (TEXT("Hello welcome to word guessing game."));                          //This is the cout version for C++ unreal engine 
    
    HiddenWord = (TEXT("chicken"));              //NOTICE that we dont have to declare the variables here because it has been declared in the headers file as a member varibale which can be used anywhere with the same class "int" "strings" etc..
    Lives = HiddenWord.Len();                                  //declared in the headers file as a member varibale which can be used anywhere with the same class "int" "strings" etc.. inside this new function we initialize the lives
    bGameOver = false;

    PrintLine (TEXT("Guess the %i letter word"), HiddenWord.Len());  
    PrintLine (TEXT("You have %i Lives"), Lives);              
    PrintLine (TEXT("Press Tab to interact with the terminal.")); 
    
    

    
}


void UBullCowCartridge::EndGame()
{
        bGameOver = true;
        ClearScreen();
        PrintLine (TEXT(" Out of lives. Press enter to try again. \n"));
        
        

}


void UBullCowCartridge::ProcessGuess(FString Guess)
{

    if (Guess == HiddenWord )
     {
        PrintLine (TEXT("You won.\n"));             //early return 
        SetupGame();
        return;
     }
        //add another requirement if you want here      



     else                               //nested if  a lot of em
     {    
        PrintLine(TEXT("Lost a life.")); --Lives;       //decrementing lives loop just copy and paste if u want harsher requirnemt like letter cases etc....
        if (Lives > 0)
        {
            if  (Guess.Len() != HiddenWord.Len())
            {
            PrintLine(TEXT("\nTry again you have %i lives remaining. "), Lives);
            }
        }
        else
        {
            PrintLine(TEXT("You have no lives left."));
            PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
            EndGame();
            return; 
        }
     }




         //check if isogram
    //check if rignt number of character *done
    //if
    //subtract lives
    //if lives > 1 prompt the player to enter word again
    //check life count
    //if the lives are < 0
    //print mission failed 
    //prompt user if he wants to try again
    //user inputs
    //if yes, will restart the game loop no, will quit the game
}