/*Fundamental Data Structure
Project: Phase 3
Author: Fatma Xhafa*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int NO_OF_CHARS = 256; //global variable

//utility function to determine the range of the variables which will be chosen
//label is initialized to Choice: by default
int chooseBetween(int min, int max, string label) {
	int choice;

	do {
		cout << label << ": "; cin >> choice;

		// > validate input data type
		while (cin.fail()) {
			cin.clear(); cin.ignore(INT_MAX, '\n');

			cout << "Invalid input." << endl << endl;
			cout << label << ": "; cin >> choice;
		}

		// > validate the range
		if (choice < min || choice > max) {
			cout << "Invalid input." << endl;
		}

	} while (choice < min || choice > max || cin.fail());

	return choice;
}

//interface of the classes
//parent class, all of the other classes will inherit from this one
class Extracurricular {
public:
	//This is the default constructor for this class.
	Extracurricular() {
		this->name = "";
		this->description = "";
	}
	//entering data through the class' constructor
	Extracurricular(string Name, string Description) {
		this->name = Name;
		this->description = Description;
	}
	//getting name of the Extracurricular, which is not going to change
	string getName() const { return this->name; }
	string getDescription() const { return this->description; }
	//this is the polymorphic method, which all the classes have  
	virtual double getTotalBudget() = 0;

protected:
	//attributes of the Extracurricular class
	string name, description;
};

//child class of Extracurricular, which serves as parent class for StartUP and TedX
class Clubs : public Extracurricular {
public:
	//the default constructor for the Clubs class, without parametres
	Clubs()
	{
		this->nameOfPresident = "";
		this->numberOfMembers = 0;
		this->budgetFromSponsors = 0.0;
		this->budgetFromStudentGov = 0.0;
	}

	//the class constructor, now overriding the default constructor
	Clubs(string name, string description, string nameOfPresident, int numberOfMembers, double budgetFromSponsors, double budgetFromStudentGov)
	:Extracurricular(name, description) {

		this->nameOfPresident = nameOfPresident;
		this->numberOfMembers = numberOfMembers;
		this->budgetFromSponsors = budgetFromSponsors;
		this->budgetFromStudentGov = budgetFromStudentGov;
	}
	//the following methods are implemented to access the properties of the class
	string getNameOfPresident() {
		return nameOfPresident;
	}
	int getNumberOfMembers() {
		return numberOfMembers;
	}
	virtual double getTotalBudget() {
		return budgetFromSponsors + budgetFromStudentGov;
	}

	virtual string getDepartments() = 0;

protected:
	//properties of the Clubs class 
	string nameOfPresident;
	int numberOfMembers;
	double budgetFromSponsors;
	double budgetFromStudentGov;
};
vector <Clubs *> clubs;

//child class of Extracurricular, which serves as parent class for Griffins and Olympics
class Sports : public Extracurricular {
public:
	//the default constructor for the Clubs class, without parametres
	Sports() {
		this->nameOfPresident = "";
		this->numberOfMembers = 0;
		this->budgetFromSponsors = 0.0;
		this->nameOfSport = "";
	}

	//the class constructor, now overriding the default constructor
	Sports(string name, string description, string nameOfPresident, int numberOfMembers, double budgetFromSponsors, string nameOfSport)
		:Extracurricular (name, description) {

		this->nameOfPresident = nameOfPresident;
		this->numberOfMembers = numberOfMembers;
		this->budgetFromSponsors = budgetFromSponsors;
		this->nameOfSport = nameOfSport;
	}
	//the following methods are methods that access the data of the class and return their value
	string getNameOfPresident() {
		return nameOfPresident;
	}
	int getNumberOfMembers() {
		return numberOfMembers;
	}
	string getTypeOfSport() {
		return nameOfSport;
	}
	virtual double getTotalBudget() {
		return this->budgetFromSponsors;
	}

	virtual string getSport() = 0;
	virtual int getNumberOfPlayers() { return 0;  }
	virtual string getDepartments() { return "";  };

protected:
	//properties of the class 
	string nameOfPresident;
	int numberOfMembers;
	double budgetFromSponsors;
	string nameOfSport;
};
vector<Sports *>sports;\

//child classes of Clubs, which will inherit methods and attributes both from Clubs and Extracurricular class 
class StartUP : public Clubs {
public:
	//the default constructor for the Clubs class, without parametres
	StartUP()
	{
		this->departments = "";
	}

	//the class constructor, now overriding the default constructor
	StartUP(string name, string description, string nameOfPresident, int numberOfMembers, double budgetFromSponsors, double budgetFromStudentGov, string departments) 
		: Clubs(name, description, nameOfPresident, numberOfMembers, budgetFromSponsors, budgetFromStudentGov) {
		this->departments = departments;
	}

	string getDepartments() {
		return departments;
	}
	double getTotalBudget() {
		return budgetFromSponsors + budgetFromStudentGov;
	}
private:
	string departments;
};
class TedX : public Clubs {
public:
	//the default constructor for the Clubs class, without parametres
	TedX()
	{
		this->departments = "";
	}

	//the class constructor, now overriding the default constructor
	TedX(string name, string description,string nameOfPresident, int numberOfMembers, double budgetFromSponsors, double budgetFromStudentGov, string departments)
	:Clubs (name, description, nameOfPresident, numberOfMembers, budgetFromSponsors, budgetFromStudentGov){

		this->departments = departments;
	}

	string getDepartments() {
		return departments;
	}

	double getTotalBudget() {
		return budgetFromSponsors + budgetFromStudentGov;
	}
private:
	string departments;
	
};
//child classes of Sports, which will inherit methods and attributes both from Sports and Extracurricular class 
class Griffins : public Sports {
public:
	//the default constructor for the Clubs class, without parametres
	Griffins()
	{
		this->numberOfPlayers = 0;
	}

	//the class constructor, now overriding the default constructor
	Griffins(string name, string description, string nameOfPresident, int numberOfMembers, double budgetFromSponsors, string nameOfSport, int numberOfPlayers)
		: Sports(name, description, nameOfPresident, numberOfMembers, budgetFromSponsors, nameOfSport) {

		this->numberOfPlayers = numberOfPlayers;
	}
	int getNumberOfPlayers() {
		return numberOfPlayers;
	}
	double getTotalBudget() {
	return budgetFromSponsors;
	}

	string getSport() {
		return "Griffins";
	}
private:
	int numberOfPlayers;

};
class Olympics : public Sports {
public:
	//the default constructor for the Clubs class, without parametres
	Olympics()
	{
		this->departments = "";
	}

	//the class constructor, now overriding the default constructor
	Olympics(string name, string description, string nameOfPresident, int numberOfMembers, double budgetFromSponsors, string nameOfSport, string departments)
		: Sports (name, description, nameOfPresident, numberOfMembers, budgetFromSponsors, nameOfSport) {

		this->departments = departments;
	}

	string getDepartments() {
		return departments;
	}
	double getTotalBudget(){
		return budgetFromSponsors;
	}

	string getSport() {
		return "Olympics";
	}
private:
	string departments;
	
};

//the next two functions are both utility functions which are only called when it is needed to display the menu
void displayHeader() {
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "        Welcome to the AUBG extracurricular activities database! " << endl << endl;
	cout << setw(45) << "Author: Fatma Xhafa" << endl << endl;
	cout << "   In our university, there are clubs and sports. Please choose " << endl;
	cout << "   one of the options below to get more information about them." << endl << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n1.Search." << endl << "2.Highest budget." << endl << "3.Exit." << endl;
}
void displayOptions() {
	cout << endl;
	cout << "1.Search." << endl << "2.Highest budget." << endl << "3.Exit." << endl << endl;
}

//these methods are used to retrieve information from the respective files for each child class
//all the data is stored in a vector in order to be loaded into the program and when it is no longer needed, it is deleted
void StartUPInfo(fstream& in) {
	
	vector<StartUP> startup;

	in.open("./Data/StartUP.txt");
	if (in.fail()) {
		cout << "File failed to open." << endl;
		EXIT_FAILURE;
	}
	else {
		string line;
		vector<string> startupData;

		while (getline(in, line)) { //reading elements from the file, line by line
			startupData.push_back(line);  //stores all the elements from the file in a vector 
		}


		Clubs * startup = new StartUP(
			startupData[0], // name
			startupData[1], // description
			startupData[2], // president name
			atoi(startupData[3].c_str()), // number of members
			atof(startupData[4].c_str()), // budget from sponsors
			atof(startupData[5].c_str()), // budget from student gov
			startupData[6] // dep
		);

		clubs.push_back(startup); 


		startupData.clear();

		in.close();
	}

}
void TedXInfo(fstream& in) {
	vector<TedX>tedx;

	in.open("./Data/TedX.txt");
	if (in.fail()) {
		cout << "File failed to open." << endl;
		EXIT_FAILURE;
	}
	else {
		string line;
		vector<string> tedxData;
		while (getline(in, line)) { //reading elements from the file, line by line
			tedxData.push_back(line);  ////stores all the elements from the file in a vector 
		}
		Clubs * tedx = new TedX(
			tedxData[0], // name
			tedxData[1], // description
			tedxData[2], // president name
			atoi(tedxData[3].c_str()), // number of members
			atof(tedxData[4].c_str()), // budget from sponsors
			atof(tedxData[5].c_str()), // budget from student gov
			tedxData[6] // departments
		);

		clubs.push_back(tedx);

		tedxData.clear();

		in.close();
	}

}
void GriffinsInfo(fstream& in) {
	
	vector<Griffins>griffins;

	in.open("./Data/Griffins.txt");
	if (in.fail()) {
		cout << "File failed to open." << endl;
		EXIT_FAILURE;
	}
	else {
		string line;
		vector<string> griffinsData;
		while (getline(in, line)) {     //reading elements from the file, line by line
			griffinsData.push_back(line);  //stores all the elements from the file in a vector 
		}

		Sports * griffins = new Griffins (
			griffinsData[0], // name
			griffinsData[1], // description
			griffinsData[2], // president name
			atoi(griffinsData[3].c_str()), // number of members
			atof(griffinsData[4].c_str()), // budget from sponsors
			griffinsData[5],//sport type
			atoi(griffinsData[6].c_str()) // number of players
		);

		sports.push_back(griffins);


		griffinsData.clear();

		in.close();
	}

}
void OlympicsInfo(fstream& in) {

	vector<Olympics>olympics;

	in.open("./Data/Olympics.txt");
	if (in.fail()) {
		cout << "File failed to open." << endl;
		EXIT_FAILURE;
	}
	else {
		string line;
		vector<string> olympicsData;
		while (getline(in, line)) {    //reading elements from the file, line by line
			olympicsData.push_back(line);   //stores all the elements from the file in a vector 
		}

		Sports * olympics = new Olympics(
			olympicsData[0], // name
			olympicsData[1], // description
			olympicsData[2], // president name
			atoi(olympicsData[3].c_str()), // number of members
			atof(olympicsData[4].c_str()), // budget from sponsors
			olympicsData[5],//sport type
			olympicsData[6] // departments
		);

		sports.push_back(olympics);


		olympicsData.clear();

		in.close();
	}

}

//implementation of the quicksort algorithm, used to sort the clubs based on their budget
int partition(vector<Extracurricular*>& ex, int p, int q)
{
	int x = ex[p]->getTotalBudget();
	int i = p;
	int j;
	for (j = p + 1; j <= q; j++)

	{
		if ((ex[j]->getTotalBudget()) <= x)
		{
			i = i + 1;
			swap(ex[i], ex[j]);
		}
	}
	swap(ex[i], ex[p]);
	return i;
}
void quickSort(vector<Extracurricular*>& ex, int p, int q)
{
	int r;
	if (p < q)
	{
		r = partition(ex, p, q);
		quickSort(ex, p, r);
		quickSort(ex, r + 1, q);
	}

}

//get maximum of 2 integers, utility function
int max(int a, int b) { return (a > b) ? a : b; }
//implementation of the Boyer-Moore string pattern matching algorithm
void badCharHeuristic(string pat, int patternLength, int badchar[NO_OF_CHARS]) {
	int i;
	for (i = 0; i < NO_OF_CHARS; i++) {
		badchar[i] = -1;
	}
	for (i = 0; i < patternLength; i++) {
		badchar[(int)pat[i]] = i;
	}
}
bool search(string text, string pat) {

	unsigned int patternLength = pat.length();
	unsigned int textLength = text.length();

	int j = patternLength - 1; //j is index of pattern
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, patternLength, badchar); //function call
	int shift = 0;


	while (shift <= (textLength - patternLength)) {
		while (j >= 0 && pat[j] == text[shift + j])
			j--;
		if (j < 0) {
			shift += (shift + patternLength < textLength) ? patternLength - badchar[text[shift + patternLength]] : 1;
		}
		else {
			shift += max(1, j - badchar[text[shift + j]]);
		}
	}
	return j < 0;
}

vector<Extracurricular*>query;

//these 2 functions will be called in the main function, they are implemented to display choices and 
//prompts the user continously for choices, until they choose to exit
void clubsfunction(int i) {
	int a;
	if (!clubs.empty()) {

		do {
			cout << "What do you want to know about " << clubs[i]->getName() << "?" << endl;
			cout << "1.Name of president" << endl;
			cout << "2.About the club" << endl;
			cout << "3.Number of members" << endl;
			cout << "4.Departments" << endl;
			cout << "5.Back to main menu." << endl;
			
			a = chooseBetween(1, 5, "Choice");

			switch (a) {
				case 1:
					cout << "\nThe president's name is: " << clubs[i]->getNameOfPresident() << endl << endl;
					cout<<"--------------------------------------------------------------------"<<endl;
					break;
				case 2:
					cout << "\nAbout the club: " << endl;
					cout << clubs[i]->getDescription() << endl << endl;
					cout << "--------------------------------------------------------------------" << endl;
					break;
				case 3:
					cout << "\nNumber of members in this club is: " << clubs[i]->getNumberOfMembers() << endl << endl;
					cout << "--------------------------------------------------------------------" << endl;
					break;
				case 4:
					cout << "\nDepartments of this club are the following: " << clubs[i]->getDepartments() << endl << endl;
					cout << "--------------------------------------------------------------------" << endl;
					break;
				default:
					break;
			}
		} while (a < 5 && a > 0);
	}
}
void sportsfunction(int i) {
	int a;
	if (!sports.empty()) {

		do {
			cout << "What do you want to know about " << sports[i]->getName() << "?" << endl;
			cout << "1.Name of president" << endl;
			cout << "2.About" << endl;
			cout << "3.Number of members" << endl;
			cout << "4.Departments (for Olympics) or number of players (for Griffins)" << endl;
			cout << "5. Type of sport" << endl;
			cout << "6.Back to main menu." << endl;

			a = chooseBetween(1, 6, "Choice");

			switch (a) {
			case 1:
				cout <<"\nThe president's name is: " << sports[i]->getNameOfPresident() << endl << endl;
				cout << "--------------------------------------------------------------------" << endl;
				break;
			case 2:
				cout << "\nAbout: " << endl;
				cout << sports[i]->getDescription() << endl << endl;
				cout << "--------------------------------------------------------------------" << endl;
				break;
			case 3:
				cout << "\nNumber of members in this club/team is: " << sports[i]->getNumberOfMembers() << endl << endl;
				cout << "--------------------------------------------------------------------" << endl;
				break;
			case 4:
				if (sports[i]->getSport() == "Griffins") {
					cout<<"\nNumber of the players in the team: " << sports[i]->getNumberOfPlayers() << endl <<endl;
					cout << "--------------------------------------------------------------------" << endl;
				}

				else if (sports[i]->getSport() == "Olympics") {
					cout << "\nDepartments of this club/team are: " << sports[i]->getDepartments() << endl << endl;
					cout << "--------------------------------------------------------------------" << endl;
				}
				break;
			case 5:
				cout << "\nSport(s) played in this club/team is/are: " << sports[i]->getTypeOfSport() << endl << endl;
				cout << "--------------------------------------------------------------------" << endl;
			default:
				break;
			}
		} while (a < 6 && a > 0);
	}
}

int main()  { 
	fstream in;
	
	StartUPInfo(in);
	TedXInfo(in);
	OlympicsInfo(in);
	GriffinsInfo(in);

	vector<Extracurricular*>ex;  //vector in which all the instances of the child classes will be stored 
	ex.push_back(clubs[0]);     //startup
	ex.push_back(clubs[1]);    //tedx
	ex.push_back(sports[0]);  //olympics
	ex.push_back(sports[1]); //griffins

	displayHeader();

	int n, c;
	string pattern;

	do {
		n = chooseBetween(1, 3, "Choice");
		cout << endl;
		switch (n) {
		case 1:
			cout << "Please select one of the options below." << endl;
			cout << "1.Clubs." << endl;
			cout << "2.Sports." << endl;
			c = chooseBetween(1, 2, "Choice");
			cout << endl;
			
			if (c == 1) {
				cout << "Search for a club (StartUP or TedX) : ";
				cin >> pattern;
				//string pattern matching
				for (int i = 0; i < pattern.length(); i++) {
					pattern[i] = tolower(pattern[i]); //this is done to recognize the lowercase and uppercase characters as the same 
				}
				if (!pattern.empty()) {

					for (int j = 0; j < ex.size(); ++j) {
						if (search(ex[j]->getName(), pattern)) {  
							query.push_back(ex[j]);
						}
					}
				}
				cout << "\n--------------------------------------------------------------------" << endl;
				if (pattern == "startup") {
					clubsfunction(0);
				}
				else if (pattern == "tedx") {
					clubsfunction(1);
				}
				else {
					cout << "The string you entered does not match any of the clubs in our database." << endl;
				}
				displayOptions();
			}
			else if (c == 2) {
				cout << "Search for a sport (Griffins or Olympics) : ";
				cin >> pattern;
				for (int i = 0; i < pattern.length(); i++) {
					pattern[i] = tolower(pattern[i]);
				}
				if (!pattern.empty()) {

					for (int j = 0; j < ex.size(); ++j) {
						if (search(ex[j]->getName(), pattern)) {
							query.push_back(ex[j]);
						}
					}
				}
				cout << "\n--------------------------------------------------------------------" << endl;
				if (pattern == "olympics") {
					sportsfunction(0);
				}
				else if (pattern == "griffins") {
					sportsfunction(1);
				}
				else {
					cout << "The string you entered does not match any of the clubs in our database." << endl;
				}
				displayOptions();
			}
			break;
		case 2:
			cout << "AUBG'S clubs and sports, sorted according to their total budget, from lowest to highest: " << endl;
			quickSort(ex, 0, ex.size() - 1);
			for (int i = 0; i < ex.size(); ++i) {
				cout << ex[i]->getName() << " : $ " << ex[i]-> getTotalBudget() << endl;
			}
			cout << "--------------------------------------------------------------------" << endl;
			displayOptions();
			break;
		case 3:
			cout << "Goodbye!" << endl;  
		default:
			break;
		}
	} while (n != 3);
		return 0;
}