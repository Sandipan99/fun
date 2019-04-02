#include<stdio.h>

void heapify(int* k_max, int k, int i){
	int left = 2*i;
	int right = 2*i+1;
	int min = 0;
	int temp;
	
	if(left<=k && k_max[left]<k_max[i])
		min = left;
	else	min = i;

	if(right<=k && k_max[right]<k_max[min])
		min = right;
	if(min!=i){
		temp = k_max[i];
		k_max[i] = k_max[min];
		k_max[min] = temp;
		heapify(k_max,k,min);
	}
}

void build_heap(int* k_max, int k){
	int i;
	for(i=k/2;i>=1;i--)
		heapify(k_max,i,k);
}

int main(int argc, char* argv[]){
	int arr[20];
	int i,n,k,flag,min;
	printf("Enter the number the elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the %d th element\n",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter the value of k\n");
	scanf("%d",&k);
	int k_max[k+1];

	if(k>n)
		printf("Enter a k less than n\n");
	
	for(i=0;i<n;i++){
		if(i<k){
			k_max[i+1] = arr[i];
			flag=1;
		}
		else{
			if(flag==1){
				build_heap(k_max,k);
				flag=0;
			}
			else{
				min = k_max[1];
				if(arr[i]>min){
					k_max[1] = arr[i];
					heapify(k_max,k,1);
				}	
			}
		}
	}

	printf("The %d largest elements are -\n",k);
	for(i=1;i<=k;i++)
		printf("%d,",k_max[i]);
	return 0;
}
