#include <stdio.h>
#include <stdlib.h>

int *answer(int arr[], int size)
{
    int ansArr[size];

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0)
            {
                if (i != j)
                {
                    count++;
                }
            }
        }
        ansArr[i] = count;
    }

    return ansArr;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *ans = answer(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", &ans[i]);
    }
}