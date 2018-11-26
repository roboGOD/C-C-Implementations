#include<stdio.h>  
#include<string.h> 
#include<stdlib.h> 

int* sortedKeys(char temp2[])
{
      int *sort = malloc(sizeof(int)*strlen(temp2));
      char temp[20];
      int i,j,index;
      for(i = 0;i<strlen(temp2);i++)
            temp[i] = temp2[i];
      for(j = 0; j<strlen(temp); j++ ) 
      {
            for(i = 0; i<strlen(temp); i++)
                  if(temp[i] < temp[index]) 
                        index = i;
            temp[index] = 123;
            sort[index] = j;
      }
      return sort;
}

char* encrypt(char *plaintext,char key_value[])
{     
      int row, col = strlen(key_value), msglen = strlen(plaintext);
      char mat[20][20];
      int *sortedKey;
      char *cipher_text = malloc(strlen(plaintext));
      int i,j,k;
      
      row = msglen/col;
      if(msglen%col != 0)
            row += 1;
      sortedKey = sortedKeys(key_value);
      k = 0;
      printf("\n");
      for(i=0;i<row;i++) 
      {
            for(j=0;j<col;j++) 
            {
                  if(k<msglen)
                        mat[i][j] = plaintext[k++];
                  else
                        mat[i][j] = '_';
                  printf("%c ",mat[i][j]);
            }
            printf("\n");
      }
      k = 0;
      for(i=0;i<col;i++) 
            for(j=0;j<row;j++) 
                  cipher_text[k++] = mat[j][sortedKey[i]];
      return cipher_text;
}
char* decrypt(char *cipher_text,char key_value[])
{
      int row, col = strlen(key_value), msglen = strlen(cipher_text);
      char mat[20][20];
      int *sortedKey = malloc(sizeof(int)*strlen(key_value));
      char *plaintext = malloc(strlen(cipher_text));
      int i,j,k;
      
      row = msglen/col;
      sortedKey = sortedKeys(key_value);
      k = 0;
      for(i=0;i<col;i++) 
            for(j=0;j<row;j++)
                  mat[j][sortedKey[i]] = cipher_text[k++];
      k = 0;
      for(i=0;i<row;i++) 
            for(j=0;j<col;j++) 
                  if(mat[i][j] != '_')
                        plaintext[k++] = mat[i][j];
                  else 
                        break;            
      return plaintext;
}
int main()  
{  
      char *plaintext, key_value[20], * cipher_text;  
      int i, j = 0;  
      plaintext = malloc(256);
      cipher_text = malloc(256);
      printf("\nEnter Plain-Text to Encrypt:\t");  
      scanf("%[^\n]255s", plaintext);  
      while ((getchar()) != '\n');
      printf("\nEnter key value:\t");
      scanf("%[^\n]s", key_value);  
      cipher_text = encrypt(plaintext,key_value);
      printf("\nCipher Text:\t%s\n", cipher_text);  
      plaintext = decrypt(cipher_text,key_value);
      printf("\nAfter Decrytion : \t%s\n",plaintext);
      return 0;
}