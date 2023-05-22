#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* charToMorse(char currentChar){
  int i;
  char *morse[36][7] = { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}, {"-----"} };
  char *alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  

  if (currentChar == ' '){
    return " ";
  }
  else if (isalnum(currentChar)){
    currentChar = toupper(currentChar);
    for(i = 0; i < strlen(alphanum); i++){
      if (currentChar == alphanum[i]){
        return *morse[i];
      }
    }
  }
  return NULL;
}

//turn all text into morse codes

int main(int argc, char *argv[]) {
    //printf("\a\a\a");
    if (argc == 1){
      printf("Please give something\n");
      return 1;
    }

    // Copy strings into our array
    int max_strings = argc-1;
    int string_lenght = 15;
    char strings[max_strings][string_lenght];
    for (int j = 1; j < argc; j++){
      strcpy(strings[j-1], argv[j]);
    }

    // List and print all strings
    for (int i = 0; i < (argc-1); i++) {
        if (strlen(strings[i]) != 1) {
          for (int j = 0; j < strlen(strings[i]); j++) {
            printf("%s\n",charToMorse(strings[i][j]));
          }
        } 
        else {
            printf("%s\n", charToMorse(*strings[i]));          
        }
    }

    return 0;

  

}


