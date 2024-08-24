#include <cs50.h>
#include <stdio.h>

int getCoins(int amount);

int main(void)
{
    int m;
    do
    {
        m = get_int("Change owed: ");
    }
    while (m < 1);

    int coins = getCoins(m);
    printf("%i\n", coins);
}

int getCoins(int amount)
{
    int coins = 0;
    int values[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        while (amount >= values[i])
        {
            amount -= values[i];
            coins++;
        }
    }

    return coins;
}
