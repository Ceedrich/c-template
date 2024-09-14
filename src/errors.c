#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "errors.h"

void throw_error(error error_code, const char *message){
    switch(error_code){
        case ERROR_GENERAL:
            fprintf(stderr, "Error: A general error occurred\n");
            break;
        case ERROR_PERMISSION:
            fprintf(stderr, "Error: A permission error occurred\n");
        default:
            fprintf(stderr, "Error: Unknown error\n");
            break;
    }
    if (message[0] != '\0'){
        fprintf(stderr, "Details: %s\n", message);
    }
    if (error_code >= 1 && error_code <= 245)
        exit(error_code);
    else
        exit(1);
}
