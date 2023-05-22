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
  return " ";
}

//turn all text into morse codes

int main(int argc, char *argv[]) {
    if (argc == 1){
      printf("Please give something\n");
      return 1;
    }

    //read from file
    if (strcmp(argv[1],"--file") == 0 && argc > 2){
      char filename[20];
      strcpy(filename,argv[2]);
      FILE* file = fopen(filename, "r");
      if (file == NULL) {
          printf("Unable to open file: %s\n", filename);
          return 1;
      }
      int ch;
      while ((ch = fgetc(file)) != EOF) {
          puts(charToMorse(ch));
          //putchar('t');
      }
      printf("\n");
      fclose(file);
      return 0;
    }//read from terminal
    else if (strcmp(argv[1],"--text") == 0 && argc > 2){
      int max_strings = argc-2;
      int string_lenght = 15;
      char strings[max_strings][string_lenght];
      for (int j = 2; j < argc; j++){
        strcpy(strings[j-2], argv[j]);
      }
      // List and print all strings
      for (int i = 0; i < (argc-2); i++) {
          if (strlen(strings[i]) != 1) {
            for (int j = 0; j < strlen(strings[i]); j++) {
              puts(charToMorse(strings[i][j]));
            }
          } 
          else {
              puts(charToMorse(*strings[i]));        
          }
          printf("\n");
      }
      return 0;
    }
    
    
    
    

    

  

}


