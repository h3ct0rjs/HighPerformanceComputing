#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct cell_info
{
    int a;
    int b;
    int table[TABLE_SIZE];
};
//define a pointer to the cell_info struct
struct cell_info *cell_ptr;		

int main(int argc, char *argv[])
{
	//Explicit memory management, you allocate the exact mem required in the heap. 
	//the previous struct is located in the stack memory and static variables in 
	//the global memory, three kind of different memories. 
	cell_ptr = (struct cell_info *)malloc(sizeof(struct cell_info));
	printf("%dBytes",sizeof(cell_ptr));
	printf("\n%dBytes",sizeof(struct cell_info));
	//after the usage of the memory, we need to free up the mem using free.
	free(cell_ptr);
	//then the operative system just use the mem space that was free up.
	return 0;
}
