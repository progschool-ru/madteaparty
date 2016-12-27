/*

Этап 1.
Выполнил участник K.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Прислать до 22:00 среды 28 декабря.

Останавливаем игру, когда осталось неотрицательное число, но взять ничего нельзя.
Показываем, кто ходит: первый или второй.
Финальное поздравление, где написано кто выиграл: первый или второй. Выигрывает тот, кто последним ходил.


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

    int current = start;
    while (current > 0)
    {
        printf("Available: %d\n", current);
        int player_takes;
        scanf("%d", &player_takes);
        if (player_takes < min || player_takes > max)
        {
            printf("Invalid input. You can take any number >= %d and <= %d. Try again (%d <= X <= %d)\n", min, max, min, max);
        }
        else
        {
            current -= player_takes;
        }
    }
    printf("The end of the game. Left: %d\n", current);
}
