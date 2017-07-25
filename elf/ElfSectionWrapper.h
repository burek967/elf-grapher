#pragma once

#include "elf/ElfDataWrapper.h"

#include <cstddef>
#include <iterator>

#include <libelf.h>

namespace
{

class ElfSectionIterator
{
    elf::ElfDataWrapper data;

    public:
    constexpr ElfSectionIterator(Elf_Scn *scn = NULL)
        : data {scn}
    {
        if (scn != NULL)
            ++data;
    }

    using difference_type = std::ptrdiff_t;
    using value_type = elf::ElfDataWrapper;
    using pointer = elf::ElfDataWrapper*;
    using reference = elf::ElfDataWrapper&;
    using iterator_category = std::forward_iterator_tag;

    value_type operator*() const { return data; }
    ElfSectionIterator& operator++() { ++data; return *this; }
    bool operator!=(const ElfSectionIterator& oth) const { return data != oth.data; }
};

} // namespace

namespace elf
{

class ElfSectionWrapper
{
    Elf *elf;
    Elf_Scn *scn;

    public:
    constexpr ElfSectionWrapper(Elf *e = NULL)
        : elf(e)
          , scn(NULL)
    {}

    std::size_t getNdxScn() { return elf_ndxscn(scn); }
    Elf64_Shdr* getShdr() { return elf64_getshdr(scn); }
    const char *getName(std::size_t shstrndx)
    {
        return elf_strptr(elf, shstrndx, getShdr()->sh_name);
    }

    ElfSectionWrapper& operator++();
    bool operator!=(const ElfSectionWrapper& oth) const { return scn != oth.scn; }

    ElfSectionIterator begin() const { return {scn}; }
    constexpr ElfSectionIterator end() const { return {}; }
};

} // namespace elf
