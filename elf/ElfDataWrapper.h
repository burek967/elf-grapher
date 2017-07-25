#pragma once

#include <cstddef>
#include <iterator>

#include <libelf.h>

namespace elf
{

class ElfDataWrapper
{
    Elf_Data *data;
    Elf_Scn *section;

    public:
    constexpr ElfDataWrapper(Elf_Scn *scn = NULL)
        : data {NULL}
        , section {scn}
    {}

    Elf_Data* get() { return data; }
    const Elf_Data* get() const { return data; }

    ElfDataWrapper& operator++();
    bool operator!=(const ElfDataWrapper& oth) const { return data != oth.data; }
};

} // namespace elf
