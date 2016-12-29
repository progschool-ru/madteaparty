/*

Этап 1.
Выполнил участник K.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Выполнил участник M.

Останавливаем игру, когда осталось неотрицательное число, но взять ничего нельзя.
Показываем, кто ходит: первый или второй.
Финальное поздравление, где написано кто выиграл: первый или второй. Выигрывает тот, кто последним ходил.


Этап 3.
Прислать до субботы 31 декабря 23:59

- Игрок не может взять больше, чем лежит в куче.
- В конфигурационном файле conf.txt задано сколько лежит в куче, min и max.
- Программа читает эту конфигурацию перед запуском и играет.
- Если конфигурация противоречива,
    выводим на экран информацию о том, что не понравилось,
    сразу после этого выходим


Известные проблемы:
На данный момент известных проблем нет.
Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.




*/

#include<stdio.h>

int main()
{
    int start = 30;
    int min = 2;
    int max = 4;

    int player_number=1;
    int current = start;
     printf("Course %d player\n",player_number);
    while (current>=min)
    {   
         int player_takes;
        printf("Available: %d\n", current);        
        scanf("%d", &player_takes);
        if (player_takes < min || player_takes > max)
        {
            printf("Invalid input. You can take any number >= %d and <= %d. Try again (%d <= X <= %d)\n", min, max, min, max);
             if (player_number==1)
            {
            printf("Course 1 player\n");
            }
            else 
            {    
                 printf("Course 2 player\n");
            }            
        }
        else
        {  
            current -= player_takes;
            if(current>=player_takes)
            {           
                if (player_number==1)
                {
                   player_number=player_number+1;
                }
                else 
                {
                    player_number=1;
                }
                 printf("Course %d player\n",player_number);
            }

        }
    }
    printf("The end of the game. Left: %d\n ", current);
    printf("%d player wins", player_number);
}
