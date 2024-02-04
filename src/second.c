#include "second.h"

float Derivative(float A, float deltaX) {
    return (f(A + deltaX) - f(A - deltaX)) / (2.0*deltaX);
}

float f(float x) {
    return cos(x);
}

float Pi(int k) {
    float pi = 1.0;
    
    for (int i = 1; i <= k; i++) {
        pi *= 4.0*i*i / (4.0*i*i - 1);
    }

    return pi * 2;
}