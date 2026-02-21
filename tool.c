#include"stdio.h"
int atoi_mine(const char *str) {
    int i=0,num=0;
    while(str[i]!= '\n' ||str[i]!= '\r' || str[i]!= ' ' ){     
        int temp = str[i]-'0';
        num = num*10+temp;
        i++;  
        
    }
    return num;
}