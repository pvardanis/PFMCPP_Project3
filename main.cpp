/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <cmath>
#include <bits/stdc++.h> 
#include <iostream>

struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};


/*
 1)
 */
struct AudioPlugins 
{
    int numOfPlugins;
    std::vector<std::string> differentTypes; // I don't know
    // why .push_back("something") gets me an error

    struct MultiBandCompressor
    {
        bool playSound = false;
        double attackTime = 0.;
        double releaseTime = 0.;
        float compressRatio = 2.5f;
    };

    double processSample(MultiBandCompressor compressor);
};

/*
 2)
 */
struct ShoppingMall
{
    int numOfVisitors;
    int numOfCameras;
    double dailyEarnings;

    struct mensClothing
    {
        double totalCost;
        int salePercent = 30;
        std::vector<std::string> listOfShops;
        double applyDiscount()
        {
            return (1 - (salePercent / 100.)) * totalCost;
        }
    };

    struct cosmetics
    {
        int numOfPopUpStores;
        void greetCustomer();
    };

    void helpCustomers();
    void superviseArea(int numOfVisitors, int numOfCameras);
};

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
        
        double computeArea()
        {
            return M_PI * pow(radius, 2); // I don't get these warnings
        } 
    };
};

/*
 4)
 */
struct BusStation 
{
    int numOfPassengers = 50;
    double ticketCost = 1.50;
    int numberOfTickets = 30;

    void stopBus();
    void checkTickets()
    {
        if (numberOfTickets != numOfPassengers)
        {
            std::cout << "Everyone out!" << std::endl;
        }
    }
};


/*
 5)
 */
struct Kitchen
{
    int numOfKnifes = 5;
    bool fridgeIsEmpty = true; // always true :(
    bool hasTomatoes = false;
    std::vector<std::string> recipe;

    void makeSalad()
    {
        if (!hasTomatoes)
        {
            std::cout << "You can't make any salad!" << std::endl;
        }
    }
};
/*
 6)
 */
struct Wardrobe
{
    struct Pants
    {
        char color, size, type, brand;
        void select()
        {
            std::cout << "What color would you like: " << std::endl;
            std::cin >> color;
        }
    };
    void selectCloth(Pants pants);
    Pants myPants; // only UDT member variable
};


/*
 7)
 */
struct simCity FIXME types should start with a Capital Letter
{
    double totalAmount = 250000000.;
    double unoccupiedArea = 150000.; // square meters

    struct Factory
    {
        double totalInvestment; 
        double totalArea;
        
        void interviewPeople(int totalQualifications, int threshold)
        {
            if (totalQualifications > threshold)
            {
                std::cout << "You got hired!" << std::endl;
            }
            else
            {
                std::cout << "Unfortunately we won't proceed with your application" << std::endl; // that's all I hear lol
            }
        }
    };

    void dontGiveAShitAboutHomelessPeople(); // happens in Brighton, UK (you heard it here first!)
};
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
    void makeBooking()
    {
        if (maxCapacity >= numOfCars)
        {
            std::cout << "Can't fix your car dude!" << std::endl;
        }
        else
        {
            std::cout << "Please leave your number." << std::endl; 
            numOfCars += 1;
        }
    }
};

/*
 9)
 */
struct MusicStudio
{
    int numOfMicrophones, cables;
    bool isSoundproof;
    double costPerMix;

    void positionSpeakers();
    void mixSong();
};

/*
 10)
 */
struct University
{
    int numOfStudents = 1500;
    double totalBudget = 1000000.;
    double costPerYear = 10000.; // happens also in UK, nothing is free here dude
    std::vector<std::string> modules, weeklySchedule;

    void buyEquipment(double cost, bool hasEquipment)
    {
        if (hasEquipment)
        {
            std::cout << "Maybe we won't need this!" << std::endl;
        }
        else 
        {
            if (totalBudget > cost)
            {
                totalBudget -= cost;
            }            
        }      
    }
    void receiveParcels();
    void makeExams(std::vector<std::string> listOfCourses);
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
