#include <cs50.h>
#include <stdio.h>

void makePyramid(int height);

int main(void)
{
    int h;

    do
    {
        h = get_int("Height? ");
    }

    while (h < 1);

    makePyramid(h);
}

void makePyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int spaces = (height - i) - 1;
        int hashes = (height - spaces) - 1;

        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= hashes; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// void makePyramid(int height)
// {
//     for (int i = 0; i < height; i++)
//     {

//         for (int j = 0; j < height ; j++)
//         {
//              int noOfSpaces = height - j;
//              int noOfHash = height - noOfSpaces;

//             for ( int k = 0; k <= noOfSpaces ; k++)
//             {
//             printf(" ");
//             }
//             for (int l = 0; l <= noOfHash; l++)
//             {
//                 printf("#");
//             }
//             printf("\n");
//         }
//     }
// }

// void makeGrid(int size )
// {
//      for (int i = 0; i < size; i++)
//     {

//         for( int j = 0; j < size; j++ )
//         {
//             printf("o");
//         }
//         printf("\n");
//     }
// }
