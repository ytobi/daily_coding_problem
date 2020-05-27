#include <stdio.h>
#include <stdlib.h>

int solution(char ** arr, int size, int * sol );

int main( int argc, char ** argv )
{

    if( argc < 2 )
    {
        printf("Usage %s [i...n]\n", __FILE__ );
        return 0;
    }

    // print out initial list
    printf("[");
    for( int i = 0; i < argc - 1; i++ )
        printf("%2s ", argv[i+1] );
    printf("]\n");

    // solve the problem
    int  sol[argc - 1];
    solution( argv, argc, sol );

    // print out the returned array
    printf("[");
    for( int i = 0; i < argc - 1; i++ )
        printf(" %2d ", sol[i] );
    printf("]\n");


    return 0;
}

int solution(char ** arr, int size, int * sol )
{
    int total_p = 1;
    // calculate total product of all input value
    for( int i = 1; i < size; i++ )
        total_p *= atoi(arr[i]);

    // divide total product by each number to exclude them
    for( int i = 1; i < size; i++ )
        sol[i-1] = total_p / atoi(arr[i] );

    return 0;
}
