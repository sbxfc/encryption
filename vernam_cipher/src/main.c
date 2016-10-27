#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encipher();
void decipher();

int main(){

  int choice;
  while (1) {
      printf("1. Encrypt Text\n");
      printf("2. Decrypt Text\n");
      printf("3. Exit\n");
      printf("Enter your choice : ");
      scanf("%d" ,&choice);
      fflush(stdin);
      if(choice == 3){
        exit(0);
      }
      else if(choice == 1){
        encipher();
      }
      else if(choice == 2){
        decipher();
      }
      else{
        printf("Please Enter Valid Option.");
      }
  }

  return 0;
}

/*加密函数*/
void encipher()
{
     unsigned int a,b;
     char input[257],key[33];

     printf("Enter Text to be Encrypted [Max. 256 characters/ only alphabets]:\n");
     scanf("%s", input);
     fflush(stdin);

     printf("Enter Encryption Key [Max. 32 Characters/ only aphabets]:\n");
     scanf("%s", key);
     fflush(stdin);

     printf("Result:\n");
     for(a=0,b=0;a<strlen(input);a++,b++)
     {
          if(b >= strlen(key)){
               b=0;
          }
          printf("%c",65+(((toupper(input[a])-65)+(toupper(key[b])-65))%26));
     }
     printf("\n");
}

/*解密函数*/
void decipher()
{
     unsigned int a,b;
     char input[257],key[33];
     int value;

     printf("Enter Text to be Decrypted [Max. 256 characters/ only alphabets]:\n");
     scanf("%s", input);
     fflush(stdin);

     printf("Enter Decryption Key [Max. 32 Characters/ only aphabets]:\n");
     scanf("%s", key);
     fflush(stdin);

     printf("Result: ");
     for(a=0,b=0;a<strlen(input);a++,b++)
     {
          if(b>=strlen(key)){
               b=0;
          }

          value = (toupper(input[a])-64)-(toupper(key[b])-64);
          if( value < 0){
               value = 26 + value;
          }
          printf("%c",65 + (value % 26));
     }
     printf("\n");
}
