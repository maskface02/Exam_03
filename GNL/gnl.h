#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef GNL_H
#define GNL_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char    *get_next_line(int fd)
;

#endif
