#include <iostream>
using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int traincount;

public:
    Train()
    {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
        traincount++;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    Train(int num, string name = "", string src = "",
          string des = "", string time = "")
    {
        trainNumber = num;
        trainName = name;
        source = src;
        destination = des;
        trainTime = time;
        traincount++;
    }

    ~Train()
    {
        traincount--;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> trainName;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Train Time: ";
        cin >> trainTime;
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount()
    {
        return traincount;
    }
};
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
        trains[totalTrains++] = Train(101, "Okha Express", "Surat", "Mumbai", "10 AM");
        trains[totalTrains++] = Train(102, "Rajdhani Express", "Delhi", "Mumbai", "08 AM");
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "\nTrain record added successfully!\n";
        }
        else
        {
            cout << "Train storage is full!\n";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available!\n";
            return;
        }
        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " Details:\n";
            trains[i].displayTrainDetails();
            cout << "--------------------------\n";
        }
    };

    void searchTrainByNumber(int number)
    {
        bool found = false;
        ;
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Train with number " << number << " not found!\n";
        }
    }
};

int Train::traincount = 0;

int main()
{
    RailwaySystem r;
    int choice = 0;

    while (choice != 4)
    {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add  New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train By Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            r.addTrain();
            break;
        case 2:
            r.displayAllTrains();
            break;
        case 3:
        {
            int number;
            cout << "Enter Train Number to search: " << endl;
            cin >> number;
            r.searchTrainByNumber(number);
            break;
        }
        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}