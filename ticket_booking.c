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

/*ADD TRAIN*/

void addTrain() {
    struct Train *t = malloc(sizeof(struct Train));

    printf("\nTrain Number: ");
    scanf("%d",&t->trainNo);

    if(findTrain(t->trainNo)){
        printf("Train already exists!\n");
        free(t);
        return;
    }

    printf("Train Name: ");
    scanf(" %[^\n]",t->trainName);

    printf("AC Seats: ");
    scanf("%d",&t->totalAC);

    printf("Sleeper Seats: ");
    scanf("%d",&t->totalSL);

    printf("RAC Seats: ");
    scanf("%d",&t->totalRAC);

    t->availableAC=t->totalAC;
    t->availableSL=t->totalSL;
    t->availableRAC=t->totalRAC;

    t->nextACSeat=t->nextSLSeat=1;

    t->freeACCount=0;
    t->freeSLCount=0;

    t->confirmedHead=NULL;
    t->racHead=t->racTail=NULL;
    t->waitingHead=t->waitingTail=NULL;

    t->next=head;
    head=t;

    printf("Train Added!\n");
}

/*QUEUE*/

struct Passenger* popQueue(struct Passenger **head, struct Passenger **tail){
    if(!(*head)) return NULL;

    struct Passenger *temp=*head;
    *head=temp->next;

    if(!(*head)) *tail=NULL;

    temp->next=NULL;
    return temp;
}

struct Passenger* removeFromList(struct Passenger **head, struct Passenger **tail, int pnr){
    struct Passenger *curr=*head,*prev=NULL;

    while(curr){
        if(curr->pnr==pnr){
            if(prev) prev->next=curr->next;
            else *head=curr->next;

            if(tail && curr==*tail) *tail=prev;

            curr->next=NULL;
            return curr;
        }
        prev=curr;
        curr=curr->next;
    }
    return NULL;
}

/*BOOK*/

void bookTicket(){
    int trainNo,type;
    printf("\nTrain No: ");
    scanf("%d",&trainNo);

    struct Train *t=findTrain(trainNo);
    if(!t){
        printf("Train Not Found!\n");
        return;
    }

    struct Passenger *p=malloc(sizeof(struct Passenger));
    p->pnr=globalPNR++;

    printf("Name: ");
    scanf(" %[^\n]",p->name);

    printf("Age: ");
    scanf("%d",&p->age);

    if(p->age < 12){
        char ch;
        printf("Guardian present? (y/n): ");
        scanf(" %c",&ch);

        if(ch=='y'||ch=='Y'){
            printf("Guardian Name: ");
            scanf(" %[^\n]",p->guardian);
        } else {
            printf("Booking cancelled\n");
            free(p);
            return;
        }
    } else strcpy(p->guardian,"N/A");

    printf("Seat Type (1=AC,2=Sleeper): ");
    scanf("%d",&type);
    p->seatType=type;
