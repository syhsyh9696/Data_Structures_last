#include <iostream>

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

int main(int argc, char const *argv[])
{
	SS_Node te;
	te.getInformation();
	std::cout << te.getName();
	return 0;
}