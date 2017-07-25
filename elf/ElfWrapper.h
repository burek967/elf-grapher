#pragma once

#include "elf/ElfSectionWrapper.h"
#include "FileDescriptor.h"

#include <cstddef>
#include <iterator>

#include <libelf.h>

namespace {

class ElfIterator
{
    elf::ElfSectionWrapper section;

    public:
    constexpr ElfIterator(Elf *e = NULL)
        : section {e}
    {
        if (e != NULL)
            ++section;
    }

    using difference_type = std::ptrdiff_t;
    using value_type = elf::ElfSectionWrapper;
    using pointer = elf::ElfSectionWrapper*;
    using reference = elf::ElfSectionWrapper&;
    using iterator_category = std::forward_iterator_tag;

    value_type operator*() const { return section; }
    ElfIterator& operator++() { ++section; return *this; }
    bool operator!=(const ElfIterator& oth) const { return section != oth.section; }
};

} // namespace

namespace elf
{

class ElfWrapper
{
    FileDescriptor fd;
    Elf *e;

    public:
    ElfWrapper(const char *path);
    ~ElfWrapper();

    std::size_t getShdrStrNdx() const;

    const Elf* get() const { return e; }
    Elf* get() { return e; }

    std::size_t getShdrStrNdx();

    ElfIterator begin() const { return {e}; }
    constexpr ElfIterator end() const { return {}; }
};

} // namespace elf
