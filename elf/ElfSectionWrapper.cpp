#include "elf/ElfSectionWrapper.h"

#include <libelf.h>

elf::ElfSectionWrapper& elf::ElfSectionWrapper::operator++()
{
    scn = elf_nextscn(elf, scn);
    return *this;
}
