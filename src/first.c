#include "first.h"

float Derivative(float A, float deltaX) {
    return (f(A + deltaX) - f(A)) / deltaX;
}

float f(float x) {
    return cos(x);
}

float Pi(int k) {
    float pi = 0.0;
    int sign = 1;
    
    for (int i = 0; i < k; i++) {
        pi += sign * 4.0 / (2 * i + 1);
        sign *= -1;
    }

    return pi;
}