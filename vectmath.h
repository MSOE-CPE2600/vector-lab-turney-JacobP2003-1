/**
 * @file vectmath.h
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #ifndef VECTMATH_H
 #define VECTMATH_H

 Vect vect_add(Vect a, Vect b);

 Vect vect_sub(Vect a, Vect b);

 Vect vect_dot(Vect a, Vect b);

 Vect vect_cross(Vect a, Vect b);

 Vect vect_scal(Vect a, double scalar);

 #endif /*VECTMATH_H*/