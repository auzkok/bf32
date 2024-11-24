#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc != 2) { puts("bf16 - brainfuck in 16 lines of code\nUsage: bf16 file"); return 1; }
    unsigned char tape[30000] = {0}; // Standard tape size
    FILE* f = fopen(argv[1], "rb");
    for (int i = 0, p = 0, d = 0;(i = fgetc(f)) != EOF;) switch (i) {
        case '+': tape[p]++; break;
        case '-': tape[p]--; break;
        case '[': if (tape[p] == 0) { while (!((i == ']')&&(--d==0))) { d = (i=='[')?d+1:d; i = fgetc(f); } } break;
        case ']': if (tape[p] != 0) { while (!((i == '[')&&(--d==0))) { d = (i==']')?d+1:d; fseek(f, -2, SEEK_CUR); i = fgetc(f); } } break;
        case '>': p = (p == 30000-1) ? 0 : p + 1; break;
        case '<': p = (p == 0) ? 30000-1 : p -1; break;
        case '.': putchar(tape[p]); fflush(stdout); break;
        case ',': tape[p] = getchar(); break;
    }
}