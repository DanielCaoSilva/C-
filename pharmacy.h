#ifndef PHARMACY_H
#define PHARMACY_H
#include "patientaccount.h"

class Pharmacy
{
private:
    double priceM1 = 10;
    double priceM2 = 20;
    double priceM3 = 30;
    double priceM4 = 40;
    double priceM5 = 50;
public:
    Pharmacy();
    double addMedication(PatientAccount p,int c);
};

#endif // PHARMACY_H
