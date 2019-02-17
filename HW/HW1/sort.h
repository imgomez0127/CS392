/*
* "I pledge my honor that I have abided by the Stevens honor system" - igomez1
* Author: Ian Gomez
* Date 02/15/19
*/
#ifndef SORTC_H
#define SORTC_H
void swap(int * intArr, int i, int j){
	/*
	* int * intArr: an integer array which has values that need to be swapped
	* int i: index for the first integer which needs to be swapped
	* int j: index for the second integer which needs to be swapped
	* This function takes in an array and two indices and swaps the items in those indices
	*/
	int temp = intArr[i];
	intArr[i] = intArr[j];
	intArr[j] = temp;
}
int lomuto_partition(int * intArr,int low, int high){
	/*
	* int * intArr: An integer array which has values that need to be sorted
	* int low: lowest index for which to analyze using lomuto partitioning
	* int high: highest index for which to analyze using lomuto partitioning
	* This function outputs an interation of the array after partioning the array using lomut partioning 
	*/
	int l = intArr[low];
	int s = low;
	for(int i = low; i < high; ++i){
		if(intArr[i] < l){
			swap(intArr,i,++s);
		} 
	}
	swap(intArr,low,s);
	return s;
}
void quickSort_helper(int * intArr,int low,int high){
	/*
	* intArr: An integer array which has values that need to be sorted
	* int low: lowest index for which to sort using quicksort
	* int high: highest index for which to sort using quicksort
	* This function is used to help sort the array using quicksort	
	*/
	if(low<high){
		int	s = lomuto_partition(intArr,low,high);
		quickSort_helper(intArr,low,s);
		quickSort_helper(intArr,s+1,high);	
	}
}
void quickSort(int * intArr,int size){ 
	/*
	* int * intArr: array of integers that need to be sorted
	* int size: size of the input array
	* This function takes in an array of integers and performs an inplace sort using the quicksort algorithm
	*/
	quickSort_helper(intArr,0,size);
}
#endif
