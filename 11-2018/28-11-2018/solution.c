#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../handy/include/handy_string.h"

typedef struct _handy_tree * handy_tree;

struct _handy_tree
{
    char * data;
    handy_tree left;
    handy_tree right;
};

void in_order( handy_tree root );

handy_tree handy_create_tree(void * data, handy_tree left, handy_tree right )
{
    handy_tree  temp_tree = malloc( sizeof(*temp_tree) );
    temp_tree->data = data;

    temp_tree->right = right;
    temp_tree->left = left;

    return temp_tree;
}

handy_tree deserialize( handy_string  str );
char * serialize( handy_tree root );
void serialize_helper( handy_tree root, handy_string str, handy_string pos );

int main( int argc, char ** argv )
{
    handy_tree root = handy_create_tree( "root",
                                         handy_create_tree("left", handy_create_tree("left.left",NULL, handy_create_tree("left.left.right", NULL, NULL)), NULL),
                                         handy_create_tree("right",
                                                           NULL, handy_create_tree("right.right", NULL, NULL)));


    char * str = malloc( 1024 );

    printf("**Before Serializing:\n");
    in_order( root );
    strcpy(str, serialize(root) );

    handy_string de = handy_create_string();
    de->append( de, str );

    handy_tree back = deserialize( de );
    printf("**After Serializing:\n");
    in_order( back );
    return 0;

}

char * serialize( handy_tree root )
{
    handy_string str = handy_create_string();
    handy_string pos = handy_create_string();

    pos->append( pos, "" );
    serialize_helper( root, str, pos );

    str->del_front_char(str);
    str->add_char_back(str, '-');

    return str->string(str);

}
void serialize_helper( handy_tree root, handy_string str, handy_string pos )
{
    if( root == NULL )
        return;


    pos->add_char_front(pos, '-');
    pos->add_char_back(pos, '-');
    str->append(str, pos->string(pos) );
    str->append(str, root->data );
    pos->del_back_char(pos);
    pos->del_front_char(pos);

    pos->append(pos, "0");
    serialize_helper( root->left, str, pos );

    pos->del_back_char(pos);
    pos->append(pos, "1");
    serialize_helper( root->right, str, pos );
    pos->del_front_char(pos);
}
handy_tree deserialize( handy_string  str )
{
    handy_tree root = handy_create_tree( NULL,NULL,NULL );
    handy_tree root_head = handy_create_tree( NULL,NULL,NULL );

    memcpy( root_head, root, sizeof(*root) );

    handy_string pos = handy_create_string();
    pos->add_char_back( pos, '.' );

    bool read_node_value = true;
    char t = '0';
    while ( !str->is_null(str) )
    {
        root = root_head;
        t = str->get_front_char(str);
        handy_string temp_h = handy_create_string();

        if( t == '-' & read_node_value )
        {
            str->del_front_char(str);
            t = str->get_front_char(str);

            while( t != '-' )
            {
                temp_h->add_char_back(temp_h, t);

                str->del_front_char(str);
                t = str->get_front_char(str);
            }
            read_node_value = false;
            str->del_front_char(str);
            t = str->get_front_char(str);
        }
        else if( (t == '0' || t == '1') & !read_node_value )
        {
            while( t != '-' )
            {
                pos->add_char_back( pos, t );

                str->del_front_char(str);
                t = str->get_front_char(str);
            }
            read_node_value = true;
            t = str->get_front_char(str);
        }
        while( pos->length(pos) != 0 & read_node_value == false )
        {
            if( pos->get_front_char(pos) == '0' )
            {
                if( root->left == NULL )
                    root->left = handy_create_tree( NULL, NULL, NULL );
                root = root->left;
            }
            else if( pos->get_front_char(pos) == '1' )
            {
                if( root->right == NULL )
                    root->right = handy_create_tree( NULL, NULL, NULL );
                root = root->right;
            }
            pos->del_front_char( pos );
        }
        if( read_node_value == false )
        {
            if( root == NULL )
                root = handy_create_tree(NULL, NULL, NULL);
            root->data = malloc( temp_h->length );
            strcpy(root->data, temp_h->string(temp_h));
        }
    }

    return root_head;
}

void in_order( handy_tree root )
{
    if( root == NULL )
        return;
    printf( "%s\n", root->data );
    in_order( root->left );
    in_order( root->right );
}

