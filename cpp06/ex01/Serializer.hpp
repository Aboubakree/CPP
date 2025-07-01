#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer();
    
public:
    // Static methods for serialization and deserialization
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
