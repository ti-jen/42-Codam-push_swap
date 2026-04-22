*This project has been created as part of the 42 curriculum by tkroon*

# libftprintf

a recreation of the printf function

## Description

the goal of this project was to recreate the printf function from "stdio.h". 
the project makes a static library with the fake printf function. 

The way I replicated printf is by taking a string of characters and printing each one until a % is encountered. When a % is found, the program checks the next character to determine the format specifier, and then retrieves and prints the corresponding data from the va_list using helper functions.

## Instructions
in this project you can use the Makefile to compile and create libftprintf.a.

### executing program
```
== executes the whole program ==
make all
== remmoves all object files ==
make clean
== removes all files created by the program ==
make fclean
== removes all files created by the program and re executes the program ==
make re
```

## Resources

https://pythontutor.com/visualize.html#mode=edit

https://stackoverflow.com/questions

https://www.rapidtables.com/convert/number/hex-to-decimal.html

https://github.com/paulo-santana/ft_printf_tester#

https://github.com/Tripouille/printfTester#

https://chatgpt.com/

### usage of AI

AI was used to explain consept that were new to me like va_, also explained what the reason was for certain outputs of printf and why it did that.