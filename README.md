# MINIMAT: A Basic Terminal-based Matlab Analog
## Description:
A program that allows the user to do vector math on a list of stored vectors within the terminal.

## Compilation Command: 

    gcc -o minimat main.c console.c vectlist.c vectmath.c

## Command Line Arguments:
Run with `-h` to see full help page and list of commands

## Runtime Arguments:
### COMMANDS:
- `list` :
        
    Displays a list of all the vectors in memory to the console, with their x, y, and z values 
    
    Line Format: 
    
        [vectname] = [x] [y] [z]
- `clear`:
    
    Clears the vector memory.
- `quit` :
    
    Quits the program. (WARNING: vectors in memory will be lost!)
### VECTORS:
- Adding a new vector:
        
    Creates a new vector and adds it to memory. (Example: `vectname = x y z`)
- Displaying a vector:

    Displays the vector and its values. (Example: `vectname`)
### MATH:
- Addition `+`:

    Add the values of both vectors and store result. (Example: `vect1 = vect2 + vect3`)
- Subtraction `-`:
    
    Subtract the values of both vectors, and store result. 
    (Example: `vect1 = vect2 - vect3`)
- Scalar Multiplication(`* NUM`):

    Multiply all the values of the vector
by a decimal factor. (Example: `vect1 * 2`)
- Dot Product `*`:

    Multiply the values of both vectors, and store result. (Example: `vect1 = vect2 * vect3`)
- Cross Product `x`:
    
    Operation that gives a vector that is perpendicular to both vectors, with a magnitude equal to the product of both factor vectors' magnitudes. (Example: `vect1 = vect2 x vect3`)

## Dynamic Memory: 
The program doubles the amount of memory allocated for vectors whenever there would be an overflow.