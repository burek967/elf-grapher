#include "FileDescriptor.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

FileDescriptor::FileDescriptor(const char *path, int flags)
{
    fd = open(path, flags);
    if (fd == -1)
        throw strerror(errno);
}

FileDescriptor::~FileDescriptor()
{
    close(fd);
}
