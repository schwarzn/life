#include "stdio.h"
#include "windows.h"

int main()
{
    int n, i;
    FILE *Fin, *Fout;
    Fin = fopen("nomer1.txt", "r");
    Fout = fopen("nomer2.txt", "w");

    if(Fin == NULL)
    {
        printf("cannot open file \n");
        return 1;
    }

    fscanf(Fin, "%d", &n);
    int a[n];
    int b[n];

    for(i = 0; i < n; i ++)
    {
        fscanf(Fin, "%d", &a[i]);
    }
    for(i = 0; i < n; i++)
        {
            if(a[i] == 0)
                printf(" ");
            else
                printf("*");
        }

    while(!GetAsyncKeyState(VK_ESCAPE))
    {

        if(a[0] == 0)
        {
            if(a[n-1] == 1 || a[1] == 1)
                b[0] = 1;
            else
                b[0] = 0;
        }
        else
        {
            if((a[n-1] == 0 && a[1] == 0) || (a[n-1] == 1 && a[1] == 1))
                b[0] = 0;
            else
                b[0] = 1;
        }

        for(i = 1; i < n - 1; i++)
        {
            if(a[i] == 0)
            {
                if(a[i+1] == 1 || a[i-1] == 1)
                    b[i] = 1;
                else
                    b[i] = 0;
            }
            else
            {
                if((a[i-1] == 0 && a[i+1] == 0) || (a[i-1] == 1 && a[i+1] == 1))
                    b[i] = 0;
                else
                    b[i] = 1;
            }
        }

        if(a[n-1] == 0)
        {
            if(a[n-2] == 1 || a[0] == 1)
                b[n-1] = 1;
            else
                b[n-1] = 0;
        }
        else
        {
            if((a[n-2] == 0 && a[0] == 0) || (a[n-2] == 1 && a[0] == 1))
                b[n-1] = 0;
            else
                b[n-1] = 1;
        }

        printf("\n");
        if(b[0] == 0)
            printf(" ");
        else
            printf("*");
        for(i = 1; i < n; i++)
        {
            if(b[i] == 0)
                printf(" ");
            else
                printf("*");
        }

        for(i = 0; i < n; i++)
        {
            a[i] = b[i];
        }

        Sleep(900);
    }

    fprintf(Fout, "%d \n", n);
    for(i = 0; i < n; i++)
    {
        fprintf(Fout, "%d ", a[i]);
    }

    fclose(Fin);
    fclose(Fout);
}
