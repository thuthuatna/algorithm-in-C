#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int next_permutation(int n, char **s){
	//kiem tra xem array da permutations den phan tu cuoi cung hay chua
	// i-1 la phan tu can tim
	int i=n-1;
	while(i>0 && strcmp(s[i-1],s[i])>=0){
		i--;
		if(i<=0){
			return 0;
		}
	}
	// 1. tim tu phai qua trai, hoan vi co chi so dau tien thoa man aj<aj+1
	int j=n-1;
	while(strcmp(s[i-1],s[j])>=0){
		j--;
	}
	// doi cho 2 phan tu tim duoc la s[i-1] va s[j]
	char *temp = s[j];
	s[j]=s[i-1];
	s[i-1] = temp;
	
	for(i;i<n;i++){
		for(int k=i;k<n;k++){
			if(strcmp(s[i],s[k])>=0){
				temp = s[i];
				s[i]=s[k];
				s[k]=temp;
			}
		}
	}
	
	return 1;
}

int main(){
	int n;
	char **arr;
	scanf("%d",&n);
	arr = (char **)malloc(n*sizeof(char*)); 
	for(int i=0;i<n;i++){
		arr[i] = (char *)calloc(11,sizeof(char));
		scanf("%s",*(arr+i)); 
	}

	do{
		for(int i=0;i<n;i++){
			printf("%s%c",arr[i],i == n-1?'\n':' ');
		}		
	}while(next_permutation(n,arr));

	for(int i=0;i<n;i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}
