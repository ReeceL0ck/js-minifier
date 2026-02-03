#include <stdio.h>
#include <string.h>

void remove_spaces(char *line) {
    char *start = line;
    while (*start == ' ') start++;

    char *end = start + strlen(start);
    while (end > start && *(end - 1) == ' ') end--;

    memmove(line, start, end - start);
    line[end - start] = '\0';
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Incorrect usage: program <input-file>\n");
        return 1;
    } else if (argc > 2 ) {
        printf("Too many arguements usage: program <input-file>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    FILE *fpo = fopen("output.js","a");

    char buffer[sizeof(fp)];

    while (!feof(fp)) {
        fgets(buffer, sizeof(buffer), fp);
        printf("%s", buffer);
        buffer[strcspn(buffer, "\n")] = 0;
        remove_spaces(buffer);
        fprintf(fpo, buffer);
    }
    fclose(fp);
    printf("\n");
    return 0;
}
