#include <stdio.h>

typedef struct {

    int base;
    int limit;

} Segment;

int main() {

    Segment seg[3] = {

        {1000,400},
        {2000,500},
        {3000,300}
    };

    int requests[3][2] = {

        {0,200},
        {1,600},
        {2,150}
    };

    for (int i = 0; i < 3; i++) {

        int s = requests[i][0];

        int offset = requests[i][1];

        printf("\nRequest %d:\n", i+1);

        printf("Segment = %d Offset = %d\n",
               s,
               offset);

        if (offset >= seg[s].limit) {

            printf("Segmentation Fault!\n");

            printf("Reason: Offset exceeds limit\n");
        }

        else {

            int physical =
                seg[s].base + offset;

            printf("Physical Address = %d\n",
                   physical);
        }
    }

    return 0;
}

//physical address = segment base + offset