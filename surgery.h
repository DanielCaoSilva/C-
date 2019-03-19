#ifndef SURGERY_H
#define SURGERY_H
#include "patientaccount.h"

class Surgery
{
    double chargeS1 = 100;
    double chargeS2 = 200;
    double chargeS3 = 300;
    double chargeS4 = 400;
    double chargeS5 = 500;
public:
    Surgery();
    double addSurgery(PatientAccount p,int c);
};

#endif // SURGERY_H
