#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Eingabe: Wort (+ EOF)
*/

enum {LEN=20};

int in(char c, char liste[]){
    int i = 0;
    for (i = 0; i < strlen(liste); i++) {
        if (c == liste[i]) {
            return 1;
        }
    }
    return 0;
}

char* soundex(const char s[LEN], char res[7]) {
    int i = 0, j = 0, stelle = 0;
    char bfpv[] = "bfpv", cgjkqsxz[] = "cgjkqsxz", dt[] = "dt", mn[] = "mn";

    res[0] = toupper(s[0]);
    stelle = 1;
    for (i = 1; i < LEN; i++) {
        if (stelle < 7) {
            if (in(s[i], bfpv)) {
                if (res[stelle-1] != '1') {
                    res[stelle] = '1';
                    stelle++;
                } 
            }
            else if (in(s[i], cgjkqsxz)) {
                if (res[stelle-1] != '2') {
                    res[stelle] = '2';
                    stelle++;
                } 
            }
            else if (in(s[i], dt)) {
                if (res[stelle-1] != '3') {
                    res[stelle] = '3';
                    stelle++;
                } 
            }
            else if (s[i] == 'l') {
                if (res[stelle-1] != '4') {
                    res[stelle] = '4';
                    stelle++;
                } 
            }
            else if (in(s[i], mn)) {
                if (res[stelle-1] != '5') {
                    res[stelle] = '5';
                    stelle++;
                } 
            }
            else if (s[i] == 'r') {
                if (res[stelle-1] != '6') {
                    res[stelle] = '6';
                    stelle++;
                } 
            }
        }
    }
    for (i = stelle; i < 6; i++) {
        res[stelle] = '0';
        stelle++;
    }
    res[stelle] = '\0';
    return res;
}

int main(void) {
    char s[LEN] = {0}, res[7];

    printf("Eingabe: \n");
    while(scanf("%s", s) != EOF) {
        printf("%s\n", soundex(s, res));
    }

    return 0;
}