#include<stdio.h>
//quickSort(): partition() + iteration
void quickSort(int * a, int start, int end);
//partition(): compare + swap()
int partition(int * a, int start, int end);
//swap()
void swap(int * a, int i, int j);
//display()
void display(int * a, int num);
  
int main(void)
{
    int a[5] = {5,5,4,6,2};
    int num = sizeof(a)/sizeof(a[0]);

    display(a, num);
    quickSort(a, 0, 4);
    display(a, num);

    return 0;
}

void quickSort(int * a, int start, int end)
{
    if(start < end)
    {    
        int q = partition(a, start, end);
        quickSort(a, start, q-1);
        quickSort(a, q+1, end);}
}

int partition(int * a, int start, int end)
{
    int x = a[start];
    int i = start;
    int j = end + 1;

    while (1)
    {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i >= j)
            break;
        swap(a, i, j);
    }
    a[start] = a[j];
    a[j] = x;

    return j;
}

void swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void display(int * a, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
