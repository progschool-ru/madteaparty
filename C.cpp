/*

Этап 1.
Выполнил участник С.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Выполнил участник N.

Останавливаем игру, когда осталось неотрицательное число, но взять ничего нельзя.
Показываем, кто ходит: первый или второй.
Финальное поздравление, где написано кто выиграл: первый или второй. Выигрывает тот, кто последним ходил.


Этап 3.
Выполнил участник К.

- Игрок не может взять больше, чем лежит в куче.
- В конфигурационном файле conf.txt задано сколько лежит в куче, min и max.
- Программа читает эту конфигурацию перед запуском и играет.
- Если конфигурация противоречива,
    выводим на экран информацию о том, что не понравилось,
    сразу после этого выходим

Этап 4.
Выполнил участник M.

- Если обнаружили, что файла нет, то создаём example файл с какой-то конфигурацией
- Второй игрок - комп. Ходит как-то: всегда какое-то допустимое число.


Этап 5.
Прислать до 22:00 четверга 5 января

- Комп старается выиграть:
    если может, ходит правильно,
    если не может, ходит как-то: какое-то допустимое число.
- В конфиге можно задать, кто первый, кто второй:
    комп, чел, два компа, два чела.


Известные проблемы:

- Обнаружил С.В.:
    если конфигурационного файла нет, то падает с "Segmentation fault: 11"

Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.




*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool check_config(int n, int min, int max)
{
    if (n < max)
    {
        printf("Max must not be greater than Left\n");
        return 1;
    }
    if (n <= min)
    {
        printf("Min must not be greater than Left\n");
        return 1;
    }
    if (n <= 0)
    {
        printf("Must be a natural number\n");
        return 1;
    }
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

int main()
{   
    
       int n, min, max;
    FILE *f = fopen("conf.txt", "rt");
    fscanf(f, "%d%d%d", &n, &min, &max);
    fclose(f);
    if (f == NULL)
     { 
       int b[3];
       srand(time(NULL));
       for(int i=0;i<3; i=i+1)
       {
       b[i]=rand()%49+1;
       }
       FILE *w = fopen("conf.txt", "wb");
        fprintf(w,"%d %d %d",b[0],b[1],b[2]);
        fclose (w);
        n=b[0];
        min=b[1];
        max=b[2];
       }
    if (1 == check_config(n, min, max))
    {
        return 1;
    }
     

       
       
    int player = 1;
    printf("Left %d. Player %d", n, player);
    printf("\n");
    while (n >= min)
    {    
        if(player==2)
        {            
             int r=0;
             srand(time(NULL));
             r=rand()%(max-min+1)+min;
             printf("%d", r);
             printf("\n");
             n=n-r;
             player = 1;
             
        }
        else
        {
        int cur;
          scanf("%i",&cur);
          
        if (cur < min || cur > max || cur > n)
        {
            printf("wrong\n");
        }
        else
        {
            n = n - cur;
            player = 3 - player;
        }
       
        
        }
          
        printf("Left %d. Player %d\n", n, player);
    }
    player = 3 - player;
    printf("The end. The winner is player #%i", player);
    return 0;
}
