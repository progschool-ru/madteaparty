/*

Этап 1.
Выполнил участник M.

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
    int b=30;
    printf("Left 30");
    printf("\n");
    while(b>0)
    {
    	int c;
    	scanf("%i",&c);
    	if(c!=2 && c!=3 && c!=4)
        {
        printf("wrong");
        printf("\n");
        }
    	else 
        {
        b=b-c;
    	printf("Left ");
    	printf("%i",b);
    	printf("\n");
        }
       
    }
    printf("The end");
}
