#include <iostream>

class PersonData
{
private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    long long phone;
    PersonData() {}
protected:
protected:
    // protected constructor for use by derived classes
    PersonData(const std::string & lN, const std::string & fN, const std::string & a
               ,const std::string & c,const std::string & s,const int & z,const long long & p)
        : lastName(lN), firstName(fN), address(a),city(c),state(s),zip(z),phone(p)
    {
        printf("PersonData Constructed\n");
    }
public:
    const std::string & getlastName() const { return lastName; }
    const std::string & getfirstName() const { return firstName; }
    const std::string & getaddress() const { return address; }
    const std::string & getcity() const { return city; }
    const std::string & getstate() const { return state; }
    const int & getzip() const { return zip; }
    const long long & getphone() const { return phone; }
};
class CustomerData: public PersonData
{
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData(int cN,bool mL,std::string lN,std::string fN,
                 std::string a,std::string c,
                 std::string s,int z,long long p) : PersonData(lN,fN,a,c,s,z,p),
                                  customerNumber(cN),mailingList(mL)
    {
        printf("CustomerData Constructed\n");
    }
    const int & getcustomerNumber() const {return customerNumber;}
    const bool & getmailingList() const {return mailingList;}
    void  setmailingList(bool change) { mailingList=change;}
};
class PreferredCustomer: public CustomerData
{
private:
    double purchasesAmount;
    double discountLevel;
    double dLA[4]={500,1000,1500,2000};
public:
    PreferredCustomer(double pA,int cN,bool mL,std::string lN,std::string fN,
                      std::string a,std::string c,
                      std::string s,int z,long long p) : CustomerData(cN,mL,lN,fN,a,c,s,z,p),
                                    purchasesAmount(pA)
    {
        if(pA<0)
        {    std::cout<<"Invalid Purchase Amount\n";exit(1);}
        else if(pA>=0&&pA<dLA[0])
            discountLevel =0;
        else if(pA>=dLA[0]&&pA<dLA[1])
            discountLevel=.05;
        else if(pA>=dLA[1]&&pA<dLA[2])
            discountLevel=.06;
        else if(pA>=dLA[2]&&pA<dLA[3])
            discountLevel=.07;
        else if(pA>=dLA[3])
            discountLevel=.10;
        printf("PreferredCustomer Constructed\n");
    }
    const double & getpurchaseAmount() const {return purchasesAmount;}
    const double & getdiscountLevel() const {return discountLevel;}
};

int main()
{
    CustomerData cd(12345,true,"Silva","Daniel","123 W. Street St.","Burbank"
                    ,"California",91505,8186419496);
    printf("Customer Information:\n");
    printf("Customer #: %d\n",cd.getcustomerNumber());
    printf("On Mailing List: %d\n",cd.getmailingList());
    printf("Last Name: %s\n",cd.getlastName().c_str());
    printf("First Name: %s\n",cd.getfirstName().c_str());
    printf("Address: %s\n",cd.getaddress().c_str());
    printf("City: %s\n",cd.getcity().c_str());
    printf("State: %s\n",cd.getstate().c_str());
    printf("Zip Code: %d\n",cd.getzip());
    printf("Phone #: %llu\n\n\n",cd.getphone());

    PreferredCustomer pC(2000,54321,false,"Silver","Danny","321 N. Street Ave."
                         ,"Knabrub","New York",50519,8001234567);
    printf("Preferred Customer Information:\n");
    printf("Purchase Amount: %f\n",pC.getpurchaseAmount());
    printf("Discount Level: %f\n",pC.getdiscountLevel());
    printf("Customer #: %d\n",pC.getcustomerNumber());
    printf("On Mailing List: %d\n",pC.getmailingList());
    printf("Last Name: %s\n",pC.getlastName().c_str());
    printf("First Name: %s\n",pC.getfirstName().c_str());
    printf("Address: %s\n",pC.getaddress().c_str());
    printf("City: %s\n",pC.getcity().c_str());
    printf("State: %s\n",pC.getstate().c_str());
    printf("Zip Code: %d\n",pC.getzip());
    printf("Phone #: %llu\n",pC.getphone());
    return 0;
}

