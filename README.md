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
