#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STRUCTURES*/

struct Passenger {
    int pnr;
    char name[50];
    int age;
    char guardian[50];

    int seatType;
    int seatNo;
    char coach[5];

    char status[20];

    struct Passenger *next;
};

struct Train {
    int trainNo;
    char trainName[50];

    int totalAC, availableAC, nextACSeat;
    int totalSL, availableSL, nextSLSeat;
    int totalRAC, availableRAC;

    // Seat reuse
    int freeACSeats[100];
    int freeACCount;

    int freeSLSeats[100];
    int freeSLCount;

    struct Passenger *confirmedHead;
    struct Passenger *racHead, *racTail;
    struct Passenger *waitingHead, *waitingTail;

    struct Train *next;
};

struct Train *head = NULL;
int globalPNR = 1000;

/*UTILIY*/

struct Train* findTrain(int trainNo) {
    struct Train *t = head;
    while (t && t->trainNo != trainNo)
        t = t->next;
    return t;
}

int compareIgnoreCase(char a[], char b[]) {
    int i=0;
    while(a[i] && b[i]) {
        char c1 = (a[i]>='A'&&a[i]<='Z')?a[i]+32:a[i];
        char c2 = (b[i]>='A'&&b[i]<='Z')?b[i]+32:b[i];
        if(c1!=c2) return 0;
        i++;
    }
    return (a[i]=='\0' && b[i]=='\0');
}
