// my comment
#include <stdio.h>
#include <math.h>
#define n 5

void arrayout(const char* s, int a[n][n])
{
    printf("\n%s",s);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf ("%4d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int* f(int a[n][n])
{
    static int array[n-1] = {0};
    for(int j = 1 ; j < n; j++)
    for(int i = 0 ; i < j; i++)
    array[i] += a[j][i];
    return array;
}
double F(int a[n][n])
{
    int* ar = f(a);
    double res = 1;
    printf("f:\n");
    for(int k = 0; k < n-1; k++)
        printf("%4d",k);
    printf("\n  ");
    for(int k = 0; k < n-2; k++)
        printf("————");
    printf("——\n");
    for(int i = 0; i < n-1; i++)
    {
        printf("%4d",ar[i]);
        res *= fabs(ar[i]);
    }
    res = pow(res,1.0/(n-1));
    return res;
}
void sort_insertion(int a[n])
{
    for (int c = n-1; c >= 1; c--)
    {
        int d=c;
        while ( d < n && a[d-1] < a[d])
        {
            int t  = a[d];
            a[d]   = a[d-1];
            a[d-1] = t;
            d++;
        }
    }
}
void array_of_sorted_arrays(int a[n][n])
{
    for (int i = 0; i < n; i++)
        sort_insertion(a[i]);
}
main()
{
    static int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a.%d%d = ", i, j);
            scanf("%d", &a[i][j]);
        }
    arrayout("\nold array:\n",a);
    array_of_sorted_arrays(a);
    arrayout("new array:\n",a);
    printf("\n\nF: %lf\n",F(a));
}