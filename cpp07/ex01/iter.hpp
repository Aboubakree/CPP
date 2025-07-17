#pragma once


template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

template <typename T>
void print(T& element) {
    std::cout << element << " ";
}

template <typename T>
void increment(T& element) {
    element++;
}