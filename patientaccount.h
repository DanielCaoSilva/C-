#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H


class PatientAccount
{
private:
    double totPatientCharges;
    int numDaysInHos;
    const double dailyRate = 100;
    friend class Surgery;
    friend class Pharmacy;
public:
    PatientAccount(int numDays);
    PatientAccount(double pc,int numDaysInHos);
    double getTotalCharges();
    int getDaysInHos();
    void setTotalCharges(double nCharges);
};

#endif // PATIENTACCOUNT_H
