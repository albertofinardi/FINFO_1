#include <stdio.h>
#define MAX 30

int main(){

	char str[MAX+1];
	int minLen, maxLen, currLen, i;

	scanf("%s", str);

	for(i=0, minLen=0, maxLen=0; str[i]!='\0'; i++){
		for(currLen=0; str[i]>='0'&& str[i]<='9'; currLen++, i++);

			if(currLen>0){
				if(currLen>=maxLen)
					maxLen = currLen;
				if(minLen==0 || currLen<minLen){
					minLen=currLen;
				}
				i--;
			}
	}

	printf("%d %d\n", minLen, maxLen);
	return 0;
}