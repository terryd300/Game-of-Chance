//
//  HW2.c
//  
//
//  Created by Terry Delaney on 2/28/21.
//

#include "HW2.h"

int main()
{

    // Determine number of picks
    
    printf("\n\n");
    printf("How many numbers would you like to choose? ");
    scanf("%d", &picks);
    printf("\n");

    int choices [picks];

    // Obtain number choices
    
    for (int i = 0; i < picks; i++)
    {
        printf("Please enter a number between 0 and 255 for choice #%d: ", i + 1);
        scanf("%d", &choices[i]);
        
        while (choices [i] < 0 || choices [i] > 255)
        {
            printf("You did not enter a valid number.\n\nPlease enter a number between 0 and 255 for choice #%d: ", i + 1);
            scanf("%d", &choices[i]);
        }
        printf("\n");
    }

    // Sort choices
    
    while (swap != 0)
    {
        swap = 0;
        for (int j = 0; j < picks - 1; j++)
        {
            if (choices [j] > choices [j + 1])
            {
                swap = choices [j];
                choices [j] = choices [j + 1];
                choices [j + 1] = swap;
                swap = 1;
            }
        }
    }
    
    // Verify choices
    
    for (int k = 0; k < picks; k++)
    {
        printf("Choice #%d is: %d\n\n", k + 1, choices [k]);
    }
    
    // Determine winning number
    
    cpid = fork();
    
    if (cpid == 0)
    {
        // Code Executed by Child
        
        int result;
        
        srand(time(NULL));
        result = rand();
        
        exit(result);   // Wait for signals
    }
    
    else
    {
        // Code Executed by Parent
        
        do
        {
            w = waitpid (cpid, &wstatus, WUNTRACED | WCONTINUED);
            
            if (WIFEXITED(wstatus))
            {
                winner = WEXITSTATUS(wstatus);
            }
        }   while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        
    }
    
    printf("The winning number is: %d\n\n", winner);
    
    // Test for winner
    
    test = picks - 1;
    
    if (choices [test] < winner)
    {
        test = -1;
    }
    
    else if (choices [0] > winner)
    {
        test = 0;
        win = 1;
    }
    
    while (win == 0 && test != -1)
    {
        if (choices [test - 1] < winner)
        {
            win = 1;
        }
        
        else
        {
            test--;
        }
    }
    
    // Display Results
    

    
    if (win == 0)
    {
        printf("You did not pick any winning numbers.\n\n");
        printf("Therefore, the game is a tie.\n\n");
    }
    
    else
    {
        printf("CONGRATULATIONS!!!!  YOU ARE A WINNER!!!\n\n");
        printf("Your winning choice of %d is the winner!\n\n", choices [test]);
    }
    
    return 0;
}

