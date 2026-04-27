#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================= STRUCTURES ================= */

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
