// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int length = n;
    int maior;
    //sorting the list from in decendent order
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        }
    }
    //returning the first element from the ordered list
    return array[0];
}
