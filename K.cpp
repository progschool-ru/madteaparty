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
Выполнил участник Е.

- Игрок не может взять больше, чем лежит в куче.
- В конфигурационном файле conf.txt задано сколько лежит в куче, min и max.
- Программа читает эту конфигурацию перед запуском и играет.
- Если конфигурация противоречива,
    выводим на экран информацию о том, что не понравилось,
    сразу после этого выходим


Этап 4.
Выполнил участник N.

- Если обнаружили, что файла нет, то создаём example файл с какой-то конфигурацией
- Второй игрок - комп. Ходит как-то: всегда какое-то допустимое число.


Этап 5.
Выполнил участник N.

- Комп старается выиграть:
    если может, ходит правильно,
    если не может, ходит как-то: какое-то допустимое число.
- В конфиге можно задать, кто первый, кто второй:
    комп, чел, два компа, два чела.


Этап 6.
Выполнил участник С.

- Тестируем, исправляем ошибки.
- Смотрим код, выискиваем потенциальные ошибки, тестируем, исправляем.
- Улучшаем пользовательский интерфейс на своё усмотрение, но оставляя его текстовым.


Этап 7.
Выполнил участник K.

- Тестируем, исправляем ошибки.
- Смотрим код, выискиваем потенциальные ошибки, тестируем, исправляем.
- Улучшаем пользовательский интерфейс на своё усмотрение, но оставляя его текстовым.


Известные проблемы:

- Обнаружил участник К. Исправил участник К.
    - Когда в последний ход оставалось меньше, чем брал ходивший игрок,
      программа не передавала ход следующему игроку.
    - Не было проверки на корректность конфигурации
    
Добавляйте сюда проблемы о которых вы знаете, но не смогли или не успели решить.




*/

#include<stdio.h>

bool check_config(int n, int min, int max)
{
    if (n <= 0)
    {
        printf("Total must be positive\n");
        return 0;
    }
    if (min <= 0)
    {
        printf("Min must be positive\n");
        return 0;
    }
    if (min > max)
    {
        printf("Min must not be greater than max\n");
        return 0;
    }
    return 1;
}

int main()
{
    int start,o;
    int min;
    int max;
    int k,l;
    FILE *f = fopen("conf.txt", "rt");
    if(f!=NULL)
    {
        fscanf(f, "%d%d%d%d%d", &start, &min, &max, &k, &l);
        fclose(f);
    }
    else
    {
        f=fopen("conf.txt","wt");
        start=30;min=1;max=2;k=0;l=1;
        fprintf(f,"%d %d %d %d %d", start, min, max,k,l);
        fclose(f);
    }

    if (!check_config(start, min, max))
    {
        return 1;
    }

    int player_number=1;
    int current = start;
    printf("You can take from %d up to %d. There is %d now \n",min,max,current);
    while (current>=min)
    {   
        int player_takes;
        printf("Available: %d\n", current);
        printf("Course %d player\n",player_number);

        if ((player_number==1 && !k) || (player_number == 2&&!l))
        {
            scanf("%d", &player_takes);
        }
        else
        {
            o=current%(min+max);
            player_takes=o<min?min:o>=max?max:o;
            printf("Player %d takes %d\n", player_number, player_takes);
        }

        if (player_takes < min || player_takes > max || player_takes>current)
        {
            printf("Invalid input. You can take any number >= %d and <= %d. Try again (%d <= X <= %d)\n", min, max, min, max);
            printf("Course %d player\n", player_number);
        }
        else
        {  
            current -= player_takes;
            if (player_number==1)
            {
               player_number=2;
            }
            else 
            {
                player_number=1;
            }
        }
    }
    printf("The end of the game. Left: %d\n ", current);
    printf("%d player wins", 3 - player_number);
}
