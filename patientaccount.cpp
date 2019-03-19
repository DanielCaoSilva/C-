#include "patientaccount.h"
#include <iostream>
using namespace std;

PatientAccount::PatientAccount(int numDays)
{
    numDaysInHos = numDays;
    totPatientCharges = numDays*dailyRate;
}
PatientAccount::PatientAccount(double pc, int numDaysInH)
{
    numDaysInHos = numDaysInH;
    totPatientCharges = pc+(numDaysInH*dailyRate);
}
double PatientAccount::getTotalCharges()
{
    return totPatientCharges;
}
int PatientAccount::getDaysInHos()
{
    return numDaysInHos;
}
void PatientAccount::setTotalCharges(double nCharges)
{
    totPatientCharges = nCharges;
}
