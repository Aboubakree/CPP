#include "Serializer.hpp"

// Private constructor - prevents instantiation
Serializer::Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    // Use reinterpret_cast to convert pointer to uintptr_t
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    // Use reinterpret_cast to convert uintptr_t back to pointer
    return reinterpret_cast<Data*>(raw);
}