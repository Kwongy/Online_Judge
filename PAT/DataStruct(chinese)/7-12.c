#include<stdio.h>
	
int n;
long long arr[100005];
long long  partition(int left, int right){
	long long pivot = arr[left];
	while(left < right){
		while(left < right && arr[right] >= pivot) right--;
		arr[left] = arr[right];
		while(left < right && arr[left] <= pivot) left++;
		arr[right] = arr[left];
	}
	arr[left] = pivot; 
	return left;
}
void quicksort(int left, int right){
	if(left < right){
		long long pivot = partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}


long long temp[100005];
void mergeSort(int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right){
	int i, j, k;
	for(i = left; i <= right; i++){
		temp[i] = arr[i];
	}
	for(i = left, j = mid + 1, k = left; i <= mid && j <= right;){
		if(temp[i] <= temp[j]) arr[k++] = temp[i++];
		else arr[k++] = temp[j++];
	}
	while(i <= mid) arr[k++] = temp[i++];
	while(j <= right) arr[k++] = temp[j++];
} 
int main(){
//	freopen("aa.txt","r",stdin);

	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
//	¿ìÅÅ 
//	quicksort(0, n - 1);	

//	¹é²¢
	mergeSort(0, n - 1);	
	printf("%lld", arr[0]);
	for(i = 1; i < n; i++){
		printf(" %lld", arr[i]);
	}
	
	return 0;
}
