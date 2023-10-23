// POPULATION GROWTH: https://cs50.harvard.edu/x/2023/labs/1/

#include <cs50.h>
#include <stdio.h>

#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years

    int startsize, endsize, years = 0;

  do
  {
      printf("\nStar size: ");
      scanf("%d", &startsize);
  }
  while (startsize < 9);

  do
  {
      printf("\nEnd size: ");
      scanf("%d", &endsize);
  }
  while (endsize < startsize);

  while (startsize < endsize)
  {
     startsize += ceil((startsize / 3) - (startsize / 4));
     years++;
  }
  printf("\nYears: %d\n", years);

    return 0;

}
