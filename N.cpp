/*

Этап 1.
Выполнил участник N.

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
    int a=30;
    while(a>0)
    {
        printf("Available: %d",a);
        int b;scanf("%d",&b);
        while(b<=1||b>=5)
        {
            printf("Invalid input.");
            scanf("%d",&b);
        }
        a=a-b;
    }
    printf("The end of the game. Left: %d",a);
}