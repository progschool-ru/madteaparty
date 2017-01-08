/*

Этап 1.
Выполнил участник M.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Выполнил участник K.

- Останавливаем игру, когда осталось неотрицательное число, но взять ничего нельзя.
- Показываем, кто ходит: первый или второй.
- Финальное поздравление, где написано кто выиграл: первый или второй. Выигрывает тот, кто последним ходил.


Этап 3.
Выполнил участник С.

- Игрок не может взять больше, чем лежит в куче.
- В конфигурационном файле conf.txt задано сколько лежит в куче, min и max.
- Программа читает эту конфигурацию перед запуском и играет.
- Если конфигурация противоречива,
    выводим на экран информацию о том, что не понравилось,
    сразу после этого выходим


Этап 4.
Выполнил участник E.

- Если обнаружили, что файла нет, то создаём example файл с какой-то конфигурацией
- Второй игрок - комп. Ходит как-то: всегда какое-то допустимое число.
- Исправить известные проблемы.


Этап 5.
Выполнил участник К.

- Комп старается выиграть:
    если может, ходит правильно,
    если не может, ходит как-то: какое-то допустимое число.
- В конфиге можно задать, кто первый, кто второй:
    комп, чел, два компа, два чела.


Этап 6.
Выполнил участник M.

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

- Обнаружил участник С, исправил участник E:
    Не успел потестить функции ввода/вывода из файла.
- Обнаружил С.В., исправил участник K:
    Не создаётся файл с какой-то конфигурацией если исходного файла нет.

Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.




*/

#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <time.h>


int humanTakes(int total, int min, int max)
{
    int c;
    scanf("%i",&c);
    return c;
}

int compTakes(int total, int min, int max)
{
    int rest = total % (min + max);
    if (rest < min)
    {
        rand();
        return rand() % max + min;
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
    
    int b,c,x;
    int max;
    int min;
    int playerIsComp[3];
    FILE *f = fopen("conf.txt", "rt");
    if (f != NULL)
    {
        fscanf(f, "%d%d%d%d%d", &b, &min, &max, &playerIsComp[1], &playerIsComp[2]);
        if(min>max) {printf("Wrong max or min"); return 0;}
        if(b<=min){printf("Wrong col"); return 0;}
        fclose(f);
    }
    else
    {
        srand(time(NULL));
        b = rand()%40+10;
        min = rand()%8+1;
        max = rand()%10+1;
        if(min>max)
        while(min>max)
        {
        min = rand()%8+1;
        max = rand()%10+1;
        }
         while(max>=b)
        {
        b = rand()%40+10;
        }
        
        playerIsComp[1] = rand()%2;
        playerIsComp[2] = rand()%2;
        f = fopen("conf.txt", "wt");
        fprintf(f, "%d\n%d %d\n%d %d\n", b, min, max, playerIsComp[1], playerIsComp[2]);
        fclose(f);
     }
    int player = 1;
    printf("Left %d. Player %d\n", b, player);
    while(b>=min)
    {
        if (1 == playerIsComp[player])
        {
            c = compTakes(b, min, max);
            printf("Comp takes %d\n",c);
        }
        else
        {
            c = humanTakes(b, min, max);
        }

        if (c < min || c > max || b-c<0)
        {
            printf("wrong");
            printf("\n");
        }
        else 
        {  
            b=b-c;
            player = (1 == player) ? 2 : 1;
            printf("Left %d. Player %d\n", b, player);
        }
    }
    player = (1 == player) ? 2 : 1;
    printf("The end. The winner is player #%d!\n", player);
}
