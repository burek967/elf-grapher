#include <iostream>

#include <libelf.h>

#include "Graph.h"

void print_usage(const char *prog)
{
    std::cerr << "Usage: " << prog << " file ..." << std::endl;
}

void elf_init()
{
    if (elf_version(EV_CURRENT) == EV_NONE)
        throw elf_errmsg(-1);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    try
    {
        elf_init();
    }
    catch (const char *e)
    {
        std::cerr << e << std::endl;
        return 2;
    }
    
    Graph g;
    for (int i=1; i<argc; ++i)
    {
        try
        {
            g.add_file(argv[i]);
        }
        catch (const char *e)
        {
            std::cerr << argv[i] << ": " << e << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << argv[i] << ": " << e.what() << std::endl;
        }
    }
    return 0;
}
