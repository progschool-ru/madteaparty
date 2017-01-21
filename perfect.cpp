#include <stdio.h>
#include <cstdlib>

bool check_config(int n, int min, int max)
{
    if (min <= 0)
    {
        printf("Min must not be negative\n");
        return 1;
    }
    if (max <= 0)
    {
        printf("Max must be positive\n");
        return 1;
    }
    if (min > max)
    {
        printf("Min must not be greater than max\n");
        return 1;
    }
    return 0;
}

int humanTakes(int current, int min, int max)
{
    int takes;
    scanf("%d", &takes);
    return takes;
}

int compTakes(int current, int min, int max)
{
    int rest = current % (min + max);
    if (rest < min)
    {
        rand();
        return min + rand() % max;
    }
    else if (rest >= max)
    {
        return max;
    }
    else
    {
        return rest;
    }
}

int main()
{
    int start;
    int min;
    int max;
    int playerIsComp[3];

    FILE *confFile = fopen("conf.txt", "rt");
    if (confFile != NULL)
    {
        fscanf(confFile,"%d%d%d%d%d", &start, &min, &max, &playerIsComp[1], &playerIsComp[2]);
        fclose(confFile);
    }
    else
    {
        start = 30;
        min = 1;
        max = 2;
        confFile = fopen("conf.txt", "wt");
        playerIsComp[1] = 0;
        playerIsComp[2] = 1;
        fprintf(confFile, "%d %d %d %d %d\n", start, min, max, playerIsComp[1], playerIsComp[2]);
        fclose(confFile);
    }   
    if (1 == check_config(start, min, max))
    {
        return 1;
    }

    int player = 1;
    int current = start;
    while (current >= min)
    {
        printf("Available: %d. Player %d\n", current, player);
        printf("You can take any number >= %d and <= %d\n", min, max);
        int player_takes;
        if (0 == playerIsComp[player]) {
            player_takes = humanTakes(current, min, max);
        } else {
            player_takes = compTakes(current, min, max);
            printf("Comp takes %d\n", player_takes);
        }

        if (player_takes < min || player_takes > max || current < player_takes)
        {
            printf("Invalid input. You can take any number >= %d and <= %d. Try again (%d <= X <= %d)\n", min, max, min, max);
        }
        else
        {
            current -= player_takes;
            player = (1 == player) ? 2 : 1;
        }
    }
    player = (1 == player) ? 2 : 1;
    printf("The end of the game. Left: %d.\n The winner is player #%d!\n", current, player);
}