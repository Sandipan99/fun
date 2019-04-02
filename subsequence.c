#include<stdio.h>

int main(){
    int arr[20];
    int i,n;
    int sum,intm;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    // insert elements to array
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the sum which you want to check\n");
    scanf("%d",&sum);

    int s = 0, e = 0; // s and r holds the starting and the ending positions of the subsequence
    intm = arr[e];
    while(1){
       while(intm<sum){
        e++;
        if(e==n-1)
            break;
        intm+=arr[e];
       }
       if(intm==sum){
        printf("subsequence found -- positions are %d,%d\n",s,e);
        break;
       }
       else{
        while(intm>sum){
            intm-=arr[s];
            s++;
            if(s==n-1)
                break;
        }
        if(intm==sum){
            printf("subsequence found -- positions are %d,%d\n",s,e);
            break;
        }
       }
       if((e==n-1)||(s==n-1)){
        printf("No such subsequence found");
        break;
       }
    }

    return 0;
}