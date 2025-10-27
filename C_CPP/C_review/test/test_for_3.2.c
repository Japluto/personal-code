#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand((unsigned)time(NULL));
    int i = rand() % 100 + 1;
    int guess;
    printf("Let's guess a number between 1 and 100: ");
    scanf("%d", &guess);
    while (guess != i)
    {
        /* code */
        if (guess > i)
        {
            printf("Too big! Try again: ");
            scanf("%d", &guess);
        }
        else
        {
            printf("Too small! Try again: ");
            scanf("%d", &guess);
        }
    }
    printf("Congratulations! You guessed it right!\n");
    printf("The numeber is %d", i);
    return 0;
}
