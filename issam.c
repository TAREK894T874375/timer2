#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int second = 0;
int mn = 0;
int hours =0;
char s = '0';
char m ='0';
char h ='0';
void func_s(void);
void func_mn(void);
void func_hours(void);
int main (void){
 func_s();
 func_mn();
 func_hours();
}
void func_s (void){
   for (int i = 0; i < 60; i++)
   { 
     if (i>10){
          s = '\0';
     }else {s='0';}
     printf("%c%i : %c%i : %c%i\n",h,hours,m,mn,s,second);    
    sleep(1);
    system("cls");
    second ++;    
   }
   second = 0;  
}
void func_mn(void){
    mn ++;
    for (int i = 0; i < 60; i++)
    {
             if (i>10){
             m='\0';           }
             else{m='0';}
       printf("%c%i : %c%i : %c%i\n",h,hours,m,mn,s,second);
       sleep(1);
       func_s();
       mn++;
    }
    mn =0;   
}
void func_hours(void){
 hours ++;
 for (int i = 0; i < 60; i++)
 { 
         if (i>10){
          h='\0';}
          else{h='0';}
    printf("%c%i : %c%i : %c%i\n",h,hours,m,mn,s,second);
    sleep(1);
    func_mn();
    hours ++;   
 }
}