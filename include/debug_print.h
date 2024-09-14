#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

// Define debug levels
#define DEBUG_LEVEL_NONE  0
#define DEBUG_LEVEL_ERROR 1
#define DEBUG_LEVEL_WARN  2
#define DEBUG_LEVEL_INFO  3
#define DEBUG_LEVEL_DEBUG 4

// Set the current debug level if not already defined
#ifndef CURRENT_DEBUG_LEVEL
#define CURRENT_DEBUG_LEVEL DEBUG_LEVEL_INFO
#endif // CURRENT_DEBUG_LEVEL

// Define a debug print macro with levels
#define DEBUG_PRINT(level, format, ...) \
    do { \
        if (level <= CURRENT_DEBUG_LEVEL) { \
            switch (level) { \
                case DEBUG_LEVEL_ERROR: \
                    fprintf(stderr, "ERROR: " format "\n", ##__VA_ARGS__); \
                    break; \
                case DEBUG_LEVEL_WARN: \
                    fprintf(stderr, "WARN:  " format "\n", ##__VA_ARGS__); \
                    break; \
                case DEBUG_LEVEL_INFO: \
                    fprintf(stdout, "INFO:  " format "\n", ##__VA_ARGS__); \
                    break; \
                case DEBUG_LEVEL_DEBUG: \
                    fprintf(stdout, "DEBUG: " format "\n", ##__VA_ARGS__); \
                    break; \
            } \
        } \
    } while (0)

#endif // DEBUG_PRINT_H
