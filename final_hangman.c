#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


void rules()
{
    printf("\nThe rules of Hangman are:\n");
    printf("A word will be randomized in your choice of genre\n");
    printf("You will have 5 lifes to guess a letter in that word\n");
    printf("If you guess all letter without losing 5 lifes. You WIN\n");
    printf("If you lose all 5 lifes. You LOSE\n");
    printf("ENJOY\n\n");
}

int genres()
{
    int ch;
    printf("Enter your genre\n");
    printf("1) Names\n");
    printf("2) Football\n");
    printf("3: Apps\n");
    printf("Enter a choice (1,2 or 3) : ");
    scanf("%d",&ch);
    if (ch == 1)
        return ch;
    else if (ch == 2)
        return ch;
	else if (ch == 3)
		return ch;
    else{
        printf("Invalid entry\n");
        printf("Try again\n");
        genres();
    }
}


void dead()
{
    printf("\t |----+    \n");
    printf("\t |    |    \n");
    printf("\t |    O    \n");
    printf("\t |   / \\   \n");
    printf("\t |    |    \n");
    printf("\t |   / \\    ");
}

void life_0()
{
    printf("\t |----+    \n");
    printf("\t |    \n");
    printf("\t |     \n");
    printf("\t |     \n");
    printf("\t |     \n");
    printf("\t |      ");
}

void life_1()
{
    printf("\t |----+    \n");
    printf("\t |    |\n");
    printf("\t |     \n");
    printf("\t |     \n");
    printf("\t |     \n");
    printf("\t |      ");
}

void life_2()
{
    printf("\t |----+    \n");
    printf("\t |    |    \n");
    printf("\t |    O    \n");
    printf("\t |     \n");
    printf("\t |     \n");
    printf("\t |       ");
}

void life_3()
{
    printf("\t |----+    \n");
    printf("\t |    |    \n");
    printf("\t |    O    \n");
    printf("\t |   / \\   \n");
    printf("\t |     \n");
    printf("\t |      ");
}

void life_4()
{
    printf("\t |----+    \n");
    printf("\t |    |    \n");
    printf("\t |    O    \n");
    printf("\t |   / \\   \n");
    printf("\t |    |    \n");
    printf("\t |     ");
}



void printing(int deaths){
	if (deaths == 5)
		life_0();
	if (deaths == 4)
		life_1();
	if (deaths == 3)
		life_2();
	if (deaths == 2)
		life_3();
	if (deaths == 1)
		life_4();
	if (deaths == 0)
		dead();
}



void game_func(char str[])
{
	int count = 0;
    int strsize = strlen(str);
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };	
	int loopIndex = 0;
	int reguessed = 0; 
	
	char guess[16];
    char letter_entered;

    while ( numCorrect < strsize ) {

		count++;

		printing(numLives);

		printf("\n\n");


	
		for(loopIndex = 0; loopIndex < strsize; loopIndex++) {

			if(letterGuessed[loopIndex] == 1) {
				printf("%c ", str[loopIndex]);				
			} 
            else {
				printf("_ ");
			}
		
		}	

		printf("\n\n");	



        printf("Number Correct So Far : %d\n",numCorrect);
        printf("Enter a guess letter:");
        scanf("%s",&guess[0]);
        
		
		letter_entered = guess[0];
		reguessed = 0; 
		
		printf("letterEntered:%c\n",letter_entered);
		
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < strsize; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				if(str[loopIndex] == letter_entered) {
					reguessed = 1; 
					break;
				} 
				continue;
			}
		
			if( letter_entered == str[loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
		
		if( oldCorrect == numCorrect && reguessed == 0) {
			numLives--;
			printf("Sorry, wrong guess\n");
            printf("\n\n");
			if (numLives == 0) {
				break;
			}
		}
        else if( reguessed == 1) {
			printf("Already Guessed!!\n");
		}
        else {
			printf("Correct guess :)\n\n\n");
		}
	
	}

    if (numLives == 0){
        dead();
        printf("\n\nSorry you lose, the word was: '%s'\n", str);	
	} 
    else {	
		printf("\nYOU WIN!!! :)\tThe word was '%s' \n",str);
	} 
	

}



int main()
{

	srand(time(NULL));

    char arr1[][20] = {"karthik","saran","arjun","aravind","sumukh"};
    char arr2[][20] = {"hazard","messi","ronaldo","kimmich","rashford"};
    char arr3[][20] = {"netflix", "amazon", "twitter", "whatsaap", "facebook"};

    int rand_num = rand() % 5;

	int ch2;
    char ch1, ch3;

    printf("\nWELCOME TO HANGMAN\n");
    printf("======================================\n");
    printf("Do you know how to play? (y/n) : ");
    scanf("%c",&ch1);

    if(ch1 == 'n')
        rules();

    printf("\n======================================\n");
    ch2 = genres();

	printf("\n\n");

    if (ch2 == 1)
        game_func(arr1[rand_num]);
    else if (ch2 == 2)
        game_func(arr2[rand_num]);
    else 
        game_func(arr3[rand_num]);
        
    
    printf("\nDo you want to play again?(1. yes/2. no) : ");
    scanf("%s",&ch3);

    if (ch3 == 1)
        main();
    else
        printf("Thank you");

    printf("\n");

    return 0;


}
