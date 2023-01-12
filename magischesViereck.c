#include <stdio.h>

/*
    Eingabe: ungerade Zahl zwischen 1 und 9
*/


int mod(int z, int n) {
    if (z < 0) return (z % n) + n; /* Modulo wird anders berechnet, wenn die Zahl negativ ist */
    return z % n;
}

int main(void) {
    int n = 0, zaehler = 1, i = 0, j = 0;
    int array[9][9] = {0};

    printf("Ungerade Zahl zw. 1 und 9 angeben: ");
    while(n % 2 == 0 || n > 9 || n < 1) scanf("%d", &n); /* scannt so lange, dass die Zahl nicht gerade, kleiner als 1 oder größer als 9 ist */

    i = j = n/2;

    while(array[i][j] != 1) { /* Abbruchbedingung: am Ende landet man immer auf der Start-1 */
        array[i][j] = zaehler;
        zaehler++;
        i = mod(i + 1, n);
        j = mod(j - 1, n);
        if (array[i][j] != 0) { /* falls man auf ein schon belegtes Feld trifft, soll man sich anders bewegen */
            i = mod(i + 1, n);
            j = mod(j + 1, n);  
        } 
    }

    for (i = 0; i < n; i++) { /* Ausgabe */
        for (j = 0; j < n; j++) {
            printf("%3d", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}