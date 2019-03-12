#include <iostream>
#include <string>

using namespace std;

//Parked Car Class
class ParkedCar
{
private:
    string make;
    string model;
    string color;
    string license;
    int timeParked;
    friend class PoliceOfficer;
public:
    ParkedCar(string m,string md,string c,string l,int tP)
    {
        this->make = m;
        this->model = md;
        this->color = c;
        this->license = l;
        this->timeParked = tP;
    }
    int getTimeParked()
    {
        return timeParked;
    }
};
//Parking Meter Class
class ParkingMeter
{
private:
    int minParkPurchase;
    friend class PoliceOfficer;
public:
    ParkingMeter(int pp)
    {
        minParkPurchase=pp;
    }
    int getMinPark()
    {
        return minParkPurchase;
    }
};
//Parking Ticket Class
class ParkingTicket
{
private:
    string make;
    string model;
    string color;
    string license;
    int timeParkedIllegal;
    const int firstHourRate = 25;
    const int afterHourRate = 10;
    int fine;
    string pName;
    int bNum;
public:
    ParkingTicket(string m,string md,string c,
                  string l,int tP,string pName,int bNum)
    {
        this->make=m;
        this->model=md;
        this->color=c;
        this->license=l;
        this->timeParkedIllegal=tP;
        this->fine=calcFine();
        this->pName=pName;
        this->bNum = bNum;
    }
    int calcFine()
    {
        int hour=(timeParkedIllegal/60);
        if((timeParkedIllegal%60)>1)
           hour++;
        if(hour==1)
            return firstHourRate;
        if(hour>1)
            return firstHourRate+(afterHourRate*(hour-1));
        else
            return 0;
    }
    void printTicket()
    {
        cout<<"\n----Parking Ticket----\n"
           <<"Make: "<<make<<endl
           <<"Model: "<<model<<endl
           <<"Color: "<<color<<endl
           <<"License: "<<license<<endl
           <<"Time Parked Illegally(min): "<<timeParkedIllegal<<endl
           <<"Fine: $"<<fine<<endl
           <<"Issued by: "<<pName<<endl
           <<"Badge #: "<<bNum<<endl;
    }
};
//Police Officer Class
class PoliceOfficer
{
private:
    string pOName;
    int badgeNum;
public:
    PoliceOfficer(string n,int b)
    {
        this->pOName=n;
        this->badgeNum=b;
    }
    string getName()
    {
        return this->pOName;
    }
    bool examineCar(ParkedCar pc,ParkingMeter pm)
    {
        if(pc.timeParked>pm.minParkPurchase)
            return true;
        else
            return false;
    }
    ParkingTicket giveTicket(ParkedCar pc,ParkingMeter pm)
    {
        if(examineCar(pc,pm))
        {
            int timeParkedIllegally = pc.timeParked-pm.minParkPurchase;
            ParkingTicket ticket(pc.make,pc.model,pc.color,pc.license,
                                 timeParkedIllegally,pOName,badgeNum);
            return ticket;
        }
        else
            return ParkingTicket (pc.make,pc.model,pc.color,pc.license,0,
                                  pOName,badgeNum);
    }
};
//Main Driver
int main()
{
    ParkedCar pc("toyota","camry","gray","1abc123",200);
    ParkingMeter pm(55);
    PoliceOfficer po("Jerry",12345);
    if(po.examineCar(pc,pm))
        po.giveTicket(pc,pm).printTicket();

    return 0;
}
