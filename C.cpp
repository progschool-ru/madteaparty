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
Выполнил участник E.

- Комп старается выиграть:
    если может, ходит правильно,
    если не может, ходит как-то: какое-то допустимое число.
- В конфиге можно задать, кто первый, кто второй:
    комп, чел, два компа, два чела.


Этап 6.
Выполнил участник N.

- Тестируем, исправляем ошибки.
- Смотрим код, выискиваем потенциальные ошибки, тестируем, исправляем.
- Улучшаем пользовательский интерфейс на своё усмотрение, но оставляя его текстовым.


Этап 7.
Прислать до 22:00 вторника 10 января

- Избавьтесь от импорта ненужных библиотек.
- Тестируем, исправляем ошибки.
- Смотрим код, выискиваем потенциальные ошибки, тестируем, исправляем.
- Улучшаем пользовательский интерфейс на своё усмотрение, но оставляя его текстовым.


Известные проблемы:

- Обнаружил С.В. Исправил участник N:
    если конфигурационного файла нет, то падает с "Segmentation fault: 11"
- Обнаружил участник E. Исправил участник N:
    не реализован случай, когда играют 2 компа или 2 человека

Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.




*/



#include <fstream>
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
    srand(time(NULL));
       int n, min, max, player=1, a;
    FILE *f = fopen("conf.txt", "rt");
    fscanf(f, "%d%d%d%d", &n, &min, &max, &a);
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
        fprintf(w,"%d %d %d %d",b[0],b[1],b[2],2);
        fclose (w);
        n=b[0];
        min=b[1];
        max=b[2];
        a=2;
       }
    if (1 == check_config(n, min, max))
    {
        return 1;
    }
     

       
       
    printf("Left %d. Player %d", n, player);
    printf("\n");
    while (n >= min)
    {    
        if(player==2&&(a&2) || player==1&&(a&1))
        { 
             if (n%(min + max)>=max) 
             {
            int r=max;
             printf("%d", r);
             printf("\n");
             n=n-r;
             player = 3-player;
         }else if(n%(min + max)>=min){
            int r=n%(min + max);
             printf("%d", r);
             printf("\n");
             n=n-r;
             player = 3-player;
            }
            else
            {
            int r=0;
             r=rand()%(max-min+1)+min;
             printf("%d", r);
             printf("\n");
             n=n-r;
             player = 3-player;
            }
             
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
    printf("The end. The winner is player #%i\n", player);
    return 0;
}
