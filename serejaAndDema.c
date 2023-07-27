#include <stdio.h>
#include <stdlib.h>

/*  - take input length, array
	-call get the biggest
	- Sereja +=  the largest length wish the bigger of arr[0], arr[length -1]
	-call func() remove elment from the list
	
	-call get the biggest
	- Dima +=  the largest length wish the bigger of arr[0], arr[length -1]
	-call func() remove elment from the list
*/
int biggest (int * arr, int length);
int MyRemove (int * arr, int length, int chosen);

int main (){
	//- take input length, array
	int length, Sereja = 0, Dima = 0, chosen;
	
	scanf("%d" , &length);
	
	int * arr =  (int *)malloc(length * sizeof(int));
	
	for ( int i = 0; i < length; i++){
		scanf("%d", &arr[i]); 
	}
	
	//-call get the biggest
	do { 
	chosen = biggest( arr,  length);
	Sereja += chosen;
	length = MyRemove( arr, length, chosen);
	
	if (!length)break;//is there any more cards?
	
	chosen = biggest( arr,  length);
	Dima += chosen;
	length = MyRemove( arr, length, chosen);
	} while ( length );
	
	printf("%d %d", Sereja, Dima);
	
	
}

int biggest (int * arr, int length){
	
	if ( arr[0] > arr[length-1]) return arr[0];
	else return arr[length-1];
	
}
int MyRemove (int * arr,int  length, int chosen){
	if ( chosen == arr[length - 1]){
		length -= 1;
	}
	
	else {
		for ( int i = 0; i < length-1; i++){
		arr[i] = arr[i+1];
		
		} 
		length -= 1;
	}
	return length;
}