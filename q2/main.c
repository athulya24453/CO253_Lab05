#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int romanToInt(char s[])
{
    int n = 0;
    for (int i=0; i<strlen(s); i++){
        switch (s[i]){
            case 'I':
                if (s[i+1]=='V' || s[i+1]=='X'){
                    n--;
                }
                else {
                    n++;
                }
                break;

            case 'V':
                n+=5;
                break;

            case 'X':
                if (s[i+1]=='L'){
                    n-=10;
                }
                else{
                    n+=10;
                }
                break;

            case 'L':
                n+= 50;
                break;
        }
    }
    return n;
}

char* name(char* s){
    int i;
    int len;
    for (int i=0;i<strlen(s);i++){
        if (isspace(s[i])!=0){
            len=i;
            break;
        }

    }

    char* nameArr = malloc(len*sizeof(char));

    for (int j=0;j<len;j++){
        s[j]=nameArr[j];
    }
    return nameArr;
}

int number(char* s){
    int i;
    int len;
    for (int i=0;i<strlen(s);i++){
        if (isspace(s[i])!=0){
            len=i;
            break;
        }

    char* nArr = malloc((strlen(s)-(len+1))*sizeof(char));

    for (int j=len+1; j<strlen(s);j++){
        nArr[j-len-1]=s[j];
    }

    char numStr[2];

    strcpy(numStr, nArr);

    int numberAns = romanToInt(numStr);
    return numberAns;
}

char** ins_sort(char** arr,int size){
    for (int i = 0; i < size; i++){
        int fixnum=number(arr[i]);
        char* fixname=name(arr[i]);

        for (int j=i+1;j<size;j++){

            int comnum=number(arr[j]);

            char* comname=name(arr[j]);

            if (strcmp(fixname,comname) > 0){
                char* tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            else if (strcmp(fixname,comname) == 0){
                if(fixnum>comnum){
                    char* tmp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=tmp;
                }

            }
        }
    }
    return arr;

}


/*char** splitSentence(char* sentence, char delimiter, int* numSubstrings) {
  int i, j, k;
  int numDelimiters = 0;
  int sentenceLength = strlen(sentence);

  for (i = 0; i < sentenceLength; i++) {
    if (sentence[i] == delimiter) {
      numDelimiters++;
    }
  }

  char** substrings = (char**) malloc((numDelimiters + 1) * sizeof(char*));

  j = 0;
  for (i = 0; i < sentenceLength; i++) {
    if (sentence[i] == delimiter || i == sentenceLength - 1) {
      int substringLength = i - j + 1;
      char* substring = (char*) malloc(substringLength * sizeof(char));
      for (k = 0; k < substringLength - 1; k++) {
        substring[k] = sentence[j + k];
      }
      substring[k] = '\0';
      substrings[*numSubstrings] = substring;
      (*numSubstrings)++;
      j = i + 1;
    }
  }

  return substrings;
}*/

int compare_strings(const void* a, const void* b) {
  const char** str_a = (const char**) a;
  const char** str_b = (const char**) b;
  return strcmp(*str_a, *str_b);
}



int main()
{
    int n;
    scanf("%d",&n);
    char* matrix[n];
    for(int i=0;i<n+1;i++){
        char* string=calloc(1,sizeof(char));
        char character;

        while (scanf("%c",&character)==1){
            if(character== '\n'){
                break;
            }
            int len=strlen(string);
            string=realloc(string,len+1);
            *(string+len)=character;
            *(string+len+1)='\0';
        }
        if(i>0){
        matrix[i-1]=string;
        }

    }
    //prints input names

    // for(int i=0;i<n;i++){
    //     printf("%s\n",matrix[i]);
    // }
    char** matrix_sol=sorting(matrix,n);

    for(int i=0;i<n;i++){
        printf("%s\n",matrix_sol[i]);
    }

    return 0;
}
