// Polymorphism example   *******START*********** + override

//#include "stdafx.h"

#include <cstdio>

#include <string>

//using namespace std;



// Base class

class Animal {

    std::string _name;

    std::string _type;

    std::string _sound;

    // private constructor prevents construction of base class

    Animal() {};

protected:

    // protected constructor for use by derived classes only!

    Animal(const std::string & n, const std::string & t, const std::string & s)

        : _name(n), _type(t), _sound(s) {       //using C++ 11 in-class member initalizer

        printf("Animal Constructed\n");

    }

public:

    void speak() const;

    const std::string & name() const { return _name; }

    const std::string & type() const { return _type; }

    const std::string & sound() const { return _sound; }

    std::string snap() { return "Animal_Snap"; }     //redefine same signature



};

        //To deifine outside use class name,SCOPE OPERATOR,Member function

void Animal::speak() const {

    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());

}



// Dog class - derived from Animal

class Dog : public Animal {

    int walked;

public:

    Dog(std::string n) : Animal(n, "dog", "woof"), walked(0) {

        printf("Dog Constructed\n");

    };

    int walk() { return ++walked; }

    std::string snap() { return "Dog_Snap"; }    //override same signature

};



// Cat class - derived from Animal

class Cat : public Animal {

    int petted;

public:

    Cat(std::string n) : Animal(n, "cat", "meow"), petted(0) {

        printf("Cat Constructed\n");

    };

    int pet() { return ++petted; }

};



class Donkey :public Animal {

    int carried;

public:

    Donkey(std::string n) : Animal(n, "donkey", "hee-haw"), carried(0) {

        printf("Donkey constructed\n");

    };

    int carry() { return ++carried; }

};



// Pig class - derived from Animal

class Pig : public Animal {

    int fed;

public:

    Pig(std::string n) : Animal(n, "pig", "oink"), fed(0) {

        printf("Pig Constructed\n");

    };

    int feed() { return ++fed; }

};



//NOTICE INPUT TYPE

std::string displayName(const Animal &A) {

    return A.name();

}





int main(int argc, char ** argv) {

    Dog d("Rover");

    Cat c("Fluffy");

    Pig p("Arnold");

    Donkey donk("Eeyore");



    //Poly

    //calling a specific ANIMAL -> a derived class of base

    printf("%s\n", displayName(d).c_str() );

    printf("%s\n", displayName(c).c_str());

    printf("%s\n", displayName(p).c_str());



    //d.snap()  //what's called?

    printf("%s\n", d.snap().c_str());



    d.speak();

    c.speak();

    p.speak();

    donk.speak();



    printf("the dog has been walked %d times\n", d.walk());

    printf("the cat has been petted %d times\n", c.pet());

    printf("the pig has been fed %d times\n", p.feed());

    printf("the Donkey has been carried %d times\n", donk.carry());

}
