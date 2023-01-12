#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Kommandozeilenparameter: Menge an wie oft durch die Namen iteriert werden soll (z.B. "ene mene mu" für 3x)
    Eingabe: Namen der Knoten/Personen (+ EOF)
*/


struct Person {
    char name[25];
    struct Person *next;
};
typedef struct Person *personZ;


personZ einfuegen(personZ starter, char name[25]) {
    personZ merkzeiger = NULL;
    struct Person *newPerson = malloc(sizeof(struct Person));

    if (starter == NULL) { /* erste Person abfangen */
        strcpy(newPerson->name, name);
        newPerson->next = newPerson;
        return newPerson;
    }

    strcpy(newPerson->name, name);

    merkzeiger = starter->next;
    starter->next = newPerson;
    newPerson->next = merkzeiger;

    return newPerson;
}

personZ rauswerfen(personZ starter, int argc) {
    int i = 0;
    personZ merker;

    for (i = 1; i < argc; i++) { /* Für das Durchlaufen: argc = Argumentenlänge, Programmname included. Was wir also brauchen: argc-1 (bzw argc, wenn man bei 1 anfängt)*/
        merker = starter;
        starter = starter->next;
        printf("Aktuell: %s, nächster wäre: %s\n", starter->name, starter->next->name);
    }
    printf("Wird rausgeworfen: %s!\n", starter->name);
    printf("\n");

    merker->next = starter->next;
    free(starter);

    return merker;
}


int main(int argc, char *argv[]) {
    char eingabe[25];

    struct Person *starter = NULL;

    if (argc > 1) {
        printf("Namen eingeben: \n");
        while(scanf("%s", eingabe) != EOF) {
            starter = einfuegen(starter, eingabe);
        }
        printf("\n");

        while (starter->next != starter) {
            starter = rauswerfen(starter, argc);
        }
        printf("Muss spülen: %s!\n", starter->name);
        printf("\n");

        free(starter);
    }
    else {
        printf("%s", "Bitte Argumente beim Programmaufruf mitgeben (mind 1)!\n");
    }
    
    return 0;
}
