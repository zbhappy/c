#include <stdio.h>
#include<time.h>

#define N   8

void insert_odd(int i)
{
    int k = 0;
    int tmp;

    while((arr[k]%2) != 0 && arr[i] < arr[k])
    {
        k++;
    }
    tmp = arr[i];
    memmove(&arr[k+1], &arr[k], i-k);
    arr[k] = tmp;

}

void insert_even(int i)
{
    int j;
    int tmp;
    
    while((arr[k]%2) != 0 && arr[i] < arr[k])
    {
        k++;
    }
    tmp = arr[i];
    memmove(&arr[k+1], &arr[k], i-k);
    arr[k] = tmp;
}

#if 0
void print_t(int a[])
{
    int i = 0, j = 0, temp = 0;

    for(i = 0; i < N - 1; i++)
    {
        for(j = i + 1; j < N; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < N; i++)
    {
      printf("%d\n", a[i]);
    }

}
#endif
#if 0
void sort(int a[])
{
    int i = 0,temp = 0, j = N-1;
    for(i = 0; i < j; i++)
    {
        if((a[i]%2)== 0 )
        {

            while(j > i)
            {
                 if(((a[j])%(2)) != 0)
                 {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    j--;
                    break;
                 }
                 else
                 {
                    j--;
                 }
             
            }
          

        }
        if(j == i)
        {
            break;
        }
    
    }
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
#endif
int main(int argc, const char *argv[])
{
    int a[N] = {0};
    int i = 0, j = 0, num = 0;

    srand(time(NULL));

    while(i < N)
       {
            num = rand()%100;
            if(num >= 10)
            {
            for(j = 0; j < i; j++)
            {
                if(a[j] == num)
                {
                    --i;
                    break;
                }
            }
            if(j == i)
            {
                a[i] = num;
                ++i;
            }
            }
        }
    
   for (i = 0; i < 8; i++) 
   {
       if(arr[i] % 2 == 0)
            insert_even(i);
       else
        insert_odd(i);
   }
   printf("after sort, arr[] is:\n");
//   for (i = 0; i < 8; i++) 
 //  {
 //      printf("%d", a[i]);
  // }
   // print_t(a);
   // sort(a);

    return 0;
}
