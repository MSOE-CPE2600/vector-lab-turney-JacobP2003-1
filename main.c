/**
 * @file main.c
 * @author Jacob Purcell (purcellj@msoe.edu)
 * @brief Main function for a program that allows the user to do vector math in
 *          the terminal
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <string.h>
 #include "console.h"

 int main(int argc, char* argv[]){
    if((argc > 1) && (!strcmp(argv[1], "-h"))){
        print_help();
    }else{
        int quit_flag;
        do {	//call the input parser in a loop until the input is "quit"
			quit_flag = parse_input();
		} while(quit_flag != 1);
    }
    return 0;
}
