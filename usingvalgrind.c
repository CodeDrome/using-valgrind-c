
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void uninitialized_memory();
void memory_leak();
void use_freed_memory();
void overshoot_memory();
void realloc_memory();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("-----------------");
    puts("| codedrome.com |");
    puts("| valgrind      |");
    puts("-----------------\n");

    uninitialized_memory();
    memory_leak();
    use_freed_memory();
    overshoot_memory();
    realloc_memory();

    return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION uninitialized_memory
//--------------------------------------------------------
void uninitialized_memory()
{
    puts("Using uninitialized memory");

    int* data;

    // uncomment to fix error
    //data = malloc(sizeof(int) * 32);

    data[0] = 123;

    printf("%d\n\n", data[0]);

    // uncomment to fix error
    //free(data);
}

//--------------------------------------------------------
// FUNCTION memory_leak
//--------------------------------------------------------
void memory_leak()
{
    puts("Memory leak");

    int* data;

    data = malloc(sizeof(int) * 32);

    data[0] = 234;

    printf("%d\n\n", data[0]);

    // uncomment to fix error
    //free(data);
}

//--------------------------------------------------------
// FUNCTION use_freed_memory
//--------------------------------------------------------
void use_freed_memory()
{
    puts("Using freed memory");

    int* data;

    data = malloc(sizeof(int) * 32);

    data[0] = 345;

    // move to after printf to fix error
    free(data);

    printf("%d\n\n", data[0]);
}

//--------------------------------------------------------
// FUNCTION overshoot_memory
//--------------------------------------------------------
void overshoot_memory()
{
    puts("Overshooting memory");

    int* data;

    data = malloc(sizeof(int) * 32);

    // change indexes to between 0 and 31 to fix error
    data[32] = 456;

    printf("%d\n\n", data[32]);

    free(data);
}

//--------------------------------------------------------
// FUNCTION realloc_memory
//--------------------------------------------------------
void realloc_memory()
{
    puts("realloc memory");

    int* data = NULL;

    for(int i = 0; i < 32; i++)
    {
        data = realloc(data, (sizeof(int)) * (i + 1));

        data[i] = pow(i, 2);

        printf("%d\t%d\n", i, data[i]);
    }

    // uncomment to fix error
    //free(data);
}
