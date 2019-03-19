#include "surgery.h"
#include <iostream>
using namespace std;

Surgery::Surgery()
{

}
double Surgery::addSurgery(PatientAccount p,int c)
{
    switch (c) {
    case 1:
        p.totPatientCharges+=chargeS1;
        break;
    case 2:
        p.totPatientCharges+=chargeS2;
        break;
    case 3:
        p.totPatientCharges+=chargeS3;
        break;
    case 4:
        p.totPatientCharges+=chargeS4;
        break;
    case 5:
        p.totPatientCharges+=chargeS5;
        break;
//        cout << p.totPatientCharges;
    default:
        cout<<"Error in Adding Surgery\n";
        break;
    }
    return p.totPatientCharges;
}
