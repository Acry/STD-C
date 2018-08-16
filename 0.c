#include <stdlib.h>
#include <stdio.h>

// TODO calloc

// free( an address pointer); If ptr is NULL, no operation is performed.

// sizeof syntax:
// sizeof unary-expression  
// sizeof ( type-name )

int main(void)
{

int *numbers;
numbers=malloc(sizeof (int));
numbers[0]=4;
printf("Number: %d\n",numbers[0]);
free(numbers);
printf("\n");

int *array;
array=malloc(0);
free(array);
printf("\n");

int *more_numbers;
more_numbers=malloc(sizeof more_numbers * 10);
for(int i=1;i<11;i++){
	more_numbers[i]=i;
	printf("%d\n",more_numbers[i]);
}
free(more_numbers);
printf("\n");


int *another_array=NULL;
// If ptr is NULL, then the call to realloc is equivalent to malloc(size)
another_array=realloc(another_array, 10);
for(int i=1;i<11;i++){
	another_array[i]=i;
	printf("%d\n",another_array[i]);
}
free(another_array);
printf("\n");
int *numbers_again;
numbers_again=malloc(sizeof (int)*5);

for(int i=0; i < 5; i++){
	numbers_again[i]=i+1;
	printf("%d\n",numbers_again[i]);
}

//  if size is equal to zero, and ptr is not NULL,
//  then the call is equivalent to free(ptr).
numbers_again=realloc(numbers_again, 0);
if (numbers_again!=NULL)
	free(numbers_again);
else
	printf("Nothin to free, realloc did that already.\n");
printf("\n");

int *last_array;
last_array=malloc(sizeof last_array * 10);
for(int i=1;i<11;i++){
	last_array[i]=i;
	printf("%d\n",last_array[i]);
}
printf("\n");

/* 
 * The realloc() function returns a pointer to the newly allocated memory,
 * which is suitably aligned for any built-in type and may be different
 * from ptr, or NULL if the request fails.
 *
 *
 *
 * If realloc() fails, the original block is left untouched; 
 * it is not freed or moved.
 *
 * If the area pointed to was moved, a free(ptr) is done.
 */

int *new_array=realloc(last_array, 25);
if  (new_array==NULL){
	printf("request failed!\n");
	free(last_array);
	exit(EXIT_FAILURE);
}
printf("request succeeded!\n");
last_array=new_array;
for(int i=1;i<26;i++){
	last_array[i]=i;
	printf("%d\n",last_array[i]);
}

/*
 * If size was equal to 0, either NULL or a pointer suitable to be passed
 * to free() is returned.
 */

last_array=realloc(last_array, 0);
if (numbers_again!=NULL)
	free(last_array);
else
	printf("Nothin to free, realloc did that already.\n");
printf("\n");


/* 	valgrind ./0
	HEAP SUMMARY:
	in use at exit: 0 bytes in 0 blocks
	total heap usage: 8 allocs, 8 frees, 1,243 bytes allocated
	All heap blocks were freed -- no leaks are possible
*/
return EXIT_SUCCESS;
}
