#include<stdio.h>
#include<math.h>
 
int main(){
  int N,num,i;
  int a[210];
  scanf("%d",&N);
  for(int l=0;l<N;l++){
  	scanf("%d",a);
  }
  
  for(i=0;i<pow(10,9);i++){
    num=0;
    for(int j=0;j<N;j++){
    if(a[j]%2==0){
     	num++; 
    }else{
     break; 
    }
    }
    if(num==N){
     //2で割る
      for(int k=0;k<N;k++){
        a[k]=a[k]/2;
      }
    }else{
    	break;
      
    }
    
  }
  
  
  
  printf("%d",i);
 return 0; 
}