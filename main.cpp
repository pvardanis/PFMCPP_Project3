/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
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
    std::vector<std::string> differentTypes; 

    std::vector<double> inputSamples;
    bool playSound = true;
    bool button  = true;

    AudioPlugins(int howManyPlugins) 
    {
        numPlugins = howManyPlugins;
        std::cout << "You selected " << numPlugins << " plugins." << std::endl;
    }
    
    struct MultiBandCompressor
    {
        double attackTime = 0.;
        double releaseTime = 0.;
        double compressRatio;

        MultiBandCompressor(double ratio) 
        {
            compressRatio = ratio;
            std::cout << "You've set ratio to be: " << compressRatio << std::endl;
        }        
    };

    std::vector<double> processSample(MultiBandCompressor compressor, std::vector<double> input);
};

std::vector<double> AudioPlugins::processSample(MultiBandCompressor compressor, std::vector<double> input)
{
    inputSamples = {};

    for(size_t i=0; i < input.size(); ++i)
    {
        inputSamples.push_back(input[i]);
    }

    compressor.attackTime = 0.25;
    compressor.releaseTime = 0.1;

    for (auto i = inputSamples.begin(); i != inputSamples.end(); ++i)
    {   
        if (button == false || *i >= 10.)
        {
            playSound = false;
            std::fill(inputSamples.begin(), inputSamples.end(), 0.); 
            return inputSamples;
        }

        *i *= (compressor.attackTime - compressor.releaseTime); // I think it's a pointer and with *i you change the value that it points to
        *i /= compressor.compressRatio; // random
    }
    
    return inputSamples;
}

/*
 2)
 */

struct Visitor
{
    std::string name;
    int age;

    Visitor(std::string myName, int myAge) :
    name(myName),
    age(myAge)
    {}
};

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
    void performCheck(std::vector<Visitor> customerDetails);
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
        std::cout << "Everything all right! You don't have to worry for just " << numVisitors << "!" << std::endl;
    else if (numCameras < 50) 
        std::cout << "We need more cameras! " << numCameras << " are not enough!" << std::endl;         
}

void ShoppingMall::performCheck(std::vector<Visitor> customerDetails)
{
    std::vector<Visitor> entered;
    for( auto it = customerDetails.begin(); it != customerDetails.end(); ++it )
    {
        std::cout << "Could you please give me your details? ";
        auto age = (*it).age;
        auto name = (*it).name;
        std::cout << "My name is " << name  << " and I'm " << age  << " years old." << std::endl;
       
        if (age < 18)
        {
            std::cout << "Sorry sir! You are not allowed to enter!" << std::endl;
        } 
        else
        {
            std::cout << "Come in!" << std::endl;
            numVisitors += 1;
            entered.push_back(*it);
        }
    }

    std::cout << "List of people who entered: " << std::endl;
    for ( auto it = entered.begin(); it != entered.end(); ++it )
    {
        auto name = (*it).name;
        std::cout << name << std::endl;
    }
}

/*
 3)
 */
struct Shape
{
    bool hasAngles;
    std::string color;

    Shape() {}
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

    Circle* generateRandomCircle(double minValue, double maxValue);
};

double Shape::Circle::computeArea()
{
    double area;
    area = M_PI * pow(radius, 2);
    std::cout << "Circle of " << area << " m^2." << std::endl; 
    return area;
}

Shape::Circle* Shape::generateRandomCircle(double minValue, double maxValue)
{
    double randomRadius = fmod(double(rand()), (maxValue - minValue + 0.001));

    while (randomRadius < (minValue + maxValue) / 2) // doesn't really make sense
    {
        double temp = fmod(double(rand()), (maxValue - minValue + 0.001));
        randomRadius = temp;
    }

    Circle* randomCircle = new Circle(randomRadius); // let's try this for the first time
    
    return randomCircle;
}

/*
 4)
 */


struct Passenger
{
    bool hasTicket;
    Passenger(bool ticket) : hasTicket(ticket) {}
};

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

    void stopBus(bool passengersInStation, std::vector<Passenger> passegersWaiting);
    bool checkTickets();
};

bool BusStation::checkTickets()
{
    return (numTickets == numPassengers) ? true : false;
}

void BusStation::stopBus(bool passengersInStation, std::vector<Passenger> passengersWaiting)
{
    if (passengersInStation)
    {   
        for ( auto it = passengersWaiting.begin(); it != passengersWaiting.end(); ++it )
        {
            bool ticketStatus = (*it).hasTicket;
            
            if (ticketStatus)
            {
                std::cout << "You have to pay for your ticket!" << std::endl;
            }        
        }
        if (!this->checkTickets())
        {
            std::cout << "Everyone out!" << std::endl;
        }
    }
    else
    {
        std::cout << "Move on!" << std::endl;
    }
}

/*
 5)
 */
struct Kitchen
{
    int numOfKnifes = 5;
    bool fridgeIsEmpty = true; // always true :(
    std::vector<std::string> recipe;
    std::vector<std::string> stock;

    Kitchen() {}
    Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe) : 
    recipe(myRecipe),
    stock(myStock) 
    {}

    void makeSalad();
    bool fillBowl(bool hasIt, std::string item);
};

void Kitchen::makeSalad()
{
    for (auto it = recipe.begin(); it != recipe.end(); ++it)
    {
        std::string ingredient = *it;
        bool filled = false;
        for (auto it = stock.begin(); it != stock.end(); ++it) // this it overwrites the "it" above in this scope
        {
            std::string inStock = *it;
            if (inStock == ingredient)
            {
                filled = fillBowl(true, ingredient);
                break;
            }
        }
        if (!filled)
        {
            std::cout << ingredient << " not found! You can't make this salad!" << std::endl;
            break;
        }
    }
}

bool Kitchen::fillBowl(bool hasIt, std::string item)
{
    if (hasIt)
    {
        std::cout << "Filled with: " << item << std::endl;
        return true;
    }
    return false;
}
/*
 6)
 */
struct Wardrobe
{
    struct Pants
    {
        std::string color, size, type, brand;

        Pants() {}
        Pants(std::string mySize, std::string myType) : 
        size(mySize),
        type(myType)
        { }        
    };

    std::vector<Pants> totalPants; // only UDT member variable
    Pants wearPants;

    Wardrobe(std::vector<Pants> allPants, Pants myPants) :
    totalPants(allPants),
    wearPants(myPants)
    {} // only UDT member variable

    bool isDirty(bool foundStain);
    void wash(const Pants& dirtyPants);
    void select();
};

void Wardrobe::select()
{
    bool foundIt = false;
    for (auto it = totalPants.begin(); it != totalPants.end(); ++it) // this it overwrites the "it" above in this scope
    {
        std::string pantsSize = it->size;
        std::string pantsType = it->type;

        if (pantsSize == wearPants.size && pantsType == wearPants.type)
        {
            std::cout << "Found what you are looking for!" <<   std::endl;
            foundIt = true;
            if (isDirty(true)) // always true, because well that's what happens in reality
            {
                std::cout << "But it's dirty!" << std::endl;
                wash(wearPants);
                break; 
            }
        }        
    }
    if (!foundIt)
    {
        std::cout << "No clothes for you baby!" << std::endl;
    }
}

bool Wardrobe::isDirty(bool foundStain)
{
    return foundStain; // could do more
}

void Wardrobe::wash(const Pants& dirtyPants)
{
    std::cout << "Washed " << dirtyPants.type << "!" << std::endl; // could do more
}
/*
 7)
 */

struct Employee
{
    std::vector<std::string> qualifications;
    int age;

    Employee(std::vector<std::string> myQualifications, int myAge) :
    qualifications(myQualifications),
    age(myAge)
    {}
};
struct SimCity // fell asleep
{
    double totalAmount = 250000000.;
    double unoccupiedArea = 150000.; // square meters
    std::string message;

    SimCity(std::string hatefulMessage) : message(hatefulMessage) {}
    struct Factory
    {
        double totalInvestment; 
        double totalArea;
        std::vector<std::string> threshold;
        
        Factory(std::vector<std::string> minimumQualifications) :
        threshold(minimumQualifications)
        {}
        
        Factory(double investment, double area, std::vector<std::string> minimumQualifications) :
        totalInvestment(investment),
        totalArea(area),
        threshold(minimumQualifications)
        { 
            std::cout << "The construction of a new -" << area << " m^2- factory worth " << investment << " million dollars has been announced! Great news!" << std::endl;
        }

        void interviewPeople(std::vector<Employee> candidates);
    };

    void dontGiveAShitAboutHomelessPeople(); // happens in Brighton, UK (you heard it here first!)
};

void SimCity::Factory::interviewPeople(std::vector<Employee> candidates)
{
    for (auto it = candidates.begin(); it != candidates.end(); ++it)
    {   
        int numQualified = 0;
        int age = it->age;
        std::vector<std::string> qualifications = it-> qualifications;   

        for (size_t it = 0; it < qualifications.size(); ++it)
        {
            std::string skill = qualifications[it];
            for (size_t it = 0; it < threshold.size(); ++it)
            {
                if (skill == threshold[it])
                {
                    numQualified++;
                    break;
                }    
            }            
        }
        if (numQualified == int(threshold.size()) && age >= 18) 
        {
            std::cout << "You're hired!" << std::endl;
        }
        else
        {
            std::cout << "Unfortunately we won't proceed with your application." << std::endl;
        }
    }
}

void SimCity::dontGiveAShitAboutHomelessPeople()
{
    std::cout << message << std::endl;
}
/*
 8)
 */

struct Repair // more general
{
    std::vector<std::string> toolsNeeded;
    void unscrew(std::string tool);

    Repair(std::vector<std::string> tools) : toolsNeeded(tools) {}
};

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

    void fixCar(bool isAvailable, std::vector<std::string> tools, bool paymentInFront);
    bool makeBooking();
    void searchTool(std::string tool, bool foundIt);
};

void Garage::fixCar(bool isAvailable, std::vector<std::string> tools, bool paymentInFront)
{
    if (isAvailable)
    {
        if (paymentInFront) 
        {
            std::cout << "Your car will be ready in 3 days! The cost is: " << costPerCar << " euros." << std::endl; 
            Repair repair(tools);

            size_t i = 0;
            bool foundIt = false;
            while (i < repair.toolsNeeded.size())
            {
                if (i % 2 == 0) 
                {
                    foundIt = true;
                }
                searchTool(repair.toolsNeeded[i], foundIt);
                foundIt = false;
                i++;
            }
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

void Garage::searchTool(std::string tool, bool foundIt)
{
    if(foundIt) std::cout << "Found " << tool << "!" << std::endl;
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

struct Song
{
    std::string title;
    std::string genre;
    double volume;
    double frequencyRange;

    Song(std::string songTitle, std::string songGenre, double songVolume, double songFrequencyRange) :
    title(songTitle),
    genre(songGenre),
    volume(songVolume),
    frequencyRange(songFrequencyRange)
    {}
};

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
    void mixSong(std::vector<Song> songs);
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

void MusicStudio::mixSong(std::vector<Song> songs)
{
    std::cout << "The total cost is: " << costPerMix * int(songs.size()) << "." << std::endl;
    for (auto it = songs.begin(); it < songs.end(); ++it)
    {
        
        double volume = it->volume;
        double frequencyRange = it->frequencyRange;
        std::string title = it->title;
        std::string genre = it->genre;

        volume -= 2.5;
        frequencyRange -= 500;

        std::cout << "Song title: " << title << std::endl;
        std::cout << "Song genre: " << genre << std::endl;
        std::cout << "Volume now is: " << volume << ", frequence range is: " << frequencyRange << "Hz." << std::endl;
    }
}

/*
 10)
 */

struct Parcel
{
    std::vector<double> dimensions; // height, width, depth
    std::string type;

    Parcel() {}
    Parcel(std::vector<double> myDimensions, std::string myType) : 
    dimensions(myDimensions),
    type(myType)
    {}
};

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
    void receiveParcels(std::vector<Parcel> parcels);
    bool checkParcel(Parcel *parcel, std::vector<double> dimensionsThreshold, std::string forbiddenType);
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

void University::receiveParcels(std::vector<Parcel> parcels)
{
    int arrived = int(parcels.size());
    std::cout << "We already have " << numParcels << " parcels in total." << std::endl;
    std::cout << arrived << " parcels arrived!" << std::endl;

    for (auto it = parcels.begin(); it != parcels.end(); ++it)
    {
        Parcel *parcel = std::addressof(*it);
        if (!checkParcel(parcel, {2.5, 1.5, 0.5}, "fragile")) arrived -= 1;
        else std::cout << "Accepted!" << std::endl;
    }
    numParcels += arrived;
    std::cout << "We have " << numParcels << " parcels in total." << std::endl;
}

bool University::checkParcel(Parcel *parcel, std::vector<double> dimensionsThreshold, std::string forbiddenType)
{
    std::vector<double> dimensions = parcel->dimensions;
    std::string type = parcel->type;

    if (type == forbiddenType) 
    {
        std::cout << "Sorry, we can't receive this item! It's " << type << "!" << std::endl;
        return false;
    }
    
    for (size_t d = 0; d < dimensions.size(); ++d)
    {
        if (dimensions[d] > dimensionsThreshold[d])
        {
            std::cout << "Sorry, we can't receive this item! Exceeds allowed dimensions!" << std::endl;
            return false;
        }
    }
    return true;
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
    //Example::main();
    // example 1
    std::cout << "\nExample 1: " << std::endl;
    AudioPlugins audioPlugins(5);
    AudioPlugins::MultiBandCompressor mbc(3.5);
    audioPlugins.processSample(mbc, {1.5, 4.53, 9.49, 9.5, 5.105});
    std:: cout << "Value under 10.0, playSound: " << audioPlugins.playSound << std::endl; // all values below 10.0, returns 1
    audioPlugins.processSample(mbc, {1.5, 12.467, 9.49, 9.5, 5.105});
    std:: cout << "Value over 10.0, playSound: " << audioPlugins.playSound << std::endl; // all values below 10.0, returns 0
    audioPlugins.button = false;
    audioPlugins.processSample(mbc, {1.5, 4.53, 9.49, 9.5, 5.105}); // all below 10.
    std:: cout << "Value under 10.0 and button = false, playSound: " << audioPlugins.playSound << std:: endl; // all values below 10.0, returns 0 

    // example 2
    std::cout << "\nExample 2: " << std::endl;
    ShoppingMall attica(600, 30);
    attica.superviseArea();
    Visitor v1("Panos", 25);
    Visitor v2("George", 17);
    Visitor v3("Matkat", 18);
    Visitor v4("Chris", 13);
    attica.performCheck({v1, v2, v3, v4});
    // std::cout << "List of people who entered: " << peopleEntered << std::endl;
    
    // example 3
    std::cout << "\nExample 3: " << std::endl;
    Shape myShape("Red"); 
    Shape::Circle myCircle(5);
    myCircle.computeArea();

    Shape myRandomShape;
    Shape* randomShape = &myRandomShape;
    Shape::Circle* myRandomCircle = randomShape->generateRandomCircle(1., 10.); // random circle, radius always > (maxValue + minValue) / 2
    std::cout << "Generated a random circle with radius = " << myRandomCircle->radius << " and area of " << myRandomCircle->computeArea() << std::endl;

    // example 4
    std::cout << "\nExample 4" << std::endl;
    BusStation station1(45, 50); // the driver will notice
    station1.checkTickets();

    BusStation station2;
    station2.checkTickets(); // in the default constructor it's all good

    BusStation station3;
    Passenger p1(true);
    Passenger p2(false);
    Passenger p3(true);
    station3.stopBus(true, {p1, p2, p3});

    // example 5
    std::cout << "\nExample 5: " << std::endl;
    // Kitchen myKitchen1;
    // myKitchen1.makeSalad();
    // Kitchen myKitchen2(true, "Charred onion & tomato salad");
    // myKitchen2.makeSalad();
    std::vector<std::string> stock = {"onion", "tomatoes", "peppers", "feta", "potatoes"};
    std::cout << "Let's make salad1 !" << std::endl;
    std::vector<std::string> recipe1 = {"onion", "tomatoes", "feta"};

    Kitchen myKitchen1(stock, recipe1);
    myKitchen1.makeSalad();
    std::cout << "Let's make salad2 !" << std::endl;
    std::vector<std::string> recipe2 = {"peppers", "cheese", "pepperoni"};

    Kitchen myKitchen2(stock, recipe2);
    myKitchen2.makeSalad();

    // example 6
    std::cout << "\nExample 6: " << std::endl;
    // Wardrobe::Pants myPants1;
    // myPants1.select();
    // Wardrobe::Pants myPants2("large", "jeans");
    // myPants2.select();
    Wardrobe::Pants pants1("medium", "trousers");
    Wardrobe::Pants pants2("medium", "jeans");
    Wardrobe::Pants pants3("small", "jeans");
    Wardrobe::Pants pants4("large", "cargo");
    std::vector<Wardrobe::Pants> pants{pants1, pants2, pants3, pants4};
    Wardrobe::Pants wannaWear1("large", "cargo");
    Wardrobe::Pants wannaWear2("large", "shorts");

    Wardrobe myWardrobe1(pants, wannaWear1);
    myWardrobe1.select();

    Wardrobe myWardrobe2(pants, wannaWear2);
    myWardrobe2.select();

    // example 7
    std::cout << "\nExample 7: " << std::endl;
    // SimCity::Factory myFactory(25.5, 1550., 5);
    // myFactory.interviewPeople(6); // hired
    // myFactory.interviewPeople(3); // rejected
    // SimCity myCity("F*** off!");
    // myCity.dontGiveAShitAboutHomelessPeople();
    std::vector<std::string> minimumQualifications = {"C++", "Python", "Digital Signal Processing"};
    std::vector<std::string> myQualifications = {"Python", "Digital Signal Processing"};
    std::vector<std::string> matkatQualifications = {"Python", "Digital Signal Processing", "C++", "VST development"};
    std::vector<std::string> randomKidQualifications = {"Python", "Digital Signal Processing", "C++", "Hacking", "Machine Learning"};    
    Employee me(myQualifications, 25);
    Employee matkatmusic(matkatQualifications, 35);
    Employee randomKid(randomKidQualifications, 16);
    std::vector<Employee> candidates = {me, matkatmusic, randomKid}; 
    SimCity::Factory myFactory(minimumQualifications);
    myFactory.interviewPeople(candidates);


    // example 8
    std::cout << "\nExample 8: " << std::endl;
    // Garage myGarage1(25, 50, 157.5);
    // bool availability1 = myGarage1.makeBooking();
    // // myGarage1.fixCar(availability1, true);

    // Garage myGarage2(50, 50, 168.5);
    // bool availability2 = myGarage2.makeBooking();
    // myGarage2.fixCar(availability2, false);

    Garage myGarage3(10, 30, 157.5);
    std::vector<std::string> tools = {"screwdriver", "wrench", "pliers", "paintbrush", "saw", "drill"};
    bool availability3 = myGarage3.makeBooking();
    myGarage3.fixCar(availability3, tools, true);


    // example 9
    std::cout << "\nExample 9: " << std::endl;
    // MusicStudio myMusicStudio(125.0, true);
    // myMusicStudio.mixSong();
    Song s1("Welcome to the Jungle", "Rock", -5, 2500);
    Song s2("Fear", "Hip hop", -2.5, 1500);
    std::vector<Song> songs = {s1, s2};
    MusicStudio myMusicStudio(125.0, true);
    myMusicStudio.mixSong(songs);

    // example 10
    std::cout << "\nExample 10: " << std::endl;
    // University myUniversity1(1000000., 150);
    // myUniversity1.buyEquipment(500000, true);
    // myUniversity1.receiveParcels();

    // University myUniversity2(1000000., 50);
    // myUniversity2.buyEquipment(2000000, false);
    // myUniversity2.receiveParcels();

    Parcel parcel1({1.0, 1.0, 0.5}, "plastic");
    Parcel parcel2({0.5, 0.5, 0.5}, "fragile");
    Parcel parcel3({3.0, 1.0, 0.5}, "plastic");

    std::vector<Parcel> parcels = {parcel1, parcel2, parcel3};
    University myUniversity(1000000., 50);
    myUniversity.receiveParcels(parcels);

    std::cout << "good to go!" << std::endl;

}
