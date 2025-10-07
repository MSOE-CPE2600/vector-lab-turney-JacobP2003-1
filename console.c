/**
 * @file console.c
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Vect.h"
#include "vectlist.h"
#include "vectmath.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 void print_help(){
    printf("%-34sHELP PAGE%34s\n\n","|","|");
	printf("COMMANDS:\n");
	printf("\t'list' :\n\
	\tDisplays a list of all the vectors in memory\n\
	\tto the console, with their x, y, and z values\n\
	\t(Line Format: '[vectname] = [x] [y] [z]')\n");
	printf("\t'clear':\n\
	\tClears the vector memory.\n");
	printf("\t'quit' :\n\
	\tQuits the program.\n\
	\t(WARNING: vectors in memory will be lost!)\n");
	printf("VECTORS:\n");
	printf("\tAdding a new vector:\n\
	\tCreates a new vector and adds it to memory.\n");
	printf("\t\t\t(Example: 'vectname = x y z')\n");
	printf("\tDisplaying a vector:\n\
	\tDisplays the vector and its values.\n");
	printf("\t\t\t(Example: 'vectname')\n");
	printf("MATH:\n");
	printf("\tAddition '+':\n\
	\tAdd the values of both vectors and store result.\n");
	printf("\t\t\t(Example: 'vect1 = vect2 + vect3')\n");
	printf("\tSubtraction '-':\n\
	\tSubtract the values of both vectors, and store result.\n");
	printf("\t\t\t(Example: 'vect1 = vect2 - vect3')\n");
	printf("\tScalar Multiplication('* NUM'):\n\
	\tMultiply all the values of the vector\n\
	\tby a decimal factor.\n");
	printf("\t\t\t(Example: 'vect1 * 2')\n");
	printf("\tDot Product '*':\n\
	\tMultiply the values of both vectors, and store result.\n");
	printf("\t\t\t(Example: 'vect1 = vect2 * vect3')\n");
	printf("\tCross Product 'x':\n\
	\tOperation that gives a vector that is perpendicular\n\
	\tto both vectors, with a magnitude equal to\n\
	\tthe product of both factor vectors' magnitudes.\n");
	printf("\t\t\t(Example: 'vect1 = vect2 x vect3')\n\n");
	printf("%-32sEND HELP PAGE%32s\n","|","|");
 }

 void print_result(Vect vect){
	printf("%s = %f %f %f\n", vect.name, vect.x, vect.y, vect.z);
 }

static int parse_command(char* arg){
	int cmd_flag = 0;
	if (strcmp(arg, "quit") == 0) {
		cmd_flag = 1;
		printf("Quitting Program...\n");
	} else { 
		if (strcmp(arg, "clear") == 0){
			clearVects();
			printf("Cleared Vector Store!\n");
			cmd_flag = 2;
		} else{
			if (strcmp(arg, "list") == 0){
				printf("Vector cache:\n");
				listVects();
				cmd_flag = 3;
			}
		}
	}
	return cmd_flag;
 }

static char identify_op(char* strOperator){
	char operator;
	if(strlen(strOperator) == 1){
		operator = strOperator[0];
	} else {
		operator = '\0';
	}
	return operator;
 }

 int parse_input(){
	int cmd_flag = 0;
	printf("minimat> ");
    char line[50];
    if (fgets(line, sizeof(line), stdin) == NULL) {
		printf("Invlaid input.\n");
	} else {
		strcpy(line, strtok(line, "\n"));
		char* token = strtok(line, " ");
		cmd_flag = parse_command(token);
		if(cmd_flag == 0){ //Not a command?
			Vect vect1 = getVect(token); //vect1 = token 1
			if(isVectNull(vect1)){
				strcpy(vect1.name, token);
			}
			char* operatortok = strtok(NULL, " ");
			if(operatortok != NULL){ //Next tok exists?
				token = strtok(NULL, " \n");
				Vect vect2 = getVect(token);
				Vect resultVect;
				switch(identify_op(operatortok)){
					//Assignment or operator
					case '=':
						if(!isVectNull(vect2) 
							&& (!isVectNull(getVect(vect2.name)))){
							operatortok = strtok(NULL, " ");
							token = strtok(NULL," \n");
							Vect vect3 = getVect(token);
							switch(identify_op(operatortok)){
								case '+':
									if((!isVectNull(vect3))
										&& (!isVectNull(getVect(vect3.name)))){
										Vect resultVect = vect_add(vect2, vect3);
										strcpy(resultVect.name, vect1.name);
										addVect(resultVect);
										print_result(resultVect);
									} else {
										printf("Error: Vector not found\n");
									}
									break;
								case '-':
									if((!isVectNull(vect3))
										&& (!isVectNull(getVect(vect3.name)))){
										Vect resultVect = vect_sub(vect2, vect3);
										strcpy(resultVect.name, vect1.name);
										addVect(resultVect);
										print_result(resultVect);
									} else {
										printf("Error: Vector not found\n");
									}
									break;
								case '*':
									if((!isVectNull(vect3))
										&& (!isVectNull(getVect(vect3.name)))){
										Vect resultVect = vect_dot(vect2, vect3);
										strcpy(resultVect.name, vect1.name);
										addVect(resultVect);
										print_result(resultVect);
									} else {
										Vect resultVect = vect_scal(vect2, 
										atof(token));
										strcpy(resultVect.name, vect1.name);
										addVect(resultVect);
										print_result(resultVect);
									}
									break;
								case 'x':
									if((!isVectNull(vect3))
										&& (!isVectNull(getVect(vect3.name)))){
										Vect resultVect = vect_cross(vect2, vect3);
										strcpy(resultVect.name, vect1.name);
										addVect(resultVect);
										print_result(resultVect);
									} else {
										printf("Error: Vector not found\n");
									}
									break;
								default: 
									printf("Error: Unknown operator\n");
							}
						} else {	
							//Assignment or scalar op
							Vect resultVect;
							double tempval = atof(token);
							token = strtok(NULL, " \n");
							if(strcmp(token, "*") == 0){
								token = strtok(NULL, " ");
								vect2 = getVect(token);
								resultVect = vect_scal(vect2, tempval);
								strcpy(resultVect.name, vect1.name);
								addVect(resultVect);
								print_result(resultVect);
							} else{
								if(strcmp(token, "+") && strcmp(token, "-")
									&& strcmp(token, "x")){
									resultVect = getNullVect();
									resultVect.x = tempval;
									resultVect.y = atof(token);
									token = strtok(NULL, " ");
									resultVect.z = atof(token);
									strcpy(resultVect.name, vect1.name);
									addVect(resultVect);
									print_result(resultVect);
								} else {
									printf("Error: Vector not found\n");
								}
							}
						}
						break;
					//No assignment
					case '*':
						if((!isVectNull(vect2))
							&& (!isVectNull(getVect(vect2.name)))){
							resultVect = vect_dot(vect1, vect2);
							strcpy(resultVect.name, "ans");
							print_result(resultVect);
						} else {
							printf("Error: Unknown vector \"%s\"\n", token);
						}
						break;
					case '+':
						if((!isVectNull(vect2))
							&& (!isVectNull(getVect(vect2.name)))){
							resultVect = vect_add(vect1, vect2);
							strcpy(resultVect.name, "ans");
							print_result(resultVect);
						} else {
							printf("Error: Unknown vector \"%s\"\n", token);
						}
						break;
					case '-':
						if((!isVectNull(vect2))
							&& (!isVectNull(getVect(vect2.name)))){
							resultVect = vect_sub(vect1, vect2);
							strcpy(resultVect.name, "ans");
							print_result(resultVect);
						} else {
							printf("Error: Unknown vector \"%s\"\n", token);
						}
						break;
					case 'x':
						if((!isVectNull(vect2))
							&& (!isVectNull(getVect(vect2.name)))){
							resultVect = vect_cross(vect1, vect2);
							strcpy(resultVect.name, "ans");
							print_result(resultVect);
						} else {
							printf("Error: Unknown vector \"%s\"\n", token);
						}
						break;
					default:
						printf("Error: Unknown operator \"%s\"\n", token);
				}
			} else { //If there is only one token in the line
				if((!isVectNull(vect1)) && (!isVectNull(getVect(vect1.name)))){ 
					//If the vector exists
					print_result(vect1); //Display vector and values to console
				} else {
					printf("Error: Vector not found.\n");
				}
			}
		}
		while(token != NULL){ //Clear the rest of the tokens
			token = strtok(NULL," ");
		}
	}
	return cmd_flag;
 }