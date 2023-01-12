#include <stdio.h>
#include <string.h>

/*
    Eingabe: beliebiger Text
*/


void stringVer(void) {
    char string[300];
    int i = 0, uebrig;

    fgets(string, 300, stdin);
    for (i; i < strlen(string); i++) {
        if (string[i] > 64 && string[i] < 78) {
            string[i] = string[i] + 13;
        }
        else if (string[i] > 77 && string[i] < 91) {
            uebrig = 91 - string[i];
            uebrig = 13 - uebrig;
            string[i] = 65 + uebrig;
        }
        else if (string[i] > 96 && string[i] < 110) {
            string[i] = string[i] + 13;
        }
        else if (string[i] > 109 && string[i] < 123) {
            uebrig = 123 - string[i];
            uebrig = 13 - uebrig;
            string[i] = 97 + uebrig;
        }
    }

    printf("%s", string);
}

char charVer(char c) {
    int uebrig;

    if (c > 64 && c < 78) {
        c = c + 13;
    }
    else if (c > 77 && c < 91) {
        uebrig = 91 - c;
        uebrig = 13 - uebrig;
        c = 65 + uebrig;
    }
    else if (c > 96 && c < 110) {
        c = c + 13;
    }
    else if (c > 109 && c < 123) {
        uebrig = 123 - c;
        uebrig = 13 - uebrig;
        c = 97 + uebrig;
    }

    return c;
}

int main(void) {
    char c;
    
    while (scanf("%c", &c) != EOF){
        printf("%c", charVer(c));
    };

    return 0;
}