#include "pharmacy.h"
#include <iostream>
using namespace std;

Pharmacy::Pharmacy()
{

}
double Pharmacy::addMedication(PatientAccount p, int c)
{
    switch (c) {
    case 1:
        p.totPatientCharges+=priceM1;
        break;
    case 2:
        p.totPatientCharges+=priceM2;
        break;
    case 3:
        p.totPatientCharges+=priceM3;
        break;
    case 4:
        p.totPatientCharges+=priceM4;
        break;
    case 5:
        p.totPatientCharges+=priceM5;
        break;
    default:
        cout<<"Error in Adding Medication\n";
        break;
    }
    return p.totPatientCharges;
}
