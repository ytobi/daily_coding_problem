#include <stdio.h>
#include "../../handy/include/handy_hashtbl.h"
#include "../../handy/include/handy_string.h"

char * dict[2][10] = {
        { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" },
        { "0-", "1-", "2-", "-3", "4-", "5-", "6-", "7-", "8-", "9-" } };

char * to_string( int num )
{

    handy_string ret = handy_create_string();

    int back = 0;
    while( num != 0 )
    {
        back = num % 10;

        if( back < 0 )
            ret->append(ret, dict[1][back*-1] );
        else
            ret->append(ret, dict[0][back] );

        num /= 10;
    }
    ret->reverse(ret);
    return ret->string(ret);
}
int solution( handy_hashtbl t );

int main( int argc, char ** argv )
{
    if( argc < 2 )
    {
        printf( "Usage: %s [list of numbers]\n", argv[0] );
        return 0;
    }

    handy_hashtbl table = handy_create_hashtbl();

    for( int i = 1; i < argc; i++ )
    {
        table->add( table, argv[i], argv[i] );
    }

    printf( "Missing Int: %d\n", solution(table) );

}

int solution( handy_hashtbl t )
{
    int missing_int = 1;

    while( 1 )
    {
        if( !t->contain( t, to_string(missing_int)) )
            return missing_int;
        missing_int++;
    }
}
