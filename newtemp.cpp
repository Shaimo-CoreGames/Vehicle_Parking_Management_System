#include <conio.h>
// #include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Structure Definitions
struct EarnedMoney
{
    int carType;
    int busType;
    int truckType;
    int bikeType;
    int cycleType;
    int total;
};

struct Vehicle
{
    int vehicleNo;
    char shortDescription[60];
    char description[100];
    char createdBy[50];
    char lastUpdatedBy[50];
    char createdDateTime[50];
    char lastUpdatedDateTime[50];
    char complaint[200] = ""; // Added field for complaint
    int complaintNumber = 0;
    ; // Added unique complaint ID
    EarnedMoney earnedMoney;
};

// Function Prototypes
void initializeEarnedMoney(EarnedMoney *em);
void addEarnedMoney(EarnedMoney *oldMoney, EarnedMoney *newMoney);
void setEarnedMoney(EarnedMoney *earnedMoney, int vehicleType);
void showEarnedMoney(EarnedMoney *em);
void getAllEarnedMoney(EarnedMoney *em);
void saveEarnedMoney(EarnedMoney *em);

void setVehicle(Vehicle *vehicle);
void showVehicle(Vehicle *vehicle);
void addVehicle(Vehicle *vehicle);
void listAllVehicles();
void searchVehicle(int vehicleNo);
void deleteVehicle(int vehicleNo);
void updateVehicle(int vehicleNo);
void registerComplaint(int vehicleNo); // Function for registering complaints

int adminMenu();
int customerMenu();
void adminView();
void customerView();
// Main Function
int main()
{
    system("cls");
    cout << "                                 ========================================================================";
    cout << "\033[32m\n\n                                   -_- -_- -_- -_- -_-  VEHICLE MANAGEMENT SYSTEM  -_- -_- -_- -_- -_-\033[0m";
    cout << endl;
    cout << endl;
    cout << "                                                ______" << endl;
    cout << "                                  __/|_________/|____\\___" << endl;
    cout << "                                 |      Car       ________|" << endl;
    cout << "                                 '--(o)-------(o)--------'" << "\033[33m  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \033[0m" << endl;
    cout << endl;
    cout << "                                                                                           ______________" << endl;
    cout << "                                                                           _______________/|     Truck   |_" << endl;
    cout << "                                                                          |   ____________|______|______/|" << endl;
    cout << "\033[33m                                  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\033[0m" << "   '--(o)-------(o)------------(o)-'" << endl;

    cout << "\033[32m\n                                          Managing journeys, tracking fleets, driving success!\033[0m";
    cout << "\n                                 ========================================================================";

    int choice;
    while (true)
    {
        cout << "\033[32m\n\n--<<<<<<<< Specify Given Mode >>>>>>>>--\033[0m";
        cout << "\n         1. Admin Login\n         2. Customer Login\n         3. Exit";
        cout << "\033[32m\n<<<<<<<<------------------->>>>>>>>\033[0m";
        cout << ("\033[32m\n                                                           --> Enter Your Choice: \033[0m");
        cin >> choice;

        switch (choice)
        {
        case 1:
            adminView();
            break;
        case 2:
            customerView();
            break;
        case 3:
            cout << "\n                                               ====================================================================" << endl;
            cout << "\033[32m                                                 T H A N K   Y O U   F O R   U S I N G   T H E   S Y S T E M\033[0m" << endl;
            cout << "                                          ==========================================================================" << endl;
            cout << endl;
            cout << "\033[32m                                                                Your support means everything!\033[0m" << endl
                 << endl;
            cout << "\033[32m                                                                           GOOD BYE!\033[0m" << endl;

            return 0;
        default:
            cout << "\033[31m\n     ?__Invalid Choice__?\n\033[0m";
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            cin.get();
            cin.ignore();
        }
    }
}

// Admin and Customer Views
void adminView()
{
    string password;
    cout << "\nEnter Admin Password: ";
    cin >> password;
    if (password != "123")
    {
        cout << "\033[31m\n                                                   Invalid Password! Access Denied.\n\033[0m";
        cout << "                                                       Returning to the main menu...\n";
        return;
    }

    Vehicle vehicle;
    EarnedMoney earnedMoney;
    initializeEarnedMoney(&earnedMoney);
    int vno, breakLoop = 0;

    while (true)
    {
        switch (adminMenu())
        {
        case 1:
            setVehicle(&vehicle);
            addVehicle(&vehicle);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 2:
            cout << "\nEnter The Vehicle Number To Search: ";
            cin >> vno;
            searchVehicle(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 3:
            cout << "\nEnter The Vehicle Number To Delete: ";
            cin >> vno;
            deleteVehicle(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 4:
            cout << "\nEnter The Vehicle Number To Update: ";
            cin >> vno;
            updateVehicle(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 5:
            cout << "\033[32m\n_____________* Fleet Records *\n\033[0m";
            listAllVehicles();
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 6:
            cout << "\nEnter The Vehicle Number To Register Complaint: ";
            cin >> vno;
            registerComplaint(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 7:
            getAllEarnedMoney(&earnedMoney);
            showEarnedMoney(&earnedMoney);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 8:
            cout << "\nThank you for using the system. Goodbye!";
            breakLoop = 1;
            break;
        default:
            cout << "\033[31m\n     ?__Invalid Choice__?\n\033[0m";
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
        }
        if (breakLoop)
        {
            cout << endl;
            {
                cout << "\n                                               ==============================================" << endl;
                cout << "\033[32m                                                            T H A N K   Y O U\033[0m" << endl;
                cout << "                                               ==============================================" << endl;
                cout << endl;
                cout << "\033[32m                                                         Your support means everything!\033[0m" << endl;
                cout << "\033[32m                                                                     GOOD BYE!\033[0m" << endl;
            }
            break;
        }
    }
}
void customerView()
{
    Vehicle vehicle;
    int vno, breakLoop = 0;

    while (true)
    {
        switch (customerMenu())
        {
        case 1:
            setVehicle(&vehicle);
            addVehicle(&vehicle);
            cout << "___________________-_-__________________\n";
            cout << "\033[32m \n ---! Vehicle Parked Successfully !---\n\033[0m";
            cout << "________________________________________\n";
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 2:
            cout << "\nEnter The Vehicle Number To Search: ";
            cin >> vno;
            searchVehicle(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 3:
            cout << "\nEnter The Vehicle Number To Register Complaint: ";
            cin >> vno;
            registerComplaint(vno);
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
            break;
        case 4:
            cout << endl;
            {
                cout << "\n                                               ==============================================" << endl;
                cout << "\033[32m                                                            T H A N K   Y O U\033[0m" << endl;
                cout << "                                               ==============================================" << endl;
                cout << endl;
                cout << "\033[32m                                                         Your support means everything!\033[0m" << endl;
                cout << "\033[32m                                                                     GOOD BYE!\033[0m" << endl;
            }
            breakLoop = 1;
            break;
        default:
            cout << "\033[31m\n     ?__Invalid Choice__?\n\033[0m";
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
            getch();
        }
        if (breakLoop)
            break;
    }
}
// Admin Menu
int adminMenu()
{

    cout << "\n*Admin Menu:\n";
    cout << "\033[32m\n--<<<<<<<< things to be done >>>>>>>>--\033[0m";
    cout << "\n         -> 1. Add Vehicle\n";
    cout << "         -> 2. Search Vehicle\n";
    cout << "         -> 3. Delete Vehicle\n";
    cout << "         -> 4. Update Vehicle\n";
    cout << "         -> 5. List All Vehicles\n";
    cout << "         -> 6. Register Complaint\n";
    cout << "         -> 7. Check Earned Money\n";
    cout << "         -> 8. Logout\n";
    cout << "\033[32m\n<<<<<<<<------------------->>>>>>>>\033[0m";
    cout << ("\033[32m\n                                                           --> Enter Your Choice: \033[0m");
    int choice;
    cin >> choice;
    return choice;
}

// Customer Menu
int customerMenu()
{
    cout << "\n*Customer Menu:\n";
    cout << "\n\033[32m--<<<<<<<< things to be done >>>>>>>>--\n\033[0m";
    cout << "         -> 1. Park Vehicle\n";
    cout << "         -> 2. Search Vehicle\n";
    cout << "         -> 3. Register Complaint\n";
    cout << "         -> 4. Logout\n";
    cout << "\033[32m\n<<<<<<<<------------------->>>>>>>>\033[0m";
    cout << ("\033[32m\n                                                           --> Enter Your Choice: \033[0m");
    int choice;
    cin >> choice;
    return choice;
}

// Function Implementations
void initializeEarnedMoney(EarnedMoney *em)
{
    em->carType = 0;
    em->busType = 0;
    em->truckType = 0;
    em->bikeType = 0;
    em->cycleType = 0;
    em->total = 0;
}

void addEarnedMoney(EarnedMoney *oldMoney, EarnedMoney *newMoney)
{
    oldMoney->carType += newMoney->carType;
    oldMoney->busType += newMoney->busType;
    oldMoney->truckType += newMoney->truckType;
    oldMoney->bikeType += newMoney->bikeType;
    oldMoney->cycleType += newMoney->cycleType;
    oldMoney->total = oldMoney->carType + oldMoney->busType + oldMoney->truckType + oldMoney->bikeType + oldMoney->cycleType;
}

void setEarnedMoney(EarnedMoney *earnedMoney, int vehicleType)
{
    switch (vehicleType)
    {
    case 1:
        earnedMoney->carType += 100;
        earnedMoney->total += 100;
        break;
    case 2:
        earnedMoney->busType += 200;
        earnedMoney->total += 200;
        break;
    case 3:
        earnedMoney->truckType += 400;
        earnedMoney->total += 400;
        break;
    case 4:
        earnedMoney->bikeType += 50;
        earnedMoney->total += 50;
        break;
    case 5:
        earnedMoney->cycleType += 20;
        earnedMoney->total += 20;
        break;
    default:
        cout << "\033[31m\n     ?__Invalid Choice__?\n\033[0m";
        cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
    }
}

void getAllEarnedMoney(EarnedMoney *em)
{
    ifstream fin("EarnedMoney.txt");
    if (!fin)
    {
        initializeEarnedMoney(em);
    }
    else
    {
        fin >> em->carType >> em->busType >> em->truckType >> em->bikeType >> em->cycleType >> em->total;
        fin.close();
    }
}

void saveEarnedMoney(EarnedMoney *em)
{
    ofstream fout("EarnedMoney.txt");
    fout << em->carType << " " << em->busType << " " << em->truckType << " "
         << em->bikeType << " " << em->cycleType << " " << em->total;
    fout.close();
}

void showEarnedMoney(EarnedMoney *em)
{
    cout << "\n--------------------------------------------------------------------------\n";
    cout << setw(10) << "    Car    |" << setw(10) << "   Bus     |" << setw(10) << "   Truck   |" << setw(10) << "   Bike    |" << setw(10) << "   Cycle   |" << setw(10) << "    TOTAL  |";
    cout << "\n -----------------------------------------------------------------------\n";
    cout << setw(9) << em->carType << "  |" << setw(9) << em->busType << "  |" << setw(9) << em->truckType << "  |" << setw(9) << em->bikeType << "  |" << setw(9) << em->cycleType << "  |" << setw(9) << em->total << "  |";
    cout << "\n--------------------------------------------------------------------------\n";
}

void setVehicle(Vehicle *vehicle)
{
    initializeEarnedMoney(&vehicle->earnedMoney);

    int vehicleType;
    while (1)
    {
        cout << "\033[32mSelect Vehicle Type:\n\033[0m"
             << setw(13) << "1. Car " << setw(13) << "2. Bus " << setw(15) << "3. Truck "
             << setw(14) << "4. Bike " << setw(15) << "5. Cycle\n";
        cin >> vehicleType;
        if (vehicleType >= 1 && vehicleType <= 5)
        {
            setEarnedMoney(&vehicle->earnedMoney, vehicleType);
            break;
        }
        else
        {
            cout << "\033[31m\n     ?__Invalid Choice__?\n\033[0m";
            cout << "\033[32m\n                                                            Tap Any Key To Advance...\033[0m";
        }
    }

    cout << "\nEnter Vehicle Number: ";
    cin >> vehicle->vehicleNo;
    cin.ignore();
    cout << "Enter Short Description: ";
    cin.getline(vehicle->shortDescription, 30);
    cout << "Enter Description: ";
    cin.getline(vehicle->description, 100);
    strcpy(vehicle->createdBy, "Admin");
    strcpy(vehicle->lastUpdatedBy, "Admin");

    // for current date and time

    auto now = chrono ::system_clock ::now();
    auto timeT = chrono ::system_clock ::to_time_t(now);
    struct tm *timeInfo = localtime(&timeT);
    strftime(vehicle->createdDateTime, sizeof(vehicle->createdDateTime), "%c", timeInfo);
    strftime(vehicle->lastUpdatedDateTime, sizeof(vehicle->lastUpdatedDateTime), "%c", timeInfo);
}

void addVehicle(Vehicle *vehicle)
{
    ofstream fout("VehicleData.txt", ios::app);
    fout << vehicle->vehicleNo << ","
         << vehicle->shortDescription << ","
         << vehicle->description << ","
         << vehicle->createdBy << ","
         << vehicle->lastUpdatedBy << ","
         << vehicle->createdDateTime << ","
         << vehicle->lastUpdatedDateTime << ","
         << vehicle->complaint << ","
         << vehicle->complaintNumber << endl; // Use endl to ensure each entry is on a new line
    fout.close();

    EarnedMoney em;
    getAllEarnedMoney(&em);
    addEarnedMoney(&em, &vehicle->earnedMoney);
    saveEarnedMoney(&em);

    cout << "___________________-_-__________________\n";
    cout << "\033[31m\n ---! Record Added Successfully !---\n\033[0m";
    cout << "________________________________________\n";
}

void registerComplaint(int vehicleNo)
{
    ifstream fin("VehicleData.txt");
    ofstream fout("TempData.txt");
    if (!fin)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    File not Found    !---\n\033[0m";
        cout << "________________________________________\n";
        return;
    }

    string line;
    bool found = false;
    char newComplaint[200];

    cout << "Enter Complaint Description: ";
    cin.ignore();
    cin.getline(newComplaint, sizeof(newComplaint));

    while (getline(fin, line))
    {
        if (line.find(to_string(vehicleNo)) != string::npos)
        {

            Vehicle vehicle;

            stringstream ss(line);
            string strVehicleNo;

            getline(ss, strVehicleNo, ',');
            vehicle.vehicleNo = stoi(strVehicleNo);

            string temp;

            getline(ss, temp, ',');
            strncpy(vehicle.shortDescription, temp.c_str(), sizeof(vehicle.shortDescription) - 1);
            vehicle.shortDescription[sizeof(vehicle.shortDescription) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.description, temp.c_str(), sizeof(vehicle.description) - 1);
            vehicle.description[sizeof(vehicle.description) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.createdBy, temp.c_str(), sizeof(vehicle.createdBy) - 1);
            vehicle.createdBy[sizeof(vehicle.createdBy) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.lastUpdatedBy, temp.c_str(), sizeof(vehicle.lastUpdatedBy) - 1);
            vehicle.lastUpdatedBy[sizeof(vehicle.lastUpdatedBy) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.createdDateTime, temp.c_str(), sizeof(vehicle.createdDateTime) - 1);
            vehicle.createdDateTime[sizeof(vehicle.createdDateTime) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.lastUpdatedDateTime, temp.c_str(), sizeof(vehicle.lastUpdatedDateTime) - 1);
            vehicle.lastUpdatedDateTime[sizeof(vehicle.lastUpdatedDateTime) - 1] = '\0';

            getline(ss, temp, ',');
            strncpy(vehicle.complaint, temp.c_str(), sizeof(vehicle.complaint) - 1);
            vehicle.complaint[sizeof(vehicle.complaint) - 1] = '\0';

            ss >> vehicle.complaintNumber;

            strcpy(vehicle.complaint, newComplaint);
            vehicle.complaintNumber++;

            fout << vehicle.vehicleNo << ","
                 << vehicle.shortDescription << ","
                 << vehicle.description << ","
                 << vehicle.createdBy << ","
                 << vehicle.lastUpdatedBy << ","
                 << vehicle.createdDateTime << ","
                 << vehicle.lastUpdatedDateTime << ","
                 << vehicle.complaint << ","
                 << vehicle.complaintNumber << "," << endl;

            found = true;
        }

        else
        {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("VehicleData.txt");
    rename("TempData.txt", "VehicleData.txt");

    if (found)
    {
        cout << "___________________-_-__________________\n";
        cout << "\033[32m\n ---! Complaint Registered Successfully !---\n[0m";
        cout << "________________________________________\n";
    }
    else
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    Record not Found    !---\n\033[0m";
        cout << "________________________________________\n";
    }
}

void listAllVehicles()
{
    ifstream fin("VehicleData.txt");
    if (!fin)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    File not Found    !---\n\033[0m";
        cout << "________________________________________\n";
        return;
    }

    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string vehicleNo, shortDescription, description, createdBy, lastUpdatedBy, createdDateTime, lastUpdatedDateTime, complaint;
        int complaintNumber;

        // Read data using ',' as a delimiter
        getline(ss, vehicleNo, ',');
        getline(ss, shortDescription, ',');
        getline(ss, description, ',');
        getline(ss, createdBy, ',');
        getline(ss, lastUpdatedBy, ',');
        getline(ss, createdDateTime, ',');
        getline(ss, lastUpdatedDateTime, ',');
        getline(ss, complaint, ',');
        ss >> complaintNumber;

        // Output the data

        if (!(ss >> complaintNumber))
        {
            complaintNumber = 0;
        }

        if (!(vehicleNo.empty()))
        {
            cout << "----------\n";
            cout << "Vehicle Number:     " << vehicleNo << endl;
            cout << "Short Description:   " << shortDescription << endl;
            cout << "Description:        " << description << endl;
            cout << "Created By:         " << createdBy << endl;
            cout << "Last Updated By:    " << lastUpdatedBy << endl;
            cout << "Created Date & Time: " << createdDateTime << endl;
            cout << "Last Updated Date & Time: " << lastUpdatedDateTime << endl;
            cout << "Complaint:          " << complaint << endl;
            cout << "Complaint Number:   " << complaintNumber << endl;
            cout << "----------------------------------------\n";
        }
    }
    fin.close();
}

void searchVehicle(int vno)
{
    ifstream fin("VehicleData.txt");
    if (!fin)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    File not Found    !---\n\033[0m";
        cout << "________________________________________\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(fin, line))
    {
        if (line.find(to_string(vno)) != string::npos)
        {
            found = true;

            stringstream ss(line);
            string vehicleNo, shortDescription, description, createdBy, lastUpdatedBy, createdDateTime, lastUpdatedDateTime, complaint;
            int complaintNumber;

            getline(ss, vehicleNo, ',');
            getline(ss, shortDescription, ',');
            getline(ss, description, ',');
            getline(ss, createdBy, ',');
            getline(ss, lastUpdatedBy, ',');
            getline(ss, createdDateTime, ',');
            getline(ss, lastUpdatedDateTime, ',');
            getline(ss, complaint, ',');
            ss >> complaintNumber;

            cout << "----------------------------------------\n";
            cout << "Vehicle Number:     " << vehicleNo << endl;
            cout << "Short Description:   " << shortDescription << endl;
            cout << "Description:        " << description << endl;
            cout << "Created By:         " << createdBy << endl;
            cout << "Last Updated By:    " << lastUpdatedBy << endl;
            cout << "Created Date & Time: " << createdDateTime << endl;
            cout << "Last Updated Date & Time: " << lastUpdatedDateTime << endl;
            cout << "Complaint:          " << complaint << endl;
            cout << "Complaint Number:   " << complaintNumber << endl;
            cout << "----------------------------------------\n";

            break;
        }
    }

    if (!found)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    Vehicle not Found    !---\n\033[0m";
        cout << "________________________________________\n";
    }

    fin.close();
}

void deleteVehicle(int vno)
{
    ifstream fin("VehicleData.txt");
    ofstream fout("TempData.txt");
    if (!fin)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    File not Found    !---\n\033[0m";
        cout << "________________________________________\n";
        return;
    }
    string line;
    bool found = false;
    while (getline(fin, line))
    {
        // agr condition true ho(number found),to subscript ka index return hota jo { false } consider hota
        // agr condition false ho(number not found),to string::npos return hota jo { true } consider hota
        if (line.find(to_string(vno)) == string::npos)
        {
            fout << line << endl;
        }
        else
        {
            found = true;
        }
    }
    fin.close();
    fout.close();
    remove("VehicleData.txt");
    rename("TempData.txt", "VehicleData.txt");
    if (found)
    {
        cout << "___________________-_-__________________\n";
        cout << "\033[32m\n ---!    Vehicle Deleted Successfully    !---\n\033[0m";
        cout << "________________________________________\n";
    }
    else
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[32m\n ---!    Vehicle not Found    !---\n\033[0m";
        cout << "________________________________________\n";
    }
}
void updateVehicle(int vno)
{
    ifstream fin("VehicleData.txt");
    ofstream fout("TempData.txt");
    if (!fin)
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    File not Found    !---\n\033[0m";
        cout << "________________________________________\n";
        return;
    }
    string line;
    bool found = false;
    Vehicle vehicle;
    while (getline(fin, line))
    {
        if (line.find(to_string(vno)) != string::npos)
        {
            cout << "\033[32mUPDATING VEHICLE: \033[0m" << endl;
            cout << "--------------------\n";
            setVehicle(&vehicle);

            fout << vehicle.vehicleNo << ","
                 << vehicle.shortDescription << ","
                 << vehicle.description << ","
                 << vehicle.createdBy << ","
                 << vehicle.lastUpdatedBy << ","
                 << vehicle.createdDateTime << ","
                 << vehicle.lastUpdatedDateTime << ","
                 << vehicle.complaint << ","
                 << vehicle.complaintNumber << "," << endl;
            found = true;
        }
        else
        {
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();
    remove("VehicleData.txt");
    rename("TempData.txt", "VehicleData.txt");
    if (found)
    {
        cout << "___________________-_-__________________\n";
        cout << "\033[32m\n ---!    Vehicle updated Successfully    !---\n\033[0m";
        cout << "________________________________________\n";
    }
    else
    {
        cout << "___________________-?-__________________\n";
        cout << "\033[31m\n ---!    Vehicle not Found    !---\n\033[0m";
        cout << "________________________________________\n";
    }
}

int menu()
{
    cout << "\033[32m\n\n--<<<<<<<< things to be done >>>>>>>>--\033[0m";
    cout << "\n1. Add Vehicle\n2. Search Vehicle\n3. Delete Vehicle\n4. Update Vehicle\n5. List All Vehicles\n6. Check Earned Money\n7. Exit\nEnter Choice: ";
    cout << "\033[32m\n<<<<<<<<------------------->>>>>>>>\033[0m";
    int choice;
    cout << ("\033[32m\n                                                           --> Enter Your Choice: \033[0m");
    cin >> choice;
    return choice;
}