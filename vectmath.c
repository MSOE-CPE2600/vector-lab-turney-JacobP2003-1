/**
 * @file vectmath.c
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Vect.h"

Vect vect_add(Vect a, Vect b){
    Vect result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vect vect_sub(Vect a, Vect b){
    Vect result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vect vect_dot(Vect a, Vect b){
    Vect result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return result;
}

Vect vect_cross(Vect a, Vect b){
    Vect result;
    result.x = (a.y * b.z) - (a.z * b.y);
    result.y = (a.z * b.x) - (a.x * b.z);
    result.z = (a.x * b.y) - (a.y * b.x);
    return result;
}

Vect vect_scal(Vect a, double scalar){
    Vect result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}