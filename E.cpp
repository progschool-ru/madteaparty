/*

Этап 1.
Выполнил участник E.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Выполнил участник С.

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
	int i=30,a;
	printf("Avalable 30\n");
	int curturn=1;
	while (i>1)
	{
		printf("%d", curturn);
		printf (" turn\n");

		scanf ("%d",&a);
		if (a==2||a==3||a==4)
		{
	    	i=i-a;
		    printf ("Avalable %d\n",i);
		    if(curturn==1) curturn=2;
		    else curturn=1;
	    }
	    else
		printf ("invalid input\n");
	}
	printf("The end ");
	printf("%d", curturn);
	printf(" wins");
}
