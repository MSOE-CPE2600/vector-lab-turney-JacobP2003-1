/**
 * @file Vect.h
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VECTS_H
#define VECTS_H
#define NAME_LENGTH 10

typedef struct Vect{
    char name[NAME_LENGTH];
    double x;
    double y;
    double z;
}Vect;

#endif /*VECTS_H*/