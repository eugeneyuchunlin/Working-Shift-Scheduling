// #include<stdio.h>

// int main(){
//     int x,result;
//     printf("please input a number : ");
//     result = scanf("%d",&x);
//     if(result == EOF){
//         printf("EOF\n");
//     }
//     else{
//         printf("x = %d\n",x);
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>

int main(){
  char key[100];
  while(EOF!=scanf("%s",key)){

  // scanf("%s", key);

  if(strcmp(key, "apple") == 0){
    printf("蘋果\n");
  }

  else if(strcmp(key, "banana") == 0){
    printf("香蕉\n");
  }

  else if(strcmp(key, "orange") == 0){
    printf("柳丁\n");
  }

  else if(strcmp(key,"grape") == 0){
    printf("葡萄\n");
  }

  else if(strcmp(key,"peach") == 0){
    printf("桃子\n");
  }

  else if(strcmp(key, "mango") == 0){
    printf("芒果\n");
  }

  else if(strcmp(key, "kiwifruit") == 0){
    printf("奇異果\n");
  }

  else if(strcmp(key, "cherry") == 0){
    printf("櫻桃\n");
  }

  else if(strcmp(key, "pineapple") == 0){
    printf("鳳梨\n");
  }

  else if(strcmp(key, "lemon") == 0){
    printf("檸檬\n");
  }

  else if(strcmp(key,"0") == 0) break;
  
  else
    printf("李公蝦毀!?\n");
  }
}