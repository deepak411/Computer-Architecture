#include <time.h>
#include <stdio.h>
#include <string.h>

#define arr_size 1*16 //change this number to change the array size( 'n'*16= nKB) 
#define avg_count 100

struct node{  // structure for cache block
	int data[15];
	int next;
};

int main(){

	srand(time(NULL)); // seed for random number generator		
	printf("Random Read , Total Size: %dKB\n", arr_size/16);

	struct timespec startAccess, endAccess;
	double mainMemAccess=0;
	const int SECONDS_PER_NS = 1000000000;
	double temp=0;
 

	struct node* arr;
	arr=(struct node*) malloc(arr_size*sizeof(struct node));
	int val=arr_size;
	
	int i=0;
	for(i=0;i<arr_size;i++){ // initialise the  next pointer for entire structure array
		arr[i].next=val;
	}
	
	i=0;
	for(i=0;i<arr_size;i++){
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

	//perform the calculations
	int k=0;
	for(k=0;k<avg_count;k++){	
		int ctr=0;
		i=0;
		for(i=0;i<arr_size;i++){
			temp+=arr[ctr].data[0];
			ctr=arr[ctr].next;
		}	
	}

	free(arr);
	printf("Temp Value: %lf\n", temp);
	return 0;
}
