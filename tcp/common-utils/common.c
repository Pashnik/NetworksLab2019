#include "headers/common.h"
#include "headers/errors.h"

#define DECIMAL 10

/*
 * By the returned number of 'atoi' function it is impossible to determine
 * whether the string contains the correct number or not, because in
 * cases when argv = 0 and in error cases it will return 0.
 */
uint16_t exclude(int argc, int argnum, char *argv[], int portnum) {
    if (argc != argnum) raise_error(WRONG_ARGS_NUMBER);
    char *p;
    int port = (int) strtol(argv[portnum], &p, DECIMAL);
    if (port <= 0) raise_error(WRONG_PORT_FORMAT);
    return (uint16_t) port;
}

uint16_t exclude_servport(int argc, char *argv[]) {
    return exclude(argc, 2, argv, 1);
}

uint16_t exclude_cliport(int argc, char *argv[]) {
    return exclude(argc, 3, argv, 2);
}