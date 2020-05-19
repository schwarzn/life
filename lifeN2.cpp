#include "stdio.h"
#include "windows.h"
int summa(int x, int y, int z, int a, int b, int c, int d, int e);
int massiv2(int c, int a);

int main()
{
    int n, m, i, j;
    int c = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n][m];
    int b[n][m];

    for(i = 0; i < n; i++)                //���������� �������
    {
        for(j = 0; j < m; j++)
        {
            a[i][j] = rand()%2;
        }
    }

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        system("cls");

        i = 0;                                           //������� ������� ������� ��� �����
        for(j = 1; j < m - 1; j++)
        {
            c = summa(a[n - 1][j - 1], a[n - 1][j], a[n - 1][j + 1],
                      a[i][j - 1]    , a[i][j + 1],
                      a[i + 1][j - 1], a[i + 1][j], a[i + 1][j + 1]);
            b[i][j] = massiv2(c, a[i][j]);
        }
        j = 0;                                                     //������� ����� ����
        c = summa(a[n - 1][m - 1], a[n - 1][j], a[n - 1][j + 1],
                  a[i][m - 1]    , a[i][j + 1],
                  a[i + 1][m - 1], a[i + 1][j], a[i + 1][j + 1]);
        b[i][j] = massiv2(c, a[i][j]);

        j = m - 1;                                                     //������� ������ ����
        c = summa(a[n - 1][m - 1], a[n - 1][j], a[n - 1][j + 1],
                  a[i][m - 1]    , a[i][j + 1],
                  a[i + 1][m - 1], a[i + 1][j], a[i + 1][j + 1]);
        b[i][j] = massiv2(c, a[i][j]);

        i = n - 1;                                       //������� ������ ������� ��� �����
        for(j = 1; j < m - 1; j++)
        {
            c = summa(a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1],
                      a[i][j - 1]    , a[i][j + 1],
                      a[0][j - 1]    , a[0][j]    , a[0][j + 1]);
            b[i][j] = massiv2(c, a[i][j]);
        }

        j = 0;                                           //������� ����� ������� ��� �����
        for(i = 1; i < n - 1; i++)
        {
            c = summa(a[i - 1][m - 1], a[i - 1][j], a[i - 1][j + 1],
                      a[i][m - 1]    , a[i][j + 1],
                      a[i + 1][m - 1], a[i][j], a[i + 1][j + 1]);
            b[i][j] = massiv2(c, a[i][j]);
        }

        j = m - 1;                                       //������� ������ ������� ��� �����
        for(i = 1; i < n - 1; i++)
        {
            c = summa(a[i - 1][j - 1], a[i - 1][j], a[0][0],
                      a[i][j - 1]    , a[i][0],
                      a[i + 1][j - 1], a[i + 1][j], a[i + 1][0]);
            b[i][j] = massiv2(c, a[i][j]);
        }

        for(i = 1; i < n - 1; i++)                       //������� �� ������� ��������
        {
            for(j = 1; j < m - 1; j++)
            {
                c = summa(a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1],
                          a[i][j - 1]    , a[i][j + 1],
                          a[i + 1][j - 1], a[i + 1][j], a[i + 1][j + 1]);
                b[i][j] = massiv2(c, a[i][j]);
            }
        }

        for(i = 0; i < n; i++)            //������ ������� �������
        {
            for(j = 0; j < m; j++)
            {
                if(b[i][j] == 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }

        for(i = 0; i < n; i++)            //������������ ����� ��������
        {
            for(j = 0; j < m; j++)
            {
                a[i][j] = b[i][j];
            }
        }

        Sleep(200);
    }
    return 0;
}

int summa(int x, int y, int z, int a, int b, int c, int d, int e)
{
    int k;
    k = x + y + z + a + b + c + d + e;
    return k;
}

int massiv2(int c, int a)
{
    int i, j, b;
    if(a == 0)
    {
        if(c == 3)
            b = 1;
        else
            b = 0;
    }
    else
    {
        if(c == 2 || c == 3)
            b = 1;
        else
            b = 0;
    }

    return b;
}
