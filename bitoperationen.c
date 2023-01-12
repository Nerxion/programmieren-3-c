#include <stdio.h>

/*
    Eingabe: zwei ganze Zahlen a und b in binärer Darstellung
*/


void schreibbit(unsigned z) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", (z & 1<<i) != 0);
    }
    printf("\n");
}

unsigned liesbit(void) {
    char eingabe[16];
    int i=0;
    unsigned int ergebnis=0;

    scanf("%s", eingabe);

    for(i = 0; eingabe[i] != '\0'; i++) {
        if (eingabe[i] == '1') {
            ergebnis = (ergebnis << 1) | 1;
        }
        else if (eingabe[i] == '0') {
            ergebnis = (ergebnis << 1);
        }
    }
    
    printf("Umgerechnet: %u\n", ergebnis);
    return ergebnis;
}

int main(void) {
    unsigned int a, b, dies, das, jenes;

    a = liesbit();
    b = liesbit();

    dies = a & b; /* und */
    das = a | b; /* oder */
    jenes = a ^ b; /* x or (entweder oder) */

    printf("a & b = ");
    schreibbit(dies);
    printf("a | b = ");
    schreibbit(das);
    printf("a ^ b = ");
    schreibbit(jenes);

    return 0;
}