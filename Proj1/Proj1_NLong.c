#include <stdio.h>

int * getArray( ) {
  static int array_to_return[10];
  
  for (int i = 0; i < 10; ++i) {
    array_to_return[i] = i*2;
  }
  return array_to_return;
}

int main ()
{
  int *returnedArray;
  int i;

  returnedArray = getArray();
  for (int j = 0; j < 10; j++ ) {
    printf( "returnedArray[%d] = %d\n", j, returnedArray[j]);
  }
  return 0;
}
