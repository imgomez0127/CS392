#ifndef SORTC_H
#define SORTC_H
void swap(int * intArr, int i, int j){
	int temp = intArr[i];
	intArr[i] = j;
	intArr[j] = temp;
}
int lomuto_partition(int * intArr,int low, int high){
	int l = intArr[low];
	int s = low;
	for(int i = low; i < high; ++i){
		if(intArr[i] < l){
			swap(intArr,i,++s);
		}
	swap(intArr,low,s);
	return s;
}
int quickSort_helper(int * intArr,int low,int high){
	if(low<high){
		int	s = lomuto_partition(intArr,low,high);
		quickSort_helper(intArr,low,s);
		quickSort_helper(intArr,s+1,high);	
int quickSort(int intArr,int size){ 
	return quickSort_helper(intArr,0,size);
}
#endif
