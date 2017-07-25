#include "elf/ElfWrapper.h"

#include <iostream>
#include <stddef.h>

#include <libelf.h>

elf::ElfWrapper::ElfWrapper(const char *path)
    : fd(path)
{
    e = elf_begin(fd.get(), ELF_C_READ, NULL);
    if (e == NULL)
        throw elf_errmsg(-1);
    if (elf_kind(e) != ELF_K_ELF)
        throw "Not an ELF file";
}

elf::ElfWrapper::~ElfWrapper()
{
    elf_end(e);
}

std::size_t elf::ElfWrapper::getShdrStrNdx()
{
    std::size_t ret;
    if (elf_getshdrstrndx(e, &ret) == -1)
        throw elf_errmsg(-1);
    return ret;
}
