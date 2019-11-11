#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the makeAnagram function below.
int makeAnagram(char* a, char* b) {
    int count = 0;
    while (*a != '\0') {
        char *tmpb = b;
        int found = 0;
        while (*tmpb != '\0') {
            if (*a == *tmpb) {
                found = 1;
            }
            if (found) {
                *tmpb = *(tmpb + 1); 
            }
            tmpb++;
        }
        if (found == 0)
            count++;
        a++;
    }
    count += strlen(b);
    return count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* a = readline();

    char* b = readline();

    int res = makeAnagram(a, b);

    fprintf(fptr, "%d\n", res);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
