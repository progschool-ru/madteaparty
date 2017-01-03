/*

Этап 1.
Выполнил участник N.

- Показывает пользователю сколько осталось
- Запрашивает число
- Уменьшает сколько осталось и так далее
- Выходит, когда ничего не останется
- Нельзя ходить меньше чем 2 и больше чем 4


Этап 2.
Выполнил участник E.

Останавливаем игру, когда осталось неотрицательное число, но взять ничего нельзя.
Показываем, кто ходит: первый или второй.
Финальное поздравление, где написано кто выиграл: первый или второй. Выигрывает тот, кто последним ходил.


Этап 3.
Выполнил участник М.

- Игрок не может взять больше, чем лежит в куче.
- В конфигурационном файле conf.txt задано сколько лежит в куче, min и max.
- Программа читает эту конфигурацию перед запуском и играет.
- Если конфигурация противоречива,
    выводим на экран информацию о том, что не понравилось,
    сразу после этого выходим


Этап 4.
Выполнил участник K.

- Если обнаружили, что файла нет, то создаём example файл с какой-то конфигурацией
- Второй игрок - комп. Ходит как-то: всегда какое-то допустимое число.
- Исправить известные проблемы.


Этап 5.
Прислать до 22:00 четверга 5 января

- Комп старается выиграть:
    если может, ходит правильно,
    если не может, ходит как-то: какое-то допустимое число.
- В конфиге можно задать, кто первый, кто второй:
    комп, чел, два компа, два чела.


Известные проблемы:

- Обнаружил С.В. Исправил участник K.
    не читает из конфига общее количество камней.

Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.



*/

#include<stdio.h>

int humanTakes(int current, int min, int max) {
    int takes;
    scanf("%d", &takes);
    return takes;
}

int compTakes(int current, int min, int max) {
    return min;
}

int main()
{
    int start,c=1,player;
    int min;
    int max;
    FILE *f;
    f=fopen("conf.txt","rt");
    if (f != NULL)
    {
        fscanf(f,"%d%d%d", &start, &min, &max);
        fclose(f);
    }
    else
    {
        start = 30;
        min = 1;
        max = 2;
        f = fopen("conf.txt", "wt");
        fprintf(f, "%d %d %d\n", start, min, max);
        fclose(f);
    }

    if(min>max  ||  min<=0  || max<=0)
    {
        printf("Error in file");
        return 1;
    }

    int current = start;
    while(current>=min)
    {
        player = c % 2 == 1 ? 1 : 2;
        printf("Available: %d\n",current);
        int b;
        printf ("Turn player %d: ",player);
        b = player == 1 ? humanTakes(current, min, max) : compTakes(current, min, max);
        while (b<min || b>max || current<b)
        {
            printf("Invalid input.\n");
            printf ("Turn player %d: \n",player);
            b = player == 1 ? humanTakes(current, min, max) : compTakes(current, min, max);
        }
        current = current - b;
        c++;
    }
    printf("The end of the game. Left: %d. %d player win!", current, player);
}
