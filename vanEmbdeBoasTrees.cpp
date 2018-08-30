#include <iostream>
#include <math.h>

void insert(int x, int u, int *array, int *summary, int *max_min){
  int clus_num = x/u;
  int pos = x%u;
  int insert_pos = clus_num*u + pos;
  array[insert_pos]=1;
  summary[clus_num]=1;
  if (max_min[0]<x)
    max_min[0]=x;
  if (max_min[1]>x)
    max_min[1]=x;
}

int predecessor(int x, int u, int *array, int *summary, int *max_min){
  int i;
  if(x==max_min[1])
    return x;
  int clus_num = x/u;
  int pos = x%u;
  i = pos-1;
  while(clus_num>=0){
    if(summary[clus_num]>0){
      while(i>=0){
        if(array[clus_num*u+i]>0)
          return (clus_num*u+i);
        i--;
      }
    }
    clus_num--;
    i=u-1;
  }
  return 0;
}

int successor(int x, int u, int *array, int *summary, int *max_min){
  int i;
  if(x==max_min[0])
    return x;
  int clus_num = x/u;
  int pos = x%u;
  i = pos+1;
  while(clus_num<u+1){
    if(summary[clus_num]>0){
      while(i<u){
        if(array[clus_num*u+i]>0)
          return (clus_num*u+i);
        i++;
      }
    }
    clus_num++;
    i=0;
  }
  return 0;
}

int main(){
  int n,option,x,y; //n is the max element the data structure can handle
  std::cout<<"enter the upper bound of the element value"<<std::endl;
  std::cin>>n;
  int array[n+1];
  for(int i=0;i<n+1;i++)
    array[i] = 0;
  int cluster_size = (int)(pow(n,0.5))+1;
  int summary[cluster_size];
  for(int i=0;i<cluster_size;i++)
    summary[i] = 0;
  int max_min[2] = {-1,n+1};
  do{
    std::cout<<"What do you wish to do - 1. insert, 2. find max, 3. find min, 4. successor, 5. predecessor, 6. display, 7. exit"<<std::endl;
    std::cin>>option;
    if(option==7)
      break;
    switch(option){
      case 1:
        std::cout<<"enter the element you want to insert"<<std::endl;
        std::cin>>x;
        if (x>n)
          std::cout<<"you should enter a number less than or equal to"<<n<<std::endl;
        else{
          insert(x,cluster_size-1,array,summary,max_min);
        }
        break;

      case 2:
        std::cout<<"max element is"<<max_min[0]<<std::endl;
        break;

      case 3:
        std::cout<<"min element is"<<max_min[1]<<std::endl;
        break;

      case 4:
        std::cout<<"Enter the number you want to find successor for"<<std::endl;
        std::cin>>x;
        std::cout<< successor(x,cluster_size-1,array,summary,max_min) << std::endl;
        break;

      case 5:
        std::cout<<"Enter the number you want to find predecessor for"<<std::endl;
        std::cin>>x;
        std::cout<< predecessor(x,cluster_size-1,array,summary,max_min) << std::endl;
        break;

      case 6:
        for(int i=0;i<n+1;i++)
            std::cout<<array[i]<<",";
        std::cout<<std::endl;
        break;
    }
  }while(1);
  return 0;
}
