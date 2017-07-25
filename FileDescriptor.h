#pragma once

#include <fcntl.h>

class FileDescriptor
{
    int fd;

    public:
    FileDescriptor(const FileDescriptor&) = delete;
    FileDescriptor& operator=(const FileDescriptor&) = delete;

    FileDescriptor(const char *path, int flags = O_RDONLY);
    ~FileDescriptor();

    int get() const { return fd; }
};
