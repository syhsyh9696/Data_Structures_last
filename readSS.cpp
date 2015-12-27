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
    // std::string num;
    // std::string nam;
    // std::string intro;

    for (int i = 0; i < MAXNUM; ++i) {
        char temp_char[256];
        for (int j = 0; j < 4; ++j) {
                inClientFile.getline(temp_char,256,'\n');// getline(char *, int, char)
                
                switch(j) {
                    case 0:Temp[i].Number = temp_char;break;
                    case 1:Temp[i].Name = temp_char;break;
                    case 2:Temp[i].Introduction = temp_char;break;
                    case 3:break;
                }

        }

    }
        
    return Temp;
}

void outputLine(std::string a, std::string b, std::string c) {
    std::cout << a << std::endl
              << b << std::endl
              << c << std::endl;
}

int main(int argc, char const *argv[])
{
    SS_Node* test;
    test = readSpot();

    for (int i = 0; i < 10; ++i) {
       std::cout << std::left << std::setw(10) << test[i].Number << std::setw(10) << test[i].Name << std::endl;
    }
    return 0;
}