# Lab 1  Input/Output Library

Function | Definition
:--------|:----------
exit | Accepts an exit code and terminates current process
string_length | Accepts a pointer to a string and returns its length.
print_string | Accepts a pointer to a null-terminated string and prints it to stdout.
print_char | Accepts a character code directly as its first argument and prints it to stdout.
print_newline | Prints a character with code 0xA.
print_uint | Outputs an unsigned 8-byte integer in decimal format.
print_int | Output a signed 8-byte integer in decimal format.
read_char | Read one character from stdin and return it. If the end of input stream occurs, return 0.
read_word | Accepts a buffer address and size as arguments. Reads next word from stdin (skipping whitespaces7 into buffer). Stops and returns 0 if word is too big for the buffer specified; otherwise returns a buffer address. This function should null-terminate the accepted string.
parse_uint | Accepts a null-terminated string and tries to parse an unsigned number from its start. Returns the number parsed in rax, its characters count in rdx.
parse_int | Accepts a null-terminated string and tries to parse a signed number from its start. Returns the number parsed in rax; its characters count in rdx (including sign if any). No spaces between sign and digits are allowed.
string_equals | Accepts two pointers to strings and compares them. Returns 1 if they are equal, otherwise 0.
string_copy | Accepts a pointer to a string, a pointer to a buffer, and buffer’s length. Copies string to the destination. The destination address is returned if the string fits the buffer; otherwise zero is returned.
 # Lab 2 Dictionary
 
 The assignment will contain the following files:
 1. main.asm
 2. lib.asm
 3. dict.asm
 4. colon.inc
 
Follow these steps to complete the assignment:
1. Make a separate assembly file containing functions that you have already written
in the first assignment. We will call it lib.o.
Do not forget to mark all necessary labels global, otherwise they won’t be visible
outside of this object file!
2. Create a file colon.inc and define a colon macro there to create dictionary words.
This macro will take two arguments:

 * Dictionary key (inside quotes).
 * Assembly label name. Keys can contain spaces and other characters, which are not allowed in label names. Each entry should start with a pointer to the next entry, then hold a key as a nullterminated string. The content is then directly described by a programmer—for example, using db directives, as in the example shown in Listing 5-35.
3. Create a function find_word inside a new file dict.asm. It accepts two arguments:
(a) A pointer to a null terminated key string.
(b) A pointer to the last word in the dictionary. Having a pointer to the last word defined, we can follow the consecutive links to enumerate all words in the dictionary. 
find_word will loop through the whole dictionary, comparing a given key with each key in dictionary. If the record is not found, it returns zero; otherwise it returns record address.
4. A separate include file words.inc to define dictionary words using the colon
macro. Include it in main.asm.
5. A simple _start function. It should perform the following actions:
 * Read the input string in a buffer of maximum 255 characters long.
 * Try to find this key in dictionary. If found, print the corresponding value. If not,
print an error message

# Lab 3  Scalar Product &  Prime Number Checker
A scalar product of two vectors ![equation](https://latex.codecogs.com/gif.latex?(a_1,a_2...a_n)) and ![equation](https://latex.codecogs.com/gif.latex?(b_1,b_2...b_n)) is the sum

![equation](https://latex.codecogs.com/gif.latex?\sum&space;^n_{i=1}a_ib_i=a_1b_1&plus;a_2b_2&plus;...&plus;a_nb_n)

For example, the scalar product of vectors (1, 2, 3) and (4, 5, 6) is

![equation](https://latex.codecogs.com/gif.latex?1*4&plus;2*5&plus;3*6=4&plus;10&plus;18=32)

The solution should consist of
 * Two global arrays of int of the same size.
 * A function to compute the scalar product of two given arrays.
 * A main function which calls the product computations and outputs its results.

