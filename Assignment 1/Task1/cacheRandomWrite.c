#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define arr_size 16384*16 
#define avg_count 100

struct node{
	int data[15];
	int next;
};

int main(){

	srand(time(NULL)); // seed for random number generator		
	printf("Random Write , Total Size: %dKB\n", arr_size/16);

	struct timespec startAccess, endAccess;
	double mainMemAccess=0;
	const int SECONDS_PER_NS = 1000000000;

	struct node* arr;
	arr=(struct node*) malloc(arr_size*sizeof(struct node));
	int val=arr_size;
	
	for(int i=0;i<arr_size;i++){ // initialise the  next pointer for entire structure array
		arr[i].next=val;
	}
	
	for(int i=0;i<arr_size;i++){
		int tempnext=(rand() % val); // take a random number
		int j=0;
		for(j=0;j<arr_size;j++){	
			if(arr[j].next==tempnext){
				break;			
			}
		}
		if(j==arr_size){
			arr[i].next=tempnext;	// if a unique random nuber, then keep this
		}
		else{
			i--; // try again			
		}
		
	}

	clock_gettime(CLOCK_REALTIME, &startAccess); // get the start time

	for(int k=0;k<avg_count;k++){	
		int ctr=0;
		for(int i=0;i<arr_size;i++){
			arr[ctr].data[0]=i;
			ctr=arr[ctr].next;
		}	
	}

	clock_gettime(CLOCK_REALTIME, &endAccess); // get the end time

	mainMemAccess = ((endAccess.tv_sec - startAccess.tv_sec) * SECONDS_PER_NS) + (endAccess.tv_nsec - startAccess.tv_nsec); // calculate the elapsed time
	mainMemAccess /= (arr_size*avg_count);  //average access time per reference
	free(arr);
	printf("\nAccess Time %lf\n", mainMemAccess);
	return 0;
}
