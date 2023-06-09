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

void playSound(char* morse) {
  for (int i = 0; i < strlen(morse); i++){
    if (morse[i] == '.'){
      system("aplay -q dottest.wav");
    }
    else if (morse[i] == '-'){
      system("aplay -q linetest.wav");
    }
  }
}

//turn all text into morse codes

int main(int argc, char *argv[]) {

    if (argc == 1){
      char output[300];
      char temp[30];
      memset(output,0,sizeof(output));
      while (1)
      {
        scanf("%s",temp);
        strcat(output,temp);
        strcat(output," ");
        if (temp[strlen(temp)-1] == '.'){
          break;
        }
      }
      for (int i = 0; i < strlen(output); i++){
          puts(charToMorse(output[i]));
          playSound(charToMorse(output[i]));
      }
      return 0;
    }
    else if (strcmp(argv[1],"--file") == 0 && argc == 3){
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
          playSound(charToMorse(ch));
      }
      printf("\n");
      fclose(file);
      return 0;
    }
    else if (strcmp(argv[1],"--text") == 0 && argc > 2){
      int max_strings = argc-2;
      int string_lenght = 15;
      char strings[max_strings][string_lenght];
      for (int j = 2; j < argc; j++){
        strcpy(strings[j-2], argv[j]);
      }
      for (int i = 0; i < (argc-2); i++) {
          if (strlen(strings[i]) != 1) {
            for (int j = 0; j < strlen(strings[i]); j++) {
              puts(charToMorse(strings[i][j]));
              playSound(charToMorse(strings[i][j]));
            }
          } 
          else {
              puts(charToMorse(*strings[i]));
              playSound(charToMorse(*strings[i]));        
          }
          printf("\n");
      }
      return 0;
    }
    else if (strcmp(argv[1],"--help") == 0){
      printf("\n");
      printf("  --text <text input> : \tTurns the parameter you give to a morse code");
      printf("\n  --file <filename.txt> : \tReads from the given filename\n");
      printf("  <no paramater> : \t\tTakes input from console until '.' given\n");
      printf("\n");
    }
    else {
      printf("Invalid parameter. For help use --help\n");
      return 1;
    }

  
  return 0;
}


