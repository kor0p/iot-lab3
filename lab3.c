#include <stdio.h>
#include <math.h>
#define size 5

void print_array(int array_to_print[size][size])
{
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
            printf ("%4d", array_to_print[row][column]);
        
        printf("\n");
    }
    printf("\n");
}
int* find_f_i(int input_array[size][size])
{
    // task was to find a f[i](a[i][j]) ¯\_(ツ)_/¯
    static int array[size-1] = {};
    for(int column = 1 ; column < size; column++)
        for(int row = 0 ; row < column; row++)
            array[row] += input_array[column][row];
    return array;
}
double find_F(int array[size][size])
{
    // task was to find a F( f[i](a[i][j]) ) ¯\_(ツ)_/¯
    int column;
    int* array_of_f = find_f_i(array);
    double multiplication = 1;

    printf("f:\n");
    for(column = 0; column < size-1; column++)
        printf("%4d",column);
    
    printf("\n  ");
    for(column = 0; column < size-2; column++)
        printf("————");
    
    printf("——\n");
    for(int column = 0; column < size-1; column++)
    {
        printf("%4d",array_of_f[column]);
        multiplication *= fabs(array_of_f[column]);
        // tutor said to get absolute value of result
        // to haven't problem with complex nums
    }
    return pow(multiplication,1.0/(size-1));
}
void sort_by_insertion(int array[size])
{
    for (int pointer = size-1; pointer >= 1; pointer--)
        for( int index = pointer; index < size && array[index-1] < array[index]; index++)
        {
            int temp = array[index];
            array[index] = array[index-1];
            array[index-1] = temp;
        }
}
void sort_rows(int array_to_sort[size][size])
{
    for (int row = 0; row < size; row++)
        sort_by_insertion(array_to_sort[row]);
}
int main()
{
    static int array[size][size];
    for (int row = 0; row < size; row++)
        for (int column = 0; column < size; column++)
        {
            printf("a.%d%d = ", row, column);
            scanf("%d", &a[row][column]);
        }
    printf("\n\n old array:\n");
    print_array(array);
    sort_rows(array);

    printf("\n new array:\n");
    print_array(array);
    printf("\n F: %lf \n",find_F(array));

    return 0;
}