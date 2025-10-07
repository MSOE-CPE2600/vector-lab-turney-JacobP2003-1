/**
 * @file vectlist.h
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VECTLIST_H
#define VECTLIST_H

#include "Vect.h"

int isVectNull(Vect vect);

Vect getNullVect();

void initVects();

int addVect(Vect new_vect);

Vect getVect(char* vect_name);

void listVects();

void clearVects();

#endif /*VECTLIST_H*/