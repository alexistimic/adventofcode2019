#include <stdio.h>
#include <stdlib.h>

void    part_1(int *array, int size) {

  int    i;
  int    sum;

  i = 0;
  sum = 0;
  while (i < size) {
    sum += (*(array + i) / 3 - 2);
    i++;
  }
  printf("%d\n", sum);
}

void    part_2(int *array, int size) {

  int    i;
  int    sum;

  i = 0;
  sum = 0;
  while (i < size) {
    while ((*(array + i) / 3 - 2) > 0) {
      sum += (*(array + i) / 3 - 2);
      *(array + i) = *(array + i) / 3 - 2;
    }
    i++;
  }
  printf("%d\n", sum);
}

int    get_num_elements(FILE *fp) {

  int    i =0;
  int    size = 0;

  while(fscanf(fp, "%d", &i) == 1)
    size++;
  // Return pointer to beginning of file
  fseek(fp, 0, SEEK_SET);
  return(size);
}

int    main(int argc, char** argv) {

  FILE     *fp;
  int      i;
  int      size;
  int      *array;
  int      count;

  (void)argc;
  (void)argv;
  i = 0;
  count = 0;
  fp = fopen("input.txt", "r");
  size = get_num_elements(fp);
  array = malloc(sizeof(int) * size);
  while(fscanf(fp, "%d", &i) == 1) {
    *(array + count) = i;
    count++;
  }
  part_1(array, size);
  part_2(array, size);
  return(0);
}
