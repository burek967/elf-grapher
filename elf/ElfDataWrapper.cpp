#include "elf/ElfDataWrapper.h"

#include <libelf.h>

elf::ElfDataWrapper& elf::ElfDataWrapper::operator++()
{
    data = elf_getdata(section, data);
    return *this;
}
