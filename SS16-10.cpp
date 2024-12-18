#include<stdio.h>
#include<stdlib.h>
void xoaPhanTu(int *arr, int *length); 
int main(){
	int *arr;
	int length; 
	printf("Moi ban nhap so phan tu: ");
	scanf("%d", &length);
	arr=(int*)malloc(length*sizeof(int));
	xoaPhanTu(arr, &length);
	free(arr); 
	return 0; 
} 

void xoaPhanTu(int *arr, int *length){
	int addIndex;
	printf("Moi ban nhap vi tri phan tu muon xoa: ");
	scanf("%d", &addIndex);
	if(addIndex>0||addIndex<*length){
		for(int i= addIndex;i<*length; i++){
			arr[i]=arr[i+1];
			 
		} 
		*length--;
		printf("Cac phan tu sau khi xoa la: ");
		for(int i=0; i<*length; i++){
			printf("%d", arr[i]);
		}		
	}else{
		printf("\n khong hop le."); 
	} 
	}   
