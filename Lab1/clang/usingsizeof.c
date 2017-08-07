#include <stdio.h>
#define NAME_LENGTH 10
#define TABLE_SIZE 100
#define UNITS_NUMBER 10

struct unit
{  /* Define a struct with an internal union */
  int x;
  float y;
  double z;
  short int a;
  long b;
  union
  { /* Union with no name because it is internal to the struct */
    char name[NAME_LENGTH];
    int id;
    short int sid;
  } identifier;
};

int main(int argc, char *argv[])
{
  int table[TABLE_SIZE];
  struct unit data[UNITS_NUMBER];

  printf("%dBytes\n", sizeof(struct unit)); /* Print size of structure */
  printf("%dBytes\n", sizeof(table));       /* Print size of table of ints */
  printf("%dBytes\n", sizeof(data));        /* Print size of table of structs */

  return 0;
}