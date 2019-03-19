#include <iostream>
#include "patientaccount.h"
#include "pharmacy.h"
#include "surgery.h"


using namespace std;

int surgeryChoice();
int medicationChoice();
void printCharges(PatientAccount p);
void main()
{
    PatientAccount pat(2);
    int sChoice = surgeryChoice();
    int mChoice = medicationChoice();
    Surgery surg;
    Pharmacy pharm;
    pat.setTotalCharges(surg.addSurgery(pat,sChoice));
    pat.setTotalCharges(pharm.addMedication(pat,mChoice));
    printCharges(pat);

}
int surgeryChoice()
{
    int choice;
    cout << "Surgery Selection\n";
    cout << "Please enter the surgery type\n";
    cout << "1 - S1\n";
    cout << "2 - S2\n";
    cout << "3 - S3\n";
    cout << "4 - S4\n";
    cout << "5 - S5\n";
    cout << "Selection: ";
    cin >> choice;
    return choice;
}
int medicationChoice()
{
    int choice;
    cout << "Medication Selection\n";
    cout << "Please enter the medication type\n";
    cout << "1 - M1\n";
    cout << "2 - M2\n";
    cout << "3 - M3\n";
    cout << "4 - M4\n";
    cout << "5 - M5\n";
    cout << "Selection: ";
    cin >> choice;
    return choice;
}
void printCharges(PatientAccount p)
{
    cout << "Total Patient Charges\n";
    cout << "Day(s) stayed in hospital: ";
    cout << p.getDaysInHos()<<endl;
    cout << "Total Patient Charges: ";
    cout << p.getTotalCharges()<<endl;
}
