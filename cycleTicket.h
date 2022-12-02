#include "iostream"
using namespace std;
#ifndef CYCLETICKET_H
#define CYCLETICKET_H


namespace C{
class cycleTicket
{
    public:
        string option;
        int index=0;
        int ticketIndex = 1000;
        string name[100];
        string phNumber[100];
        string ticket[100];
        string avaliableTicket[1000];
        void mainMenu();
        void buying();
        void ticketList();
        void ticketSaving();
        void ticketLoading();
        int ticketCheck(string check);
        void ticketRemove(string ticket);
        void customerList();
        void customerSaving();
        void customerLoading();
};
}

#endif // CYCLETICKET_H
