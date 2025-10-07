/**
 * @file vectlist.c
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Vect.h"
#include "console.h"
#include <stdio.h>
#include <string.h>

#define MAX_VECTORS 10

Vect vects[MAX_VECTORS];
const Vect nullVect = {"", 0.0, 0.0, 0.0}; 

static void makeVectNull(Vect* vectpntr){
	strcpy(vectpntr->name, nullVect.name);
	vectpntr->x = nullVect.x;
	vectpntr->y = nullVect.y;
	vectpntr->z = nullVect.z;
}

int isVectNull(Vect vect){
	return ((!strcmp(vect.name,nullVect.name)) 
	&& (vect.x == nullVect.x) && (vect.y == nullVect.y) 
	&& (vect.z == nullVect.z));
}

Vect getNullVect(){
	return nullVect;
 }

void initVects(){
	for(int i = 0; i < (sizeof(vects)/sizeof(vects[0])); i++){
		makeVectNull(&(vects[i]));
	}
}

int addVect(Vect new_vect){
	int add_flag = 1;
	for(int i = 0; i < (sizeof(vects)/sizeof(vects[0])); i++){
		//Is vector in array null or the same name as newVect
		if((add_flag == 1) && (isVectNull(vects[i]) 
			|| !strcmp(vects[i].name, new_vect.name))){ 
			vects[i] = new_vect;
			add_flag = 0;
		}
	}
	return add_flag;
}

Vect getVect(char* vect_name){
	for(int i = 0; i < (sizeof(vects)/sizeof(vects[0])); i++){
		if(strcmp(vect_name, vects[i].name) == 0){
			return vects[i];
		}
	}
	return nullVect;
}

void listVects(){
	for(int i = 0; i < (sizeof(vects)/sizeof(vects[0])); i++){
		if(!isVectNull((vects[i]))){
			print_result(vects[i]);
		}
	}
}

void clearVects(){
	for(int i = 0; i < (sizeof(vects)/sizeof(vects[0])); i++){
			makeVectNull(&(vects[i]));
	}
}



// Vect* get_vect(char* name){
//     Vect* return_vect = NULL;
//     for(int i = 0; i <numVects; i++){
//         if(!strcmp(vectlist[i], name)){
//             return_vect = vectlist[i];
//         }
//     }
//     return return_vect;
// }

// int add_vect(char* name, double x, double y, double z){
//     int err_flag = 0;
//     if(!(numVects == MAX_VECTORS)){
//         if(!(get_vect(name) == NULL)){
//         vectlist[numVects] = ;
//         numVects++;
//         }
//     }else{
//         //Error, too many vects
//         err_flag = -1;
//     }
// }

// void clear_vects(){
//     for(int i = 0; i < MAX_VECTORS; i++){
//         vectlist[i] = NULL;
//     }
// }