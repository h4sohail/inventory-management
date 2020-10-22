# Inventory Management System
An inventory management system written in C

### Details
Author: Hamza Sohail

Purpose: Create a inventory mangement system using C for a school project

### Structure
Files:

I have seperated the functionality with these criteria:

- Client (related to the funcs that a user would interface with, such as buying and adding stock)

- Store (related to internal operations of the store such as memory allocation, initialization of the store)

- Utility (utility funcs used by either Store or Client internally, that a client does not interface with)

With each of them having their own header files for forward references

The structures are defined in "data_types.h"

The includes are in "includes.h"


### Usage
Compilation instructions:
You can run the compile.sh file I included or run this command
```
$ gcc -o app store_funcs.c client_funcs.c util_funcs.c interface.c main.c
```
After that run 
```
$ ./app
```
