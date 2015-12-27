#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

const int MAXNUM = 4;
void outputLine(std::string, std::string, std::string);

class SS_Node //scenic spot class store data
{
public:
    SS_Node() {};
    // ~SS_Node();
    bool getInformation();
    std::string getName() { return Name; }
private:
    std::string Number;// Store scenic spot number
    std::string Name;// Store scenic spot name
    std::string Introduction;// Store scenic spot introduction
};


bool SS_Node::getInformation() {
    std::cout << "Please input information: " << std::endl
              << "Scenic Spot number? ";
    std::string _number;
    std::cin >> _number;
    
    std::string _name;
    std::cout << "Scenic Spot Name? ";
    std::cin >> _name; 

    std::string _introduction;
    std::cout << "Scenic Spot introduction? ";
    std::cin >> _introduction; 

    Number = _number;
    Name = _name; 
    Introduction = _introduction;

    return true;
}

SS_Node* readSpot() {
    std::ifstream inClientFile("Scenic_Spot.data", std::ios::in);

    // Exit program if ifstream could not open file
    if ( !inClientFile ) {
        std::cerr << "File could not be opened" << std::endl;
        exit(1);
    }// End if

    SS_Node* Temp = new SS_Node[MAXNUM];

        std::string num;
        std::string nam;
        std::string intro;
        while (inClientFile >> num >> nam >> intro)
            outputLine(num, nam, intro);

}

void outputLine(std::string a, std::string b, std::string c) {
    std::cout << a << std::endl
              << b << std::endl
              << c << std::endl;
}

int main(int argc, char const *argv[])
{
    readSpot();
    return 0;
}