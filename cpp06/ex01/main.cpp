#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"


int main() {

    Data        *data = new Data;
    data->x = 10;
    uintptr_t   integer_ptr = Serializer::serialize(data);
    Data        *data_test = Serializer::deserialize(integer_ptr);
    data_test->printX();
    delete data_test;
    return 0;
}