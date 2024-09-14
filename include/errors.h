#ifndef ERRORS_H
#define ERRORS_H

/**
 * A list of all possible errors that can happen during our program
 * https://tldp.org/LDP/abs/html/exitcodes.html
 * Allowed values are: 1 <= error_code <=254 except 127 and 128
 */
typedef enum _enum_errors{
    ERROR_GENERAL = 1,
    ERROR_PERMISSION = 126, // historical: cannot run or don't have enough privileges
} error;

void throw_error(error error_code, const char *message);

#endif // ERRORS_H
