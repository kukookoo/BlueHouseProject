#include <stdio.h>
#include <stdlib.h>

int main()
{

    int card1, card2, hidden, temp;
	int seed_money = 1000, bet;
	char ans;

	do
	{
		system("cls");
		printf("Welcome to My Game!!!\n");
	    printf("Your seed money : %d\n", seed_money);

		card1 = rand() % 12 + 1;
		card2 = rand() % 12 + 1;

		printf(" Card1 : %d  |  Card2 : %d\n", card1, card2);
		
		
		printf("How much do you bet?");
        scanf("%d", &bet);

		hidden = rand() % 12 + 1;

		if (card1 > card2)
		{
		   temp =  card2;
		   card2 = card1;
		   card1 = temp;
		} 

		if ((card1 < hidden) && (hidden < card2))
		{
          seed_money += (bet*2);
	   	  printf("Hidden is %d : You got %d\n",hidden, bet*2); 
		  printf("Your seed money is %d\n", seed_money); 
		} 
		else
		{
	      seed_money -= bet;
		  printf("Hidden is %d : You lose %d\n",hidden, bet);
		  printf("Your seed money is %d\n", seed_money); 
		} 


		printf("Do you wanna continue (Y/N) :");
		scanf(" %c", &ans);

	} while (ans != 'N');
	
		return 0;
}
