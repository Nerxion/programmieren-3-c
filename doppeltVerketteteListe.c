#include <stdio.h>
#include <stdlib.h>

/*
    Kommandozeilenparameter: "Namen" der Knoten (gibt an, wie viele Knoten es werden)
*/

struct node {
    struct node *previous;
    struct node *next;
    void *data;
};
typedef struct node *nodep;


void printList(nodep lst){
    while(lst->next != NULL) {
        printf("%p\n", lst->data);
        lst = lst->next;
    }
    printf("%p\n", lst->data);
    printf("\n");
}

void printListReverse(nodep lst){
    while(lst->next != NULL) {
        lst = lst->next;
    }
    while(lst->previous != NULL) {
        printf("%p\n", lst->data);
        lst = lst->previous;
    }
    printf("%p\n", lst->data);
    printf("\n");
}


nodep insertAt(nodep lst, int pos, void *data){
    int i = 0;
    struct node *newnode = malloc(sizeof(struct node));
    nodep nextnode = NULL, startPointer = lst;

    if (lst == NULL) { /* Abfrage, ob Liste leer ist */
        newnode->data = data;
        newnode->next = NULL;
        newnode->previous = NULL;
        return newnode;
    }
    if (pos == 0) { /* Abfrage, ob an erster Stelle eingefügt werden soll */
        newnode->data = data;
        newnode->next = lst;
        newnode->previous = NULL;
        lst->previous = newnode;
        return newnode;
    }

    /* bis eine Stelle vor pos laufen  (und checken, ob pos positiv oder negativ ist und darauf reagieren)*/
    if (pos >= 0) {
        for (i = 0; i < pos-1; i++) { 
            if (lst->next != NULL) lst = lst->next;
        }     
    }
    else {
        while (lst->next != NULL) lst = lst->next;
        while (pos < -1) {
            if (lst->previous != NULL) lst = lst->previous;
            pos++;
        }
    }
    
    /* abspeichern, welches der aktuell nächste Node ist, falls der nicht NULL */
    if (lst->next != NULL) nextnode = lst->next; 

    newnode->data = data;
    lst->next = newnode;
    newnode->previous = lst;
    if (nextnode != NULL) { /* falls nächster Node nicht NULL */
        nextnode->previous = newnode;
        newnode->next = nextnode;
    } 
    else {
        newnode->next = NULL; /* sonst auf NULL zeigen lassen */
    }

    return startPointer;
}


nodep deleteAt(nodep lst, int pos) {
    int i = 0;
    nodep nextnode = NULL, previousnode = NULL, startPointer = lst;

    /* Abfrage, ob Liste NULL ist oder es nur ein Element in der Liste gibt */
    if (lst == NULL) {
        return NULL;
    }
    else if (lst->next == NULL && lst->previous == NULL) {
        free(lst);
        return NULL;
    }

    /* Durchlaufen, bis an pos angekommen bzw. -pos */
    if (pos >= 0) {
        for (i = 0; i < pos; i++) { 
            if (lst->next != NULL) lst = lst->next;
        }     
    }
    else {
        while (lst->next != NULL) lst = lst->next;
        while (pos < -1) {
            if (lst->previous != NULL) lst = lst->previous;
            pos++;
        }
    }
    
    if (lst->next != NULL && lst->previous != NULL) {
        nextnode = lst->next; 
        previousnode = lst->previous;
        nextnode->previous = previousnode;
        previousnode->next = nextnode;
    }
    if (lst->next != NULL && lst->previous == NULL) {
        nextnode = lst->next; 
        nextnode->previous = NULL;
        startPointer = nextnode; /* neuer Starter */
    }
    if (lst->next == NULL && lst->previous != NULL) {
        previousnode = lst->previous;
        previousnode->next = NULL;
    }

    free(lst);
    return startPointer;
}


nodep copyList(nodep lst) {
    struct node *copystarter = NULL;
    int i = 0;
    
    if (lst == NULL) {
        return NULL;
    }
    while (lst->next != NULL) {
        copystarter = insertAt(copystarter, i, lst->data);
        lst = lst->next;
        i++;
    }
    copystarter = insertAt(copystarter, i, lst->data);

    return copystarter;
}


void deleteList(nodep lst) { /* geht das so? */
    nodep merkzeiger = NULL;
    while (lst->next != NULL) {
        merkzeiger = lst;
        lst = lst->next;
        free(merkzeiger);
    }
    free(lst);
}


int main(int argc, char *argv[]) {
    struct node *starter = NULL;
    nodep copystarter = NULL;
    int i = 0;

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            starter = insertAt(starter, i, argv[i]);
        }

        printf("Anfangsliste: \n");
        printList(starter);
        
        copystarter = copyList(starter);
        printf("Kopierte Anfangsliste: \n");
        printList(copystarter);

        printf("Ausgabe rückwärts: \n");
        printListReverse(copystarter);

        deleteList(starter);
        deleteList(copystarter);
    }
    
    return 0;
}