/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}


#include <cmath>
#include <bits/stdc++.h> 
#include <iostream>

/*
 1)
 */
struct AudioPlugins 
{
    int numPlugins;
    std::vector<std::string> differentTypes; // I don't know
    // why .push_back("something") gets me an error
    AudioPlugins(int howManyPlugins) 
    {
        numPlugins = howManyPlugins;
        std::cout << "You selected " << numPlugins << " plugins." << std::endl;
    }
    struct MultiBandCompressor
    {
        bool playSound = false;
        double attackTime = 0.;
        double releaseTime = 0.;
        double compressRatio;

        MultiBandCompressor(double ratio) 
        {
            compressRatio = ratio;
            std::cout << "You've set ratio to be: " << compressRatio << std::endl;
        }
    };

    std::vector<double> processSample(MultiBandCompressor compressor, std::vector<double> inputSamples);
};

std::vector<double> AudioPlugins::processSample(MultiBandCompressor compressor, std::vector<double> inputSamples)
{
    compressor.attackTime = 0.25;
    compressor.releaseTime = 0.1;
    if (!compressor.playSound)
    {
        std::fill(inputSamples.begin(), inputSamples.end(), 0.);    
        return inputSamples;
    }
    for (auto i = inputSamples.begin(); i != inputSamples.end(); ++i)
    {
        *i *= (compressor.attackTime - compressor.releaseTime); // I think it's a pointer and with *i you change the value that it points to
        *i /= compressor.compressRatio; // random
    }
    
    return inputSamples;
}

/*
 2)
 */
struct ShoppingMall
{
    int numVisitors;
    int numCameras;
    double dailyEarnings;

    ShoppingMall(int visitors, int cameras) 
    {
        numVisitors = visitors;
        numCameras = cameras;
    } // or I could use this->numVisitors = numVisitors, I guess (I mean if I change the input to have the same name as the member variable)

    struct MensClothing
    {
        double totalCost;
        int salePercent = 30;
        std::vector<std::string> shops; // dunno why I get this padding warning
        double applyDiscount();
    };

    struct Cosmetics
    {
        int numOfPopUpStores;
        void greetCustomer();
    };

    void superviseArea();
};

double ShoppingMall::MensClothing::applyDiscount()
{
    return (1 - (salePercent / 100.)) * totalCost;
}

void ShoppingMall::Cosmetics::greetCustomer()
{
    std::cout << "Hello sir!" << std::endl;
}

void ShoppingMall::superviseArea()
{
    if (numVisitors < 500) 
        std::cout << "Everything all right!" << std::endl;
    else if (numCameras < 50) 
        std::cout << "We need more cameras!" << std::endl;         
}

/*
 3)
 */
struct Shape
{
    bool hasAngles;
    std::string color;

    Shape(std::string yourColor) 
    {
        color = yourColor;
        std::cout << color << " shape constructed." << std::endl;
    }
    struct Circle
    {
        double radius;
        Circle(double yourRadius) {radius = yourRadius;}
        double computeArea();
    };
};

double Shape::Circle::computeArea()
{
    double area;
    area = M_PI * pow(radius, 2);
    std::cout << "Circle of " << area << " m^2." << std::endl; 
    return area;
}
/*
 4)
 */
struct BusStation 
{
    int numPassengers;
    int numTickets;
    double ticketCost = 1.50;

    BusStation()
    {
        numPassengers = 100;
        numTickets = 100;
    }
    BusStation(int passengers, int tickets) : 
    numPassengers(passengers),
    numTickets(tickets)
    {}

    void stopBus();
    void checkTickets();
};

void BusStation::checkTickets()
{
    if (numTickets != numPassengers) 
    {
        std::cout << "Everyone out!" << std::endl; 
    }     
}

/*
 5)
 */
struct Kitchen
{
    int numOfKnifes = 5;
    bool fridgeIsEmpty = true; // always true :(
    bool hasTomatoes;
    std::string recipe;

    Kitchen() : hasTomatoes(false) {}
    Kitchen(bool tomatoes, std::string myRecipe) : 
    hasTomatoes(tomatoes),
    recipe(myRecipe) 
    {}

    void makeSalad();
};

void Kitchen::makeSalad()
{
    if (!hasTomatoes) 
    {
        std::cout << "You can't make any salad!" << std::endl; 
    } 
    else
    {
        std::cout << "Time to make " << recipe << "!" << std::endl;
    }
}
/*
 6)
 */
struct Wardrobe
{
    struct Pants
    {
        std::string color, size, type, brand;

        Pants() : size("medium"), type("capri") {}
        Pants(std::string mySize, std::string myType) : 
        size(mySize),
        type(myType)
        { }

        void select();
    };
    Pants myPants; // only UDT member variable
};

void Wardrobe::Pants::select()
{
    std::cout << "What color would you like: " << std::endl;
    std::cin >> color;
    std::cout << "You will wear " << type << " of size " << size << " and color " << color << "." << std::endl;
}
/*
 7)
 */
struct SimCity // fell asleep
{
    double totalAmount = 250000000.;
    double unoccupiedArea = 150000.; // square meters

    struct Factory
    {
        double totalInvestment; 
        double totalArea;
        
        Factory(double investment, double area) :
        totalInvestment(investment),
        totalArea(area)
        { 
            std::cout << "The construction of a new -" << area << " m^2- factory worth " << investment << " million dollars has been announced! Great news!" << std::endl;
        }

        void interviewPeople(int totalQualifications, int threshold);
    };

    void dontGiveAShitAboutHomelessPeople(); // happens in Brighton, UK (you heard it here first!)
};

void SimCity::Factory::interviewPeople(int totalQualifications, int threshold)
{
    if (totalQualifications > threshold) 
    {
        std::cout << "You got hired!" << std::endl;
    }
    else
    {
        std::cout << "Unfortunately we won't proceed with your application." << std::endl;
    }
}

void SimCity::dontGiveAShitAboutHomelessPeople()
{
    std::cout << "Good luck if you are unemployed, punk!";
}
/*
 8)
 */
struct Garage
{
    int numCars;
    int maxCapacity;
    double costPerCar;
    
    Garage(int cars, int capacity, double cost) : 
    numCars(cars),
    maxCapacity(capacity),
    costPerCar(cost)
    {}

    void fixCar(bool isAvailable, bool paymentInFront);
    bool makeBooking();
};

void Garage::fixCar(bool isAvailable, bool paymentInFront)
{
    if (isAvailable)
    {
        if (paymentInFront) 
        {
            std::cout << "Your car will be ready in 3 days! The cost is: " << costPerCar << " euros." << std::endl; 
        }
        else 
        {
            std::cout << "Gimme " << costPerCar << " euros now you punk!" << std::endl; 
        }
    } 
    else
    {
        std::cout << "I really can't do this!" << std::endl;
    }
}

bool Garage::makeBooking()
{
    if (maxCapacity <= numCars) 
    {
        std::cout << "Can't fix your car dude!" << std::endl;
        return false; 
    }
    else
    {
        std::cout << "Please leave your number." << std::endl; 
        numCars += 1;
        return true;
    }
}

/*
 9)
 */
struct MusicStudio
{
    int numOfMicrophones, cables;
    double costPerMix;
    bool isSoundproof;
    
    MusicStudio(double cost, bool soundproof) : 
    costPerMix(cost),
    isSoundproof(soundproof) 
    {}

    void positionSpeakers(double angleLeftEar, double angleRightEar);
    void mixSong();
};

void MusicStudio::positionSpeakers(double angleLeftEar, double angleRightEar)
{
    if (angleLeftEar != 45. && angleRightEar != 45.) 
    {
        std::cout << "You need to reposition the speakers!" << std::endl; 
    }
    else
    {
        std::cout << "Everything set!" << std::endl; 
    }  
}

void MusicStudio::mixSong()
{
    std::cout << "The total cost is: " << costPerMix << "." << std::endl;
}

/*
 10)
 */
struct University
{
    int numOfStudents = 1500;
    double totalBudget;
    double costPerYear = 10000.; // happens also in UK, nothing is free here dude
    int numParcels = 25;
    std::vector<std::string> modules, weeklySchedule;

    University(double budget, int parcels) :
    totalBudget(budget),
    numParcels(parcels)
    { }

    void buyEquipment(double cost, bool hasEquipment);
    void receiveParcels();
    void makeExams(std::vector<std::string> listOfCourses);
};

void University::buyEquipment(double cost, bool hasEquipment)
{
    if (hasEquipment) 
    {
        std::cout << "Maybe we won't need this!" << std::endl; 
    }
    else 
    {
        if (totalBudget >= cost)
        {
            totalBudget -= cost;
        } 
        else
        {
            std::cout << "No money!" << std::endl;
        }
    }
}

void University::receiveParcels()
{
    int arrived;
    std::cout << "How many parcels do you have for us?" << std::endl;
    std::cin >> arrived;
    numParcels += arrived;
    std::cout << "We have " << numParcels << " today." << std::endl;
}

void makeExams(std::vector<std::string> listOfCourses)
{
    for (auto i = listOfCourses.begin(); i != listOfCourses.end(); ++i)
    {
        std::cout << *i << std::endl;
    } 
}

#include <iostream>
int main()
{
    Example::main();
    // example 1
    AudioPlugins audioPlugins(5);
    AudioPlugins::MultiBandCompressor mbc(3.5);

    // example 2
    ShoppingMall attica(600, 30);
    attica.superviseArea();
    
    // example 3
    Shape myShape("Red"); // I guess I can't pass this to the nested class Circle
    Shape::Circle myCircle(5);
    myCircle.computeArea();

    // example 4
    BusStation station1(50, 49);
    station1.checkTickets();
    BusStation station2;
    station2.checkTickets(); // in the default constructor it's all good

    // example 5
    Kitchen myKitchen1;
    myKitchen1.makeSalad();
    Kitchen myKitchen2(true, "Charred onion & tomato salad");
    myKitchen2.makeSalad();

    // example 6
    Wardrobe::Pants myPants1;
    myPants1.select();
    Wardrobe::Pants myPants2("large", "jeans");
    myPants2.select();

    // example 7
    SimCity::Factory myFactory(25.5, 1550.);

    // example 8
    Garage myGarage1(25, 50, 157.5);
    bool availability1 = myGarage1.makeBooking();
    myGarage1.fixCar(availability1, true);

    Garage myGarage2(50, 50, 168.5);
    bool availability2 = myGarage2.makeBooking();
    myGarage2.fixCar(availability2, false);

    // example 9
    MusicStudio myMusicStudio(125.0, true);
    myMusicStudio.mixSong();

    // example 10
    University myUniversity1(1000000., 150);
    myUniversity1.buyEquipment(500000, true);
    myUniversity1.receiveParcels();

    University myUniversity2(1000000., 50);
    myUniversity2.buyEquipment(2000000, false);
    myUniversity2.receiveParcels();

    std::cout << "good to go!" << std::endl;

}
