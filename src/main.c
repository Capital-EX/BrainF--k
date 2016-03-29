#include <stdio.h>
#include <stdlib.h>
#define PROG_SIZE 65536
#define SKIP if(skip){ip++;break;}
int main(int argc, char *argv[]){
    FILE *file;
    if (argc == 1){
        printf("No file give...");
        return 0;
    }else{
        file = fopen(argv[1], "r");
        if (!file){
            return 0;
        }
    }
    int *tape = calloc(PROG_SIZE, sizeof(int));
    int tapePointer = 0;
    int jumpStack[256];
    int jump = -1;
    int skip = 0;
    char prog[PROG_SIZE];
    int ip = 0;
    int c;
    int i = 0;
    while ( (c = fgetc(file)) != EOF ){
        prog[i++] = c;
    }
    prog[i] = '\0';
    while ( ip < PROG_SIZE  && prog[ip] != '\0'){
        switch(prog[ip]){
            case '>': SKIP
                tapePointer++;
                ip++;
                break;
            case '<': SKIP
                tapePointer--;
                ip++;
                break;
            case '+': SKIP
                tape[tapePointer]++;
                ip++;
                break;
            case '-': SKIP
                tape[tapePointer]--;
                ip++;
                break;
            case '.': SKIP
                printf("%c",tape[tapePointer]);
                ip++;
                break;
            case ',': SKIP
                tape[tapePointer] = getchar();
                ip++;
                break;
            case '[':
                if (tape[tapePointer] == 0){
                    skip++;
                    ip++;
                }else{
                    jumpStack[++jump] = ip;
                    ip++;
                }
                break;
            case ']':
                if (tape[tapePointer] != 0 && !skip){
                    ip = jumpStack[jump];
                    jump--;
                }else{
                    if (skip != 0){
                        skip--;
                    }else{
                        jump--;
                    }
                  
                    ip++;
                }
                break;
            default:
                ip++;
        }
    }
    printf("\n%s\n",prog);
    return 0;
}