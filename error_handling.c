#include "monty.h"
/**
 * error_message - Print error message
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error_message(int error_code, ...)
{
	va_list argv;
	char *op;
	int num;

	va_start(argv, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argv, char *));
			break;
		case 3:
			num = va_arg(argv, int);
			op = va_arg(argv, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argv, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * error_message2 - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void error_message2(int error_code, ...)
{
	va_list argv;
	char *op;
	int num;

	va_start(argv, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argv, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argv, int));
			break;
		case 8:
			num = va_arg(argv, unsigned int);
			op = va_arg(argv, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argv, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list argv;
	int num;

	va_start(argv, error_code);
	num = va_arg(argv, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
