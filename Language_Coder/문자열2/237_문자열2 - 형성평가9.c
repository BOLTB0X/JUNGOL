#include <stdio.h> 
#include <string.h> 

int main(void) { 
	int num,i; 
	float f; 
	char arr[30],tmp[100]={0,};

	scanf("%d %f %s",&num,&f,arr); 
	sprintf(tmp,"%d%.3f%s",num,f,arr); 
	
	for(i = 0; i<strlen(tmp)/2; i++) 
		printf("%c",tmp[i]); 


	if(strlen(tmp)%2) {
		printf("%c",tmp[i++]); 

	printf("\n"); 

	for(; i<strlen(tmp); i++) 
		printf("%c",tmp[i]); 
	return 0; 
}
