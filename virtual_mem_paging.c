#include <stdio.h>

int main() {

    int page_table[3] = {3,1,4};

    unsigned int addresses[2] =
        {0x1A3F, 0x2B10};

    int page_size = 4096;

    for (int i = 0; i < 2; i++) {

        unsigned int va =
            addresses[i];

        unsigned int page =
            va / page_size;

        unsigned int offset =
            va % page_size;

        unsigned int frame =
            page_table[page];

        unsigned int physical =
            frame * page_size + offset;

        printf("\nVirtual Address = 0x%X\n",
               va);

        printf("Page Number = %u\n",
               page);

        printf("Offset = %u\n",
               offset);

        printf("Frame Number = %u\n",
               frame);

        printf("Physical Address = 0x%X\n",
               physical);
    }

    return 0;
}

//page number = virtual address / page size
//offset = virtual address % page size
//physical address = frame number * page size + offset
