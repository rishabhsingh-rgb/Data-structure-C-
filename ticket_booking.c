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
