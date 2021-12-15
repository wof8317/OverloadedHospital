#include <iostream>
#include <iomanip>// For setprecision() and fixed
#include <string>
using namespace std;

string patientName;
string repeater;
double selection;
double services;
double medications;
double totalCharges;
double daysInHospital;
double dailyHospitalCharge;

void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Calculate totalCharges if user selected option 1
double in_patient() {
    totalCharges = (dailyHospitalCharge * daysInHospital) + medications + services;
    cin.ignore();
    return totalCharges;
}

//Ditto, but for option 2 instead
double out_patient() {
    totalCharges = services + medications;
    cin.ignore();
    return totalCharges;
}

int main() {
    do {
            cout << "Welcome to Bay View Hospital\n";
            cout << "Please read through the following prompts to determine patients info:\n";
            cout << "Was the patient an in-patient or out-patient?\n\n";
            cout << "Please enter the patient's name: ";
            getline(cin, patientName);
            cout << "\nPlease make a selection:\n\n";
            cout << "1. Inpatient Bill\n";
            cout << "2. Outpatient Bill\n";
            cout << "3. Exit Application\n\n";
            cout << "Selection: ";
            cin >> selection;
            cin.ignore();
            
            //Determine what to do next after making a selection
            if (selection == 3) {
                //Just quit
                cout << "\nHave a nice day!\n";
                return 0;
            }
            else if (selection == 2) {
                //Ask user for the information required
                cout << "\nEnter the charges for services: $";
                cin >> services;
                cout << "Enter the medication expenses:  $";
                cin >> medications;
                out_patient();
                cout << setprecision(2) << fixed;
                cout << "The total charges for " << patientName << " are: ";
                cout << totalCharges;
            }
            else if (selection == 1) {
                //Ditto
                cout << "\nEnter the number of days patient \n";
                cout << patientName << " stayed in the hospital: ";
                cin >> daysInHospital;
                cout << "What is the daily hospital charge: $";
                cin >> dailyHospitalCharge;
                cout << "Enter the medication expenses:     $";
                cin >> medications;
                cout << "Enter the charges for services:    $";
                cin >> services;
                in_patient();
                cout << setprecision(2) << fixed;
                cout << "The total charges for " << patientName << " are: $";
                cout << totalCharges;
            }
            //Ask if the user wants to run the program again
            cout << "\n\nWould you like to create another Hospital Bill for another patient? (y/n) : ";
            getline(cin, repeater);
            if (repeater == "y")
                clear_console();
        }while (repeater != "n");
    return 0;
}
