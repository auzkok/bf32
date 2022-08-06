#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    if (argc != 2) { puts("bf32 - brainfuck in 32 lines of code\nUsage: bf32 file"); return 1; }
    unsigned char tape[30000] = {0}; // Standard tape size
    size_t i = 0, p = 0, d = 0; // index of instruction, position on tape, depth of nested loops
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) { printf("Cannot open file: %s", argv[1]); return 1; }
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* src = malloc(fileSize+1);
    fread(src, 1, fileSize, file);
    fclose(file);
    src[fileSize] = 0;
    while (src[i] != 0) {
        switch (src[i]) {
            case '+': tape[p]++; break;
            case '-': tape[p]--; break;
            case '[': if (tape[p] == 0) { while (!((src[i] == ']')&&(--d==0))) { d = (src[i]=='[')?d+1:d; i++; } } break;
            case ']': if (tape[p] != 0) { while (!((src[i] == '[')&&(--d==0))) { d = (src[i]==']')?d+1:d; i--; } } break;
            case '>': p = (p == 30000-1) ? 0 : p + 1; break;
            case '<': p = (p == 0) ? 30000-1 : p -1; break;
            case '.': putchar(tape[p]); fflush(stdout); break;
            case ',': tape[p] = getchar(); break;
            default: break;
        }
        i++;
    }
    free(src);
    return 0;
}
