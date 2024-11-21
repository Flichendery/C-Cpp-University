#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#ifdef USE_CUSTOM_MATH
int add(int a, int b);
int subtract(int a, int b);
#else
#include <cmath> // Стандартные математические функции
inline int add(int a, int b) { return a + b; }
inline int subtract(int a, int b) { return a - b; }
#endif

#endif // MATH_FUNCTIONS_H