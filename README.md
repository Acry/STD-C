Standard C Snippets

0 Memory Allocation
===================
`void * malloc(size_t size)`

reserves (bytes * count) and returns a pointer to the allocated memory.

If size is 0, then `malloc()` returns either `NULL`,
or a unique pointer value that can later be successfully passed to `free()`.

`free()`  
If `ptr` is `NULL`, no operation is performed.


`realloc()`  
`void * realloc(void *ptr, size_t size);`

If  `ptr`  is  `NULL`,  then the call is equivalent to `malloc(size)`,
for all values of size; if size is equal to zero, and `ptr` is
not  `NULL`,  then  the  call  is equivalent to `free(ptr)`.

Unless `ptr` is `NULL`, it must have been returned by an earlier call to  `malloc()`, `calloc()`,  or `realloc()`.

If the area pointed to was moved, a `free(ptr)` is done.

The `realloc()` function call returns a pointer to the newly allocated memory,
which is suitably aligned for any built-in type and  may  be  different
from `ptr`, or `NULL` if the request fails.  If size was equal to 0, either
`NULL` or a pointer suitable to be passed  to  `free()`  is  returned.   If
`realloc()` fails, the original block is left untouched; it is not freed
or moved.

[List of allocating C functions](https://www.lemoda.net/c/allocating-c-functions/index.html)
