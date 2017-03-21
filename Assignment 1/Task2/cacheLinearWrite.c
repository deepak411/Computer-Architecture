#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define arr_size 1*256  //change this number to change the array size( 'n'*256= nKB) 
#define avg_count 100	// counter for average iterations

int main(){
	int* arr;	
	printf("Linear Write , Array Size: %dKB\n", arr_size/256);
	struct timespec startAccess, endAccess;
	double mainMemAccess=0;
	const int SECONDS_PER_NS = 1000000000;
	
	arr=(int*)malloc(arr_size*sizeof(int));	// dynamically allocate the  memory

	int k=0;
	// perform the calculations
	for(k=0;k<avg_count;k++){
		int i=0;				
		for(i=0;i<arr_size;i++){
			arr[i]=i;
		}
	}		
	
	free(arr); // free the memory
	return 0;
}
