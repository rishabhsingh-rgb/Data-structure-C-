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
    // CONFIRMED
    if(type==1 && t->availableAC>0){

        if(t->freeACCount>0)
            p->seatNo=t->freeACSeats[--t->freeACCount];
        else
            p->seatNo=t->nextACSeat++;

        sprintf(p->coach,"A%d",p->seatNo);
        t->availableAC--;

        strcpy(p->status,"CONFIRMED");
        p->next=t->confirmedHead;
        t->confirmedHead=p;
    }
    else if(type==2 && t->availableSL>0){

        if(t->freeSLCount>0)
            p->seatNo=t->freeSLSeats[--t->freeSLCount];
        else
            p->seatNo=t->nextSLSeat++;

        sprintf(p->coach,"S%d",p->seatNo);
        t->availableSL--;

        strcpy(p->status,"CONFIRMED");
        p->next=t->confirmedHead;
        t->confirmedHead=p;
    }
    else if(t->availableRAC>0){
        strcpy(p->status,"RAC");
        p->seatNo=0; strcpy(p->coach,"-");
        p->next=NULL;

        if(!t->racHead) t->racHead=t->racTail=p;
        else {t->racTail->next=p; t->racTail=p;}

        t->availableRAC--;
    }
    else{
        strcpy(p->status,"WAITING");
        p->seatNo=0; strcpy(p->coach,"-");
        p->next=NULL;

        if(!t->waitingHead) t->waitingHead=t->waitingTail=p;
        else {t->waitingTail->next=p; t->waitingTail=p;}
    }

    printf("PNR: %d Status: %s\n",p->pnr,p->status);
}

/*SEARCH TRAIN*/

void searchTrainByName(){
    char name[50];
    printf("Enter name: ");
    scanf(" %[^\n]",name);

    struct Train *t=head;
    while(t){
        if(compareIgnoreCase(t->trainName,name))
            printf("Found: %s (%d)\n",t->trainName,t->trainNo);
            printf("AC availabe: %d\n",t->availableAC);
            printf("SL availabe: %d\n",t->availableSL);
            printf("RAC availabe: %d\n",t->availableRAC);
        t=t->next;
    }
}

/*SEARCH PNR*/

void searchByPNR(){
    int pnr;
    printf("\nEnter PNR: ");
    scanf("%d",&pnr);

    struct Train *t=head;
    while(t){
        struct Passenger *p;

        p=t->confirmedHead;
        while(p){ if(p->pnr==pnr){ printf("CONFIRMED\n"); return;} p=p->next;}

        p=t->racHead;
        while(p){ if(p->pnr==pnr){ printf("RAC\n"); return;} p=p->next;}

        p=t->waitingHead;
        while(p){ if(p->pnr==pnr){ printf("WAITING\n"); return;} p=p->next;}

        t=t->next;
    }
    printf("Not found\n");
}

/*PRINT*/

void printTicket() {
    int pnr;
    printf("Enter PNR: ");
    scanf("%d",&pnr);

    struct Train *t=head;

    while(t){
        struct Passenger *p;

        p=t->confirmedHead;
        while(p){
            if(p->pnr==pnr){
                printf("\n===== RAILWAY TICKET =====\n");
                printf("PNR: %d\nTrain: %s\n",p->pnr,t->trainName);
                printf("Name: %s Age:%d\n",p->name,p->age);
                printf("Seat: %s Status: CONFIRMED\n",p->coach);
                return;
            }
            p=p->next;
        }
        t=t->next;
    }

    printf("PNR Not Found!\n");
}

/*CANCEL*/

void cancelTicket(){
    int pnr;
    printf("Enter PNR: ");
    scanf("%d",&pnr);

    struct Train *t=head;

    while(t){
        struct Passenger *p;

        // CONFIRMED
        p=removeFromList(&t->confirmedHead,NULL,pnr);
        if(p){
            if(p->seatType==1){
                t->availableAC++;
                t->freeACSeats[t->freeACCount++]=p->seatNo;
            } else {
                t->availableSL++;
                t->freeSLSeats[t->freeSLCount++]=p->seatNo;
            }

            printf("PNR %d cancelled (CONFIRMED)\n", pnr);

            free(p);

            // RAC→CONFIRMED
            struct Passenger *rac=popQueue(&t->racHead,&t->racTail);
            if(rac){
                strcpy(rac->status,"CONFIRMED");
                printf("RAC passenger PNR %d upgraded to CONFIRMED\n", rac->pnr);

                if(rac->seatType==1){
                    if(t->freeACCount>0)
                        rac->seatNo=t->freeACSeats[--t->freeACCount];
                    else
                        rac->seatNo=t->nextACSeat++;

                    sprintf(rac->coach,"A%d",rac->seatNo);
                    t->availableAC--;
                } else {
                    if(t->freeSLCount>0)
                        rac->seatNo=t->freeSLSeats[--t->freeSLCount];
                    else
                        rac->seatNo=t->nextSLSeat++;

                    sprintf(rac->coach,"S%d",rac->seatNo);
                    t->availableSL--;
                }

                rac->next=t->confirmedHead;
                t->confirmedHead=rac;

                // WAITING→RAC
                struct Passenger *w=popQueue(&t->waitingHead,&t->waitingTail);
                if(w){
                    strcpy(w->status,"RAC");
                    printf("Waiting passenger PNR %d moved to RAC\n", w->pnr);

                    w->next=NULL;
                    if(!t->racHead) t->racHead=t->racTail=w;
                    else {t->racTail->next=w; t->racTail=w;}
                }
            }
            return;
        }
        
        //RAC
        p=removeFromList(&t->racHead,&t->racTail,pnr);
        if(p){
            printf("PNR %d cancelled (RAC)\n", pnr);
            t->availableRAC++;
            free(p);
            return;
        }

        // WAITING
        p=removeFromList(&t->waitingHead,&t->waitingTail,pnr);
        if(p){
            printf("PNR %d cancelled (WAITING)\n", pnr);
            free(p);
            return;
        }

        t=t->next;
    }

    printf("PNR %d not found\n", pnr);
}
