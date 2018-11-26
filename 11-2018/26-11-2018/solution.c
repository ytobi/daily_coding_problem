#include <stdio.h>
#include "../../handy/include/handy_hashtbl.h"

int main( int argc, char ** argv )
{
    // require at least 3 list of numbers
    if( argc < 3 )
    {
        printf( "Usage: %s [k][list of numbers]\n", __FILE__ );
        return 0;
    }

    handy_hashtbl numbers_hash = handy_create_hashtbl();
    handy_list numbers_list = handy_create_list();

    // the first number is the one which we test if two numbers
    // in the rest of list add up to k.
    // the first number is k
    char * k = argv[1];

    // read in the numbers in a list and hash table
    for( int i = 2; i < argc; i++ )
    {
        numbers_hash->add( numbers_hash, argv[i], atoi(argv[i]) );
        numbers_list->add_back( numbers_list, argv[i] );
    }

    // One time pass through list to check if two numbers add up to k
    // Check in hash table if number add up( a "complement" )
    for( int i = 0; i < numbers_list->length(numbers_list); i++ )
    {
        char * current_number = numbers_list->get_at(numbers_list, i);

        int add_up = atoi( k ) - atoi( current_number );
        add_up += '0'; // we need string value(aka ascii value)

        if( numbers_hash->get(numbers_hash, &add_up) )
        {
            // yes, found two numbers that add up to k, print them
            printf( "YES!, %d, %s adds to %s\n", atoi( current_number ), &add_up, k );
            return 0;
        }
    }

    printf( "NO!, no two numbers add up to %s\n", k );

    return 0;
}
