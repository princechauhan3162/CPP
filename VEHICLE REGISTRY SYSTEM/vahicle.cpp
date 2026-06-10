#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    string fuelType;

public:
    static int totalvehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        fuelType = "";
        totalvehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr, string fuel)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        fuelType = fuel;
        totalvehicles++;
    }

    ~Vehicle()
    {
        totalvehicles--;
    }

    void displayInfo()
    {
        cout << "Vehicle ID   : " << vehicleID << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model        : " << model << endl;
        cout << "Year         : " << year << endl;
        cout << "Fuel Type    : " << fuelType << endl;
    }

    static int getVehicleCount()
    {
        return totalvehicles;
    }

    void setID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string manu)
    {
        manufacturer = manu;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    void setYear(int yr)
    {
        year = yr;
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    string getFuelType()
    {
        return fuelType;
    }
};

int Vehicle::totalvehicles = 0;

class Car : public Vehicle
{
public:
    Car() : Vehicle() {}

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr, fuel)
    {
    }

    void displayCar()
    {
        displayInfo();
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod,
                int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel)
    {
        batteryCapacity = battery;
    }

    void displayElectricCar()
    {
        displayCar();
        cout << "Battery Capacity : "
             << batteryCapacity << " kWh" << endl;
    }
};

class SportCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportCar(int id, string manu, string mod,
             int yr, string fuel,
             int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery)
    {
        topSpeed = speed;
    }

    void displaySportCar()
    {
        displayElectricCar();
        cout << "Top Speed : "
             << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod,
          int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod,
        int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }
};

class Aircraft
{
private:
    int flightRange;

public:
    Aircraft(int range = 0)
    {
        flightRange = range;
    }

    int getFlightRange()
    {
        return flightRange;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod,
              int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel),
          Aircraft(range)
    {
    }

    void displayFlyingCar()
    {
        displayCar();
        cout << "Flight Range : "
             << getFlightRange() << " km" << endl;
    }
};

class VehicleRegistry
{
private:
    Vehicle vehicles[100];
    int total;

public:
    VehicleRegistry()
    {
        total = 0;

        vehicles[total++] =
            Vehicle(1, "Toyota", "Corolla", 2020, "Petrol");

        vehicles[total++] =
            Vehicle(2, "Honda", "Civic", 2019, "Diesel");
    }

    void addVehicle()
    {
        int id, year;
        string manu, model, fuel;

        cout << "Enter ID : ";
        cin >> id;

        cout << "Enter Manufacturer : ";
        cin >> manu;

        cout << "Enter Model : ";
        cin >> model;

        cout << "Enter Fuel Type : ";
        cin >> fuel;

        cout << "Enter Year : ";
        cin >> year;

        vehicles[total++] =
            Vehicle(id, manu, model, year, fuel);

        cout << "Vehicle Added Successfully\n";
    }

    void displayVehicles()
    {
        for (int i = 0; i < total; i++)
        {
            cout << "\nVehicle " << i + 1 << endl;
            vehicles[i].displayInfo();
            cout << "----------------------\n";
        }
    }

    void searchVehicle(int id)
    {
        bool found = false;

        for (int i = 0; i < total; i++)
        {
            if (vehicles[i].getVehicleID() == id)
            {
                vehicles[i].displayInfo();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Vehicle Not Found\n";
        }
    }
};

int main()
{
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n===== Vehicle Registry =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Display Vehicles";
        cout << "\n3. Search Vehicle";
        cout << "\n4. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vr.addVehicle();
            break;

        case 2:
            vr.displayVehicles();
            break;

        case 3:
        {
            int id;
            cout << "Enter Vehicle ID : ";
            cin >> id;
            vr.searchVehicle(id);
            break;
        }

        case 4:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);
}