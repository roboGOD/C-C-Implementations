#include<stdio.h>  
#include<string.h> 
#include<stdlib.h> 

char* encrypt(char *plaintext,char key_value[])
{     
      int i,j=0;
      char *cipher_text;
      cipher_text = malloc(256);
      for(i = 0; i < strlen(plaintext); i++)  
      {  
            cipher_text[i] = ((plaintext[i] - 97) + (key_value[j] - 97))%26 + 97;  
            j = (j + 1)%strlen(key_value);  
      }  
      return cipher_text;
}
char* decrypt(char *cipher_text,char key_value[])
{
      int i,j=0;
      char *plaintext;
      plaintext = malloc(256);
      for(i = 0; i < strlen(cipher_text); i++)
      {
                  plaintext[i] = ((cipher_text[i] - 97) - (key_value[j] - 97) + 26 )%26 + 97;
                  j = (j + 1)%strlen(key_value);
      }
      return plaintext;
}
int main()  
{  
      char *plaintext, key_value[20], * cipher_text;  
      int i, j = 0;  
      plaintext = malloc(256);
      printf("\nEnter Plain-Text to Encrypt:\t");  
      scanf("%[^\n]255s", plaintext);  
      while ((getchar()) != '\n');
      printf("\nEnter key value:\t");
      scanf("%[^\n]s", key_value);  
      cipher_text = encrypt(plaintext,key_value);
      printf("\nPolyalphabetic Cipher Text:\t%s\n", cipher_text);  
      plaintext = decrypt(cipher_text,key_value);
      printf("\nAfter Decrytion : \t%s\n",plaintext);
      return 0;
}