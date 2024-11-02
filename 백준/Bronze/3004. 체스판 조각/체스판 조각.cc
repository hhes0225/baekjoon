#include <stdio.h>
int main()
{
    int N, res;
    scanf("%d", &N);
    if (N % 2 == 0)
    {
        res = (N/2 + 1) * (N/2 + 1);
    }
    else
        res = ((N+1)/2) * ((N+3)/2); 
    printf("%d", res);
}