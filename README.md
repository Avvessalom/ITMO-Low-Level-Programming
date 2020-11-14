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
## Scalar Product
A scalar product of two vectors ![equation](https://latex.codecogs.com/gif.latex?(a_1,a_2...a_n)) and ![equation](https://latex.codecogs.com/gif.latex?(b_1,b_2...b_n)) is the sum

![equation](https://latex.codecogs.com/gif.latex?\sum&space;^n_{i=1}a_ib_i=a_1b_1&plus;a_2b_2&plus;...&plus;a_nb_n)

For example, the scalar product of vectors (1, 2, 3) and (4, 5, 6) is

![equation](https://latex.codecogs.com/gif.latex?1*4&plus;2*5&plus;3*6=4&plus;10&plus;18=32)

The solution should consist of
 * Two global arrays of int of the same size.
 * A function to compute the scalar product of two given arrays.
 * A main function which calls the product computations and outputs its results.
 
## Prime Number Checker
You have to write a function to test the number for primarity. The interesting thing is that the number will be
of the type unsigned long and that it will be read from stdin.
 * You have to write a function int is_prime( unsigned long n ), which checks whether n is a prime number or not. If it is the case, the function will return 1; otherwise 0.
 * The main function will read an unsigned long number and call is_prime function on it. Then, depending on its result, it will output either yes or no.

# Lab 4 Linked List & Higher-Order Functions and Lists

## Linked List

The program accepts an arbitrary number of integers through stdin. What you have to do is
1. Save them all in a linked list in reverse order.
2. Write a function to compute the sum of elements in a linked list.
3. Use this function to compute the sum of elements in the saved list.
4. Write a function to output the n-th element of the list. If the list is too
short, signal about it.
5. Free the memory allocated for the linked list.

You need to learn to use

* Structural types to encode the linked list itself.
* The EOF constant. Read the section “Return value” of the man scanf.

You can be sure that

* The input does not contain anything but integers separated by whitespaces.
* All input numbers can be contained into int variables.

Following is the recommended list of functions to implement:

* list_create – accepts a number, returns a pointer to the new linked list node.
* list_add_front – accepts a number and a pointer to a pointer to the linked list.
Prepends the new node with a number to the list.

For example: a list (1,2,3), a number 5, and the new list is (5,1,2,3).

* list_add_back, adds an element to the end of the list. The signature is the same as
list_add_front.
* list_get gets an element by index, or returns 0 if the index is outside the list bounds.
* list_free frees the memory allocated to all elements of list.
* list_length accepts a list and computes its length.
* list_node_at accepts a list and an index, returns a pointer to struct list,
corresponding to the node at this index. If the index is too big, returns NULL.
* list_sum accepts a list, returns the sum of elements.

These are some additional requirements:

* All pieces of logic that are used more than once (or those which can be conceptually
isolated) should be abstracted into functions and reused.
* The exception to the previous requirement is when the performance drop is becoming
crucial because code reusage is changing the algorithm in a radically ineffective way.
For example, you can use the function list_at to get the n-th element of a list in a
loop to calculate the sum of all elements. However, the former needs to pass through
the whole list to get to the element. As you increase n, you will pass the same elements
again and again.

In fact, for a list of length N, we can calculate the number of times elements will be addressed to
compute a sum.

![formula](https://latex.codecogs.com/svg.latex?1&plus;2&plus;3&plus;...&plus;N=\frac{N(N&plus;1)}{2})

We start with a sum equal to 0. Then we add the first element, for that we need to address it alone (1).
Then we add the second element, addressing the first and the second (2). Then we add the third element,
addressing the first, the second, and the third as we look through the list from its beginning. In the end what
we get is something like O(N^2) for those familiar with the O-notation. Essentially it means that by increasing
the list size by 1, the time to sum such a list will have N added to it.
In such case it is indeed wiser to just pass through the list, adding a current element to the accumulator

Writing small functions is very good most of the time.
* Consider writing separate functions to: add an element to the front, add to the back,
create a new linked list node.
* Do not forget to extensively use const, especially in functions accepting pointers as
arguments!

## Higher-Order Functions and Lists

In this assignment, we are going to implement several higher-order functions on linked lists, which should
be familiar to those used to functional programming paradigm.
These functions are known under the names `foreach`, `map`, `map_mut`, and `foldl`.

* `foreach` accepts a pointer to the list start and a function (which returns void and
accepts an int). It launches the function on each element of the list.
* `map` accepts a function f and a list. It returns a new list containing the results of the
f applied to all elements of the source list. The source list is not affected.

For example, `f(x)=x+1` will map the list (1, 2, 3) into (2, 3, 4).
* map_mut does the same but changes the source list.
* foldl is a bit more complicated. It accepts:
– The accumulator starting value.
– A function `f(x,a)`.
– A list of elements

It returns a value of the same type as the accumulator, computed in the following way:

1. We launch f on accumulator and the first element of the list. The result is the new
accumulator value `a′`.
2. We launch f on `a′` and the second element in list. The result is again the new
accumulator value `a′′`.
3. We repeat the process until the list is consumed. In the end the final accumulator
value is the final result.

For example, let’s take `f(x,a)=x*a`. By launching foldl with the accumulator value 1 and this function
we will compute the product of all elements in the list.

* iterate accepts the initial value s, list length n, and function f. It then generates a list
of length n as follows:

![formula](https://latex.codecogs.com/svg.latex?[s,&space;f(s),&space;f(f(s)),&space;f(f(f(s)))...])

The functions described above are called **higher-order functions**, because they do accept other
functions as arguments. Another example of such a function is the array sorting function qsort.

```c
void qsort( void *base,
 size_t nmemb,
 size_t size,
 int (*compar)(const void *, const void *));
 ```
 
It accepts the array starting address base, elements count nmemb, size of individual elements size, and
the comparator function compar. This function is the decision maker which tells which one of the given
elements should be closer to the beginning of the array.
