Brainfuck is the most famous esoteric programming language.
It operates on an array of memory cells. There are all initialized to 0 at the beginning. 
A pointer enables the program to work on that memory.

The language provides a few commands so we can work with it. The commands are the following:
* ">" Move the pointer to the right 
* "<" Move the pointer to the left
* "+" Increment the memory cell at the pointer
* "-" Decrement the memory cell at the pointer 
* "." Output the character signified by the cell at the pointer 
* "," Input a character and store it in the cell at the pointer 
* "[" Jump past the matching ] if the cell at the pointer is 0 
* "]" Jump back to the matching [ if the cell at the pointer is nonzero 

Source: https://esolangs.org/wiki/Brainfuck

To run this program, there are plenty of online interpreters as this one (https://copy.sh/brainfuck/)

======= INITIALISATION ========

+++++ +++++         Add to cell#0 the value 10
[                   Loop
    > +++++ ++          Add to cell#1 the value 7
    > +++++ +++++       Add to cell#2 the value 10
    > +++               Add to cell#3 the value 3
    > +                 Add to cell#4 the value 1
    
    <<<<-               Substract to cell#0 the value 2
]                   End loop

After this loop the memory cells are as follow:
| 0 | 70 | 100 | 30 | 10 | 0 | 0 | 0 | 0 | 0 | 0 | ...

======= PROGRAM =======

> ++ .                  Add 2 to cell#1 and print its content ("H")
> + .                   Add 1 to cell#2 and print its content ("e")
+++++ ++ .              Add 7 to cell#2 and print its content ("l")
.                       Print cell#2 content ("l")
+++ .                   Add 3 to cell#2 and print its content ("o")
> ++ .                  Add 2 to cell#3 and print its content (" ")

<< +++++ +++++ +++++ .  Add 15 to cell#1 and print its content ("W")
> .                     Print cell#2 content ("o")
+++ .                   Add 3 to cell#2 and print its content ("r")
------ .                Substract 6 to cell#2 and print its content ("l")
-------- .              Substract 8 to cell#2 and print its content ("d")
> + .                   Add 1 to cell#3 and print its content ("\n")
> .                     Print cell#4 content ("\0")

