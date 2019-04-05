#include<stdio.h>
#include<string.h>


int main(int argc, char* argv[]){

    char s[100];
    printf("Enter the string you want to reverse\n");
    scanf("%s",s);
    printf("Entered string is - %s\n",s);

    char *begin, *end, temp;
    int i;
    int len = strlen(s);
    begin = s;
    end = s;

    for(i=0;i<len-1;i++)
        end++;


    for(i=0;i<len/2;i++){
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }

    printf("The reversed string is %s\n",s);

    return 0;
}