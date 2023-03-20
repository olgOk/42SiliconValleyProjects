# 42-Project-Get-Next-Line

A C programming function that reads any valid file line by line until the end from a file descriptor.

### Contents
-------------------
* [What is get_next_line function](#What-is-get_next_line-function)
* [Why would I use get_next_line](#Why-would-I-use-get_next_line])
* [How to use get_next_line](#How-to-use-get_next_line)

### What is get_next_line function
--------------------------------------
get_next_line is an individual project at 42 Silicon Valley that teaches you how to open/write data in a file and manage memory leaks.

### Why would I use get-next-line
---------------------------------------
The goal is to get better at C, and understand memory management. You are allowed to use only three C Standard Library functions:

read
malloc
free

In additional, you are allowed to use functions from your personal C library.

> Essentially we had to recode the getline(3) C Standard Library function.

### How to use get_next_line
----------------------------------
Download/clone this repository.

Compile the ***libft***:

`make -C libft`

Build the executable:

`gcc -Wall -Wextra -Werror -I./libft/ -L./libft -lft -o gnl get_next_line.c your-main-function.c`

-I tells the compiler where your library header files are. In our case in `./libft/`

-L tells it where your library resides. In our case in  `./libft`

-l takes the name of your library. This is the set of characters that come after lib in your library name.

NOTE: -L and -l might look a little bit too much, you could replace those flags with libft/libft.a if you want.

Alright, the last command created a `gnl` executable in your directory. Now test it with:
`./gnl example-file.txt`

> It should read the whole file to you. Kinda like a basic cat implementation.

