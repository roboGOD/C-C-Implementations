#include <stdio.h>  
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>  
void playfair(char ch1, char ch2, char key[5][5], char *cipher) {  
    int i, j, w, x, y, z;  
    static int count=0;
    for (i = 0; i < 5; i++) {  
        for (j = 0; j < 5; j++) {  
            if (ch1 == key[i][j]) {  
                w = i;  
                x = j;  
            } else if (ch2 == key[i][j]) {  
                y = i;  
                z = j;  
            }  
        }  
    }    
    if (w == y) {  
        x = (x + 1) % 5;  
        z = (z + 1) % 5;   
        cipher[count++] = key[w][x];
        cipher[count++] = key[y][z];  
    } else if (x == z) {  
        w = (w + 1) % 5;  
        y = (y + 1) % 5;   
        cipher[count++] = key[w][x];
        cipher[count++] = key[y][z];  
    } else {    
        cipher[count++] = key[w][z];
        cipher[count++] = key[y][x];  
    }    
}  
void main() {  
    int i, j, k = 0, l, m = 0, n;  
    char key[5][5], keyminus[25], keystr[10], str[25] = {  
        0  
    };  
    char * cipher_text = malloc(256);
    char alpa[26];
    for(i = 0;i<26;i++) 
        alpa[i] = 65 + i;
    printf("\nEnter key:");  
    scanf("%[^\n]255s", keystr);
    while ((getchar()) != '\n');  
    printf("\nEnter the plain text:");  
    scanf("%[^\n]255s", str);  
    n = strlen(keystr);   
    for (i = 0; i < n; i++) {   
        keystr[i] = toupper(keystr[i]);
        if (keystr[i] == 'J') keystr[i] = 'I';    
    }  
    for (i = 0; i < strlen(str); i++) {  
        str[i] = toupper(str[i]);
        if (str[i] == 'J') str[i] = 'I';    
    }    
    j = 0;  
    for (i = 0; i < 26; i++) {  
        for (k = 0; k < n; k++) {  
            if (keystr[k] == alpa[i]) break;  
            else if (alpa[i] == 'J') break;  
        }  
        if (k == n) {  
            keyminus[j] = alpa[i];  
            j++;  
        }  
    }    
    k = 0;  
    for (i = 0; i < 5; i++) {  
        for (j = 0; j < 5; j++) {  
            if (k < n) {  
                key[i][j] = keystr[k];  
                k++;  
            } else {  
                key[i][j] = keyminus[m];  
                m++;  
            }  
            printf("%c ", key[i][j]);  
        }  
        printf("\n");  
    }  
    printf("\n\nEntered text :%s\nCipher Text :", str);  
    for (i = 0; i < strlen(str); i++) {  
        if (str[i + 1] == '\0') playfair(str[i], 'X', key,cipher_text);  
        else {    
            if (str[i] == str[i + 1]) playfair(str[i], 'X', key,cipher_text);  
            else {  
                playfair(str[i], str[i+1], key,cipher_text);  
                i++;  
            }  
        }  
    }  
    printf("%s\n\n",cipher_text);
}