#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <memory_in_MB>\n", argv[0]);
        return 1;
    }

    int memory_mb = atoi(argv[1]);
    size_t memory_size = (size_t)memory_mb * 1024 * 1024;
    char *memory_block = (char *)malloc(memory_size);
    
    printf("Allocated %d MB of memory. Streaming through it...\n", memory_mb);

    while (1) {
        for (size_t i = 0; i < memory_size; i++) {
            memory_block[i] = (char)(i % 256);
        }
        usleep(1000); 
    }

    free(memory_block);
    return 0;
}
