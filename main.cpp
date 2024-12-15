#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Plate{
    string state;
    int number;
};

class Vehicle
{
protected:
        float weight;
        int axle;
        int toll_distance;
        string fuel;
        Date manufacture_date;
        Plate registration; // state of registration
        string toll_type; // one way trip/two way trip/oneday pass/monthly pass
        int engine_capacity;
        bool public_transport;
        string payment; // cash or fasttag
        float toll_fee;
        string city;
        
public:
    	Vehicle() : axle(0), toll_fee(0.0), toll_distance(0), public_transport(false) {}

	void inputvehicledetails()
        {

            cout << "Enter Registration Plate: " << endl;
            cin >> registration.state >> registration.number;

            cout << "Enter Date of Manufacture (DD-MM-YYYY): " << endl;
            cin >> manufacture_date.day >> manufacture_date.month >> manufacture_date.year;

            cout << "Enter Weight of the Vehicle: " << endl;
            cin >> weight;
            
            /*cout << "Enter Distance from previous Toll: " << endl;
            cin >> toll_distance;*/

            cout << "Enter Fuel type (Petrol, Electric, CNG, Diesel):  " << endl;
            cin >> fuel;

            cout << "Enter Toll Type (Single, Round, Toll Pass): " << endl;
            cin.ignore();
            getline(cin, toll_type);

            cout << "Enter Engine Capacity: " << endl;
            cin >> engine_capacity;

            cout << "Public_transport Transport Vehicle? (1 for true/ 0 for false)" << endl;
            cin >> public_transport;

            cout << "Enter Payment Type? (Cash/Digital)" << endl;
            cin >> payment;

            toll_distance=get_toll_distance();
        }

        // Vehicle(float weight, string city, string fuel, Date manufacture_date, string registation, string toll_type, int engine_capacity, bool public_transport, string payment)
        // {
        //     this->weight = weight;
        //     this->city = city;
        //     this->fuel = fuel;
        //     this->manufacture_date = manufacture_date;
        //     this->registation = registration; 
        //     this->toll_type = toll_type;
        //     this->engine_capacity = engine_capacity;
        //     this->public_transport = public_transport;
        //     this->payment = payment;
        // }

	 string getRegistrationState() const 
	 {
		return registration.state;
	 }

	 int getRegistrationNumber() const 
	 {
		return registration.number;
         }
        int get_toll_distance()
        {   
            int city;
            cout << "Select the city: 1.Kochi 2.Trivandrum 3.Chennai 4.Ernakulam 5.Banglore " << endl;
            while (true) {
                cin >> city;
                if (cin.fail() || city < 1 || city > 5) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please enter a number between 1 and 5: ";
                } else {
                    break;
                }
            }
            switch (city)
            {
                case 1:
                    return 108; // Kochi
                case 2:
                    return 107; // Trivandrum
                case 3:
                    return 718; // Chennai
                case 4:
                    return 400; // Ernakulam
                case 5:
                    return 1024; // Banglore
                default:
                    return -1;
            }
        }

        virtual int valid() = 0;

        int toll()
        {

            toll_fee = axle * 2 * toll_distance; // Base calculation

            // Weight surcharge for heavy vehicles
            if (axle >= 3)
            {
                toll_fee *= 1.1; // 10% surcharge for heavy vehicles
            }

            // Apply fuel type discounts
            if (fuel == "Electric" || fuel == "CNG")
                toll_fee *= 0.9; // 10% discount
            else if (fuel == "Petrol")
                toll_fee *= 0.95; // 5% discount

            // State registration discount
            if (registration.state == "KL")
                toll_fee *= 0.9; // 10% discount

            // Payment mode discount
            if (payment == "Digital")
                toll_fee *= 0.9; // 10% discount

            // Public transport exemption
            if (public_transport)
                toll_fee = 0; // Exempt from toll

            // Manufacture year surcharge
            if (manufacture_date.year > 2014)
                toll_fee *= 1.5; // 50% surcharge

            // Toll type adjustments
            if (toll_type == "Round")
                toll_fee *= 1.8; 
            // 80% additional for round trip
            else if (toll_type == "Day Pass")
                toll_fee *= 1.2; 
            // 20% additional for day pass


            
            return toll_fee;
        }
};

class Single_Axle : public Vehicle
{
public:
        /* 
        axle=1;
        weight= 100kg -1000kg
        engine capacity- 100cc to 1000cc;
        */
        Single_Axle() : Vehicle() // Default constructor
        {
            axle = 1;
        }
        
        void input()
        {
        	inputvehicledetails();
        }

        int valid() override
        {
            if ((weight > 100 && weight < 1000) && (engine_capacity > 100 && engine_capacity < 1000))
            {
                return 1;
            }
            else
                return 0;
        }
};

class Double_Axle : public Vehicle
{
public:
        /*
        axle=2;
        weight= 1000kg - 5000kg;
        engine capacity- 1000cc to 5000cc
        */

        Double_Axle() : Vehicle() // Default constructor
        {
            axle = 2;
        }
        
        void input()
        {
        	inputvehicledetails();
        }

        int valid() override
        {
            if ((weight > 1000 && weight < 5000) && (engine_capacity > 1000 && engine_capacity < 5000))
            {
                return 1;
            }
            else
                return 0;
        }
};

class Triple_Axle : public Vehicle
{
private:
	int goods_weight;
public:
        /*
        axle =3;
        weight= 5000kg - 8000kg
        engine capacity-  5000cc - 8000cc
        goods_weight - max 10000kg
        */
        
        Triple_Axle() : Vehicle() // Default constructor
        {
            axle = 3;
        }
        
        void input()
        {
        	inputvehicledetails();
        	cout << "Weight of Goods? " << endl;
            	cin >> goods_weight;
        }

        int valid() override
        {
            if ((weight > 5000 && weight < 8000) && (engine_capacity > 5000 && engine_capacity < 8000) && (goods_weight <= 10000))
            {
                return 1;
            }
            else
                return 0;
        }
};

class Quadruple_Axle : public Vehicle
{
private:
	int goods_weight;
public:
        /*
        axle=4;
        weight= 8000kg to 10000kg
        engine capacity=8000cc+
        goods_weight - 10000kg to 20000kg
        */
        
        Quadruple_Axle() : Vehicle() // Default constructor
        {
            axle = 4;  
        }

	void input()
        {
        	inputvehicledetails();
        	cout << "Weight of Goods? " << endl;
            	cin >> goods_weight;
        }

        int valid() override
        {
            if ((weight > 8000 && weight <= 10000) && (engine_capacity > 8000) && (goods_weight > 10000 && goods_weight <= 20000))
            {
                return 1;
            }
            else
                return 0;
        }
};




void load_blacklist(vector<string> &blacklist)
{
    ifstream blacklist_file("Blacklist.txt"); 
    if (!blacklist_file)
    {
        cerr << "Blacklist.txt could not be opened!\n";
        return;
    }
    string entry;
    while (getline(blacklist_file, entry))
    {
        blacklist.push_back(entry);
    }
    blacklist_file.close();
}

bool is_blacklisted(const vector<string> &blacklist, const string &plate)
{
    return find(blacklist.begin(), blacklist.end(), plate) != blacklist.end();
}

int main()
{
    std::ofstream outf{ "Sample.txt", std::ios::app };
    if (!outf)
    {
        std::cerr << "Sample.txt could not be opened for writing!\n";
        return 1;
    }

    vector<string> blacklist;
    load_blacklist(blacklist); //calls fn that opens and reads the blacklist file

    vector<Vehicle *> vehicles;
    int num_vehicles;
    cout << "Enter the number of vehicles: ";
    cin >> num_vehicles;

    for (int i = 0; i < num_vehicles; ++i)
    {
        cout << "Vehicle " << i + 1 << ":\n";
        cout << "Select type (1: Single Axle, 2: Double Axle, 3: Triple Axle, 4: Quadruple Axle): ";
        int type;
        cin >> type;

        Vehicle *vehicle = nullptr;
        switch (type)
        {
        case 1:
            vehicle = new Single_Axle();
            break;
        case 2:
            vehicle = new Double_Axle();
            break;
        case 3:
            vehicle = new Triple_Axle();
            break;
        case 4:
            vehicle = new Quadruple_Axle();
            break;
        default:
            cout << "Invalid\n";
            continue;
        }

        vehicle->inputvehicledetails();
        vehicles.push_back(vehicle);
    }

    cout << "Toll Details Printed Successfully.\n";

    for (const auto &vehicle : vehicles)
    {
        string plate = vehicle->getRegistrationState() + " " + to_string(vehicle->getRegistrationNumber());
        if (is_blacklisted(blacklist, plate))
        {
            outf << "Vehicle " << plate << " is Blacklisted.\n";
        }
        else if (vehicle->valid())
        {
            outf << "Vehicle " << plate << " is Eligible." << "The Toll Fee of Vehicle " << plate << " is: " << vehicle->toll() << endl;
        }
        else
        {
            outf << "Vehicle No " << plate << " Not Eligible" << endl;
        }
    }

    for (auto vehicle : vehicles)
    {
        delete vehicle;
    }

    return 0;
}
