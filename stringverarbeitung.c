#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Kommandozeilenparameter: Wörter, die ersetzt werden sollen
    Eingabe: Satz, worin die Wörter ersetzt werden sollen (+ EOF)
*/

enum {LEN=200};

char* replaceWords(char *argv[], char *eingabe, int argc) {
    int i = 0;
    char *currCharArgv = NULL, *currCharEingabe = NULL;
    currCharEingabe = eingabe;
    
    for (i = 1; i < argc; i++) {
        currCharArgv = argv[i];
        currCharEingabe = eingabe;
        
        while(*currCharEingabe != '\0') {
            while (*currCharArgv != '\0' && *currCharEingabe != '\0') {
                if (tolower(*currCharArgv) == tolower(*currCharEingabe)) {
                    currCharArgv++;
                    currCharEingabe++;
                }
                else {
                    currCharEingabe++;
                }
            }
            if (*currCharArgv == '\0') {
                currCharArgv--;
                currCharEingabe--;
                while (tolower(*currCharArgv) == tolower(*currCharEingabe) && *currCharArgv != '\0' && *currCharEingabe != '\0') {
                    currCharArgv--;
                    currCharEingabe--;
                }
                currCharArgv += 2;
                currCharEingabe += 2;
                while (tolower(*currCharArgv) == tolower(*currCharEingabe) && *currCharArgv != '\0' && *currCharEingabe != '\0') {
                    *currCharEingabe = '*';
                    currCharArgv++;
                    currCharEingabe++;
                }
                currCharArgv--;
                currCharEingabe--;
            }
            currCharEingabe++;
        }
        
    }
    return eingabe;
}

int main(int argc, char *argv[]) {
    char eingabe[LEN] = {0};
    
    if (argc > 1) {
        printf("Eingabe: \n");
        while(fgets(eingabe, LEN-1, stdin)) {
            printf("%s\n", replaceWords(argv, eingabe, argc));
        }
    }
    else {
        printf("%s\n", "Bitte mit Argumenten aufrufen");
    }
    
    return 0;
}