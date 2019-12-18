#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct    wire {

    int    right;
    int    up;
    int    left;
    int    down;
};

void    get_num_elements(FILE *fp, char **str_wires) {

    int     c, i, counter = 0;
    char    **wires;

    wires = (char **)malloc(sizeof(char *) * 2);
    for (i = 0; i < 2; i++) {
         while ((c = fgetc(fp)) != '\n' && c != EOF) {
              printf("%c", c);
             counter++;
        }
        printf("\n\ncounter = %d\n\n", counter);
        *(wires + i) = (char *)malloc(sizeof(char) * counter);
        counter = 0;
        printf("\n\n\n");
    }
    if (ferror (fp))
        printf ("Read Error\n"), exit (EXIT_FAILURE);
}

void    str_to_int(char **str_wires) {

    int     counter = 0;
    wire    wire1;

    for (int i = 0; i < 2; i++) {
        while (*(str_wires) + i != '\0') {
            // TODO parse array and add value to the wire struct //
            i++;
        }
    }
}

int    main(int argc, char **argv) {

    FILE    *fp;
    char    **str_wires;

    (void)argc;
    (void)argv;
    fp = fopen("input.txt", "r");
    get_num_elements(fp, str_wires);
    return(0);
}
