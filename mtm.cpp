/******************************************************************************
 *
 *
 * 
 ******************************************************************************/

#include <iostream>
#include "stuff.h"
#include "mtm.h"


/*****************************************************************************
 * 
 * API FUNCTIONS
 * 
 ******************************************************************************/
void MTM_CALL do_great_things(transformation_t* inarray1, int size1,
                              transformation_t* inarray2, int size2)
{
    std::cout << "hello from dll:\n"
              << "array1 @ " << inarray1 << " of size " << size1 << '\n'
              << "array2 @ " << inarray2 << " of size " << size2 << '\n'
              << "stuff : " << stuff(size1 + size2) << '\n'
              << std::flush;
}

