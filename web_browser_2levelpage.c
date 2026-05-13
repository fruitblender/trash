#include <stdio.h>

int main() {

    unsigned int virtual_address =
        0x00403004;

    unsigned int l1_index;
    unsigned int l2_index;
    unsigned int offset;

    l1_index =
        (virtual_address >> 22) & 0x3FF;

    l2_index =
        (virtual_address >> 12) & 0x3FF;

    offset =
        virtual_address & 0xFFF;

    printf("Virtual Address = 0x%X\n",
           virtual_address);

    printf("L1 Index = %u\n",
           l1_index);

    printf("L2 Index = %u\n",
           l2_index);

    printf("Offset = %u\n",
           offset);

    int l2_base = 5000;

    int frame = 7;

    unsigned int physical_address =
        frame * 4096 + offset;

    printf("L1[%u] -> L2 table base = %d\n",
           l1_index,
           l2_base);

    printf("L2[%u] -> Frame = %d\n",
           l2_index,
           frame);

    printf("Physical Address = %u (0x%X)\n",
           physical_address,
           physical_address);

    return 0;
}

// physical address = frame number * page size + offset