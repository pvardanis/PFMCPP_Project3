 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

#include <cmath>
#include <bits/stdc++.h> 
#include <iostream>

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        void stepForward()
        {
            std::cout << "Step forward!" << std::endl;
        }

        int stepSize(int steps)
        {
            return 3 * steps; 
        }
    };

    void run(int howFast, bool startWithLeftFoot);
    Foot leftFoot;
    Foot rightFoot;
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTraveled += leftFoot.stepSize(howFast) + rightFoot.stepSize(howFast); 
}
 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 1)
 */
struct AudioPlugins 
{
    int numPlugins;
    std::vector<std::string> differentTypes; // I don't know
    // why .push_back("something") gets me an error
    
    struct MultiBandCompressor
    {
        bool playSound = false;
        double attackTime = 0.;
        double releaseTime = 0.;
        double compressRatio = 2.5;
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
    if (numVisitors > 500) 
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
    char color;

    struct Circle
    {
        double radius;        
        double computeArea();
    };
};

double Shape::Circle::computeArea()
{
    return M_PI * pow(radius, 2);
}
/*
 4)
 */
struct BusStation 
{
    int numOfPassengers = 50;
    double ticketCost = 1.50;
    int numberOfTickets = 30;

    void stopBus();
    void checkTickets();
};

void BusStation::checkTickets()
{
    if (numberOfTickets != numOfPassengers) std::cout << "Everyone out!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
}

/*
 5)
 */
struct Kitchen
{
    int numOfKnifes = 5;
    bool fridgeIsEmpty = true; // always true :(
    bool hasTomatoes = false;
    std::vector<std::string> recipe;

    void makeSalad();
};

void Kitchen::makeSalad()
{
    if (!hasTomatoes) std::cout << "You can't make any salad!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
}
/*
 6)
 */
struct Wardrobe
{
    struct Pants
    {
        char color, size, type, brand;
        void select();
    };
    Pants myPants; // only UDT member variable
};

void Wardrobe::Pants::select()
{
    std::cout << "What color would you like: " << std::endl;
    std::cin >> color;
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
        
        void interviewPeople(int totalQualifications, int threshold);
    };

    void dontGiveAShitAboutHomelessPeople(); // happens in Brighton, UK (you heard it here first!)
};

void SimCity::Factory::interviewPeople(int totalQualifications, int threshold)
{
    (totalQualifications > threshold) ? std::cout << "You got hired!" << std::endl : std::cout << "Unfortunately we won't proceed with your application" << std::endl; FIXME make this more readable
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
    int numOfCars;
    int maxCapacity;
    double costPerCar;
    bool hasTools;
    
    void fixCar(bool paymentInFront, double cost);
    void makeBooking();
};

void Garage::fixCar(bool paymentInFront, double cost)
{
    if (paymentInFront) std::cout << "Your car will be ready in 3 days! The cost is: " << cost << "." << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
    else std::cout << "Gimme " << cost << " euros now you punk!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
}

void Garage::makeBooking()
{
    if (maxCapacity >= numOfCars) std::cout << "Can't fix your car dude!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
    else
    {
        std::cout << "Please leave your number." << std::endl; 
        numOfCars += 1;
    }
}

/*
 9)
 */
struct MusicStudio
{
    int numOfMicrophones, cables;
    bool isSoundproof;
    double costPerMix;
    
    void positionSpeakers(double angleLeftEar, double angleRightEar);
    void mixSong();
};

void MusicStudio::positionSpeakers(double angleLeftEar, double angleRightEar)
{
    if (angleLeftEar != 45. && angleRightEar != 45.) std::cout << "You need to reposition the speakers!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
    else std::cout << "Everything set!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
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
    double totalBudget = 1000000.;
    double costPerYear = 10000.; // happens also in UK, nothing is free here dude
    int numParcels = 25;
    std::vector<std::string> modules, weeklySchedule;

    void buyEquipment(double cost, bool hasEquipment);
    void receiveParcels();
    void makeExams(std::vector<std::string> listOfCourses);
};

void University::buyEquipment(double cost, bool hasEquipment)
{
    if (hasEquipment) std::cout << "Maybe we won't need this!" << std::endl; FIXME break this habit of putting if blocks on the same line if the expression is long. 
    else totalBudget = (totalBudget > cost) ? (totalBudget - cost) : totalBudget; FIXME break this habit of putting if blocks on the same line if the expression is long. 
}

void University::receiveParcels()
{
    int arrived;
    std::cout << "How many parcels do you have for us?" << std::endl;
    std::cin >> arrived;
    numParcels += 1;
    std::cout << "We have " << numParcels << " today.";
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
    std::cout << "good to go!" << std::endl;
}
