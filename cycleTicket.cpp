#include "cycleTicket.h"
#include "iostream"
#include "fstream"
using namespace std;
using namespace C;

void cycleTicket::mainMenu(){
    while(true){
        cout<<"Welcome to our cycle ticket lottery\nPress 1 to buy ticket :\nPress 2 to view avaliable tickets :\nPress 3 to view all customers list :\nPress 4 to quit :"<<endl;
        cin>>option;
        if(option == "1"){
            buying();
        }else if(option == "2"){
            ticketList();
            cout<<"\n";
        }else if(option == "3"){
            customerList();
        }else if(option == "4"){
            ticketSaving();
            customerSaving();
            exit(1);
        }else{
            cout<<"Unvalid Option"<<endl;
            mainMenu();
        }
    }
}
void cycleTicket::buying(){
    string quit;
    string tk;
    cout<<"Welcome this is ticket buying section!"<<endl;
    cout<<"Please enter your name : ";
    cin>>name[index];
    cout<<"Please enter your phone number : ";
    cin>>phNumber[index];
    while(true){
        cout<<"Please enter ticket number : ";
        cin>>tk;
        int count = ticketCheck(tk);
        if(count == 1){
            ticket[index] = tk;
            ticketRemove(tk);
            index++;
            cout<<"You have bought "<<tk<<endl;
            customerList();
            cout<<"Press 1 to quit : ";
            cin>>quit;
            if(quit == "1"){
                mainMenu();
            }
        }else{
            cout<<"not avaliable"<<endl;
        }
    }
}
void cycleTicket::ticketList(){
    for(int j=0; j<ticketIndex; j++){
        cout<<avaliableTicket[j]<<" ";
    }
}
void cycleTicket::ticketSaving(){
    string filename ="ticket-number.txt";
    ofstream saveFile;

    saveFile.open(filename);

    if(!saveFile.is_open()){
        cout<<"Unable to record!"<<endl;
    } else{
        for(int i=0 ; i<ticketIndex ; i++){
            string data=avaliableTicket[i]+"\n";
            saveFile<<data;
        }
    }
    saveFile.close();
}
void cycleTicket::ticketLoading(){
    int count = 0;
    string filename ="ticket-number.txt";
    string number;
    ifstream loadFile(filename);
    if(!loadFile.is_open()){
        cout<<"Unable to open file"<<endl;
    } else{
        while(getline(loadFile,number)){
            avaliableTicket[count] = number;
            count++;
            ticketIndex = count;
        }
    }
    if(count == 0){
        string toString;
        for(int i=0; i<1000; i++){
            if(i<10){
                toString = "00"+to_string(i);
                avaliableTicket[i] = toString;
            }else if(i<100){
                toString = "0"+to_string(i);
                avaliableTicket[i] = toString;
            }else{
                avaliableTicket[i] = to_string(i);
            }
        }
    }
}
int cycleTicket::ticketCheck(string check){
    for(int i=0; i<ticketIndex; i++){
        if(check == avaliableTicket[i]){
            return 1;
        }
    }
    return 0;
}
void cycleTicket::ticketRemove(string ticket){
    int tkMinus = 0;
    int c = 0;
    for(int i=0; i<ticketIndex; i++){
        if(ticket == avaliableTicket[i]){
            tkMinus = i;
            c++;
        }
    }
    for(int j=0; j<ticketIndex; j++){
        if(c != 0){
            avaliableTicket[tkMinus] = avaliableTicket[tkMinus+1];
            tkMinus++;
        }
    }
}
void cycleTicket::customerList(){
    for(int i=0; i<index; i++){
        cout<<name[i]<<" "<<phNumber[i]<<" "<<ticket[i]<<endl;
    }
}
void cycleTicket::customerSaving(){
    string filename ="ticket-buyer.txt";
    ofstream saveFile;

    saveFile.open(filename);

    if(!saveFile.is_open()){
        cout<<"Unable to record!"<<endl;
    } else{
        for(int i=0 ; i<index ; i++){
            string data=name[i]+" "+phNumber[i]+" "+ticket[i]+"\n";
            saveFile<<data;
        }
    }
    saveFile.close();
}
void cycleTicket::customerLoading(){
    int count=0;
    string data;
    string dataFile="ticket-buyer.txt";
    string dataLine;
    ifstream data_file(dataFile);
    if(data_file.is_open()){
        while (getline(data_file,dataLine)){
            dataLine=dataLine+" ";

            for(auto &ch :dataLine){
                if(ch==' '){
                    if(count==0){
                        name[index]=data;
                        data="";
                        count++;
                    } else if(count==1){
                        phNumber[index]=data;
                        data="";
                        count++;
                    } else if(count==2){
                        ticket[index] = data;
                        index++;
                        data="";
                        count=0;
                    }

                } else{
                    string st(1,ch);
                    data = data+st;
                }

            }

        }
    } else{
        cout<<"Unable to open file"<<endl;
    }
}
