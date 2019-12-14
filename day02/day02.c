#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int     get_num_elements(FILE *fp) {

  int    size = 0;

  fseek(fp, 0, SEEK_END);
  size = ftell(fp); // get current file pointer
  fseek(fp, 0, SEEK_SET);
  return(size);
}

int     *parse_array(FILE *fp, int *size) {

  char    *arr;
  char    *token;
  int    *parsed_arr;
  int     count;
  int     i;

  count = 0;
  i = 0;
  arr = malloc(sizeof(char) * *size);
  fgets(arr, *size, fp);
  token = strtok(arr, ",");
  while( token != NULL ) {
    token = strtok(NULL, ",");
    count++;
  }
  fseek(fp, 0, SEEK_SET);
  parsed_arr = malloc(sizeof(int) * count);
  fgets(arr, *size, fp);
  token = strtok(arr, ",");
  while( token != NULL ) {
    *(parsed_arr + i) = atoi(token);
    i++;
    token = strtok(NULL, ",");
  }
  *size = count;
  free(arr);
  return(parsed_arr);
}

int    part_1(int *parsed_array, int *size, int noun, int verb) {

  int    first;
  int    second;
  int    third;
  int    delimiter;

  delimiter = 0;
  *(parsed_array + 1) = noun;
  *(parsed_array + 2) = verb;
  while (delimiter < *size) {
    first = *(parsed_array + delimiter + 1);
    second = *(parsed_array + delimiter + 2);
    third = *(parsed_array + delimiter + 3);
    if (*(parsed_array + delimiter) == 1) {
      *(parsed_array + third) = *(parsed_array + first) + *(parsed_array + second);
    }
    if (*(parsed_array + delimiter) == 2) {
      *(parsed_array + third) = *(parsed_array + first) * *(parsed_array + second);
    }
    if (*(parsed_array + delimiter) == 99) {
      break;
    }
    delimiter += 4;
  }
  return(*parsed_array);
}

int    part_2(int *parsed_array, int *copy, int *size) {

  int    first;
  int    second;
  int    third;
  int    delimiter = 0;
  int    noun = 1;
  int    verb = 1;

  while (noun < 100 && verb < 100) {
    *(parsed_array + 1) = noun;
    *(parsed_array + 2) = verb;
    while (delimiter < *size) {
      first = *(parsed_array + delimiter + 1);
      second = *(parsed_array + delimiter + 2);
      third = *(parsed_array + delimiter + 3);
      if (*(parsed_array + delimiter) == 1) {
        *(parsed_array + third) = *(parsed_array + first) + *(parsed_array + second);
      }
      if (*(parsed_array + delimiter) == 2) {
        *(parsed_array + third) = *(parsed_array + first) * *(parsed_array + second);
      }
      if (*(parsed_array + delimiter) == 99) {
        break;
      }
      delimiter += 4;
    }
    delimiter = 0;
    if (verb < 99 && noun < 99)
      verb++;
    else {
      verb = 0;
      noun++;
    }
    if (*(parsed_array) == 19690720)
      break;
    memcpy(parsed_array, copy, sizeof(int) * *(size));
  }
  return(*parsed_array);
}


int    main(int argc, char** argv) {

  FILE     *fp;
  int      *size;
  int      *parsed_array;
  int      *copy = NULL;

  (void)argc;
  (void)argv;
  fp = fopen("input.txt", "r");
  size = (int *)malloc(sizeof(int));
  *size = get_num_elements(fp);
  parsed_array = parse_array(fp, size);
  copy = (int *)malloc(sizeof(int) * *(size));
  memcpy(copy, parsed_array, sizeof(int) * *size);
  printf("\npart 1 result : %d\n", part_1(parsed_array, size, 12, 2));
  memcpy(parsed_array, copy, sizeof(int) * *(size));
  printf("\npart 2 result : %d\n", part_2(parsed_array, copy, size));
  return(0);
}
