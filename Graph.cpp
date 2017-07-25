#include "Graph.h"

#include "elf/ElfDataWrapper.h"
#include "elf/ElfSectionWrapper.h"
#include "elf/ElfWrapper.h"

#include <iostream>

namespace
{
    void print_rel_table(elf::ElfSectionWrapper& section)
    {
        for (elf::ElfDataWrapper data : section)
            std::cout << "  data block with size " << data.get()->d_size << std::endl;
    }
}

void Graph::add_file(const char *path)
{
    elf::ElfWrapper elf(path);
    std::size_t shstrndx = elf.getShdrStrNdx();
    for (elf::ElfSectionWrapper section : elf) {
        std::cout << section.getNdxScn() << "   " << section.getName(shstrndx)<< std::endl;
        if (section.getShdr()->sh_type & SHT_RELA)
            print_rel_table(section);
    }
}
