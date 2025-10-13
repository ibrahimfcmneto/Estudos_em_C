#include <stdio.h>

int main()
{
    int valores[5] = {1,2,3,4,5};

    for(int i=0; i<5; i++)
    {
        printf("O valor %d tem %ld bytes\n", valores[i], sizeof(valores[i]));
    }

    printf("O array valores possui %ld bytes\n", sizeof(valores));

    printf("*(valores) vale: %d\n", *(valores));
    printf("*(valores+1) vale: %d\n", *(valores+1));

    
    return 0;
}