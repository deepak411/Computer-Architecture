#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define arr_size 65536*256 
#define avg_count 100

int main(){
	int* arr;	
	printf("Linear Read , Array Size: %dKB\n", arr_size/256);
	struct timespec startAccess, endAccess;
	double mainMemAccess=0;
	const int SECONDS_PER_NS = 1000000000;
	double temp=0;
 
	arr=(int*)malloc(arr_size*sizeof(int));	     // dynamically allocate the  memory

	clock_gettime(CLOCK_REALTIME, &startAccess); // get the start time

	for(int k=0;k<avg_count;k++){				
		for(int i=0;i<arr_size;i++){
			temp+=arr[i];
		}
	}		
	
	clock_gettime(CLOCK_REALTIME, &endAccess);   // get the stop time

	mainMemAccess = ((endAccess.tv_sec - startAccess.tv_sec) * SECONDS_PER_NS) + (endAccess.tv_nsec - startAccess.tv_nsec); // calculate the elapsed time in 'ns'
    	mainMemAccess /= (arr_size*avg_count);	     //average access time per reference
	free(arr); 
	printf("Temp Value: %lf\n", temp);
	printf("\nAccess Time %lf\n", mainMemAccess);
	return 0;
}
