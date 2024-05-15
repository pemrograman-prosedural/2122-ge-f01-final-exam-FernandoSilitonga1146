#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm ( char *_name, unsigned short _capacity, gender_t _gender )
{
    

    Dorm.residents_num = 0;
    strcpy( Dorm.name, _name );
    Dorm.capacity = _capacity;
    Dorm.gender   = _gender;

    return dorm_;
}

void print_dorm (struct Dorm dorm_to_print )
{
    printf( "%s", dorm_to_print.name );

    ( dorm_to_print.gender == GENDER_MALE )?
        printf( "|%d|male\n", dorm_to_print.capacity ):
        printf( "|%d|female\n", dorm_to_print.capacity );

    fflush( stdout );    
}

void printDormDetails (struct Dorm dorm_to_print )
{
    printf( "%s|%d", dorm_to_print.name, dorm_to_print.capacity );

    ( dorm_to_print.gender == GENDER_MALE )?
        printf( "|male" ) : printf( "|female" );
    
    printf( "|%d\n", dorm_to_print.residents_num );

    fflush( stdout );  
}

short findDormIdx ( char* _name, struct Dorm *list, int length )
{
    for ( short i=0; i<length; i++ ) {
        if ( strcmp( list[i].name, _name ) == 0 )
            return i;
    }

    return -1;
}
