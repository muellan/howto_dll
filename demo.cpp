
#include "mtm.h"


int main()
{
    constexpr int size1 = 1000;
    constexpr int size2 = 1000;

    auto input1 = new transformation_t[size1];
    auto input2 = new transformation_t[size2];


    do_great_things(input1, size1, input2, size2);    


    delete input1;
    delete input2;
}
