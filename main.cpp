#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

class Vehicle
{
    public:
        float weight;
        int axle;
        int prev_toll_distance;
        string fuel;
        int manufacture_date;
        string registation; //state of registration
        string toll_type; //one way trip/two way trip/oneday pass/monthly pass
        int engine_capacity;
        bool public_transport;
        string payment;//cash or fasttag
        float toll_fee;


        Vehicle()
        {
            cout << "Enter Weight of the Vehicle: " << endl;
            cin >> weight;
            
            cout << "Enter Distance from previous Toll: " << endl;
            cin >> prev_toll_distance;

            cout << "Enter Fuel type: " << endl;
            cin >> fuel;

            cout << "Enter Date of Manufacture: " << endl;
            cin >> manufacture_date;

            cout << "Enter Place of Registration: " << endl;
            cin >> registation;

            cout << "Enter Toll Type: " << endl;
            cin >> toll_type;

            cout << "Enter Engine Capacity: " << endl;
            cin >> engine_capacity;

            cout << "Public_transport Transport Vehicle? (1 for true/ 0 for false)" << endl;
            cin >> public_transport;

            cout << "Enter Payment Type? (Cash/Fastag)" << endl;
            cin >> payment;
        }

        Vehicle(float weight, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public_transport,string payment)
        {
            this -> weight = weight;
            this -> axle = 2;
            this -> prev_toll_distance = prev_toll_distance;
            this -> fuel = fuel;
            this -> manufacture_date = manufacture_date;
            this -> registation = registation; 
            this -> toll_type = toll_type;
            this -> engine_capacity = engine_capacity;
            this -> public_transport = public_transport;
            this -> payment = payment;
        }

        /*basically this function returns the value of prev toll distance based on user input (menu driven)*/
        int get_toll_distance(int x)
        {   

            if(x==1)
                return 108;//kochi
            else if(x==2)
                return 107;//trivandrum
            else if(x==3)
                return 718;//chennai
            else
                return 0;
        }

        void virtual valid(){}

        void virtual toll(){}
};

class Single_Axle: public Vehicle
{
    public:
        /* 
        axle=1;
        weight= 100kg -1000kg
        engine capacity- 100cc to 1000cc;
        */
        Single_Axle()
        {
            axle=1;
        }

        void valid()
        {
            if ((weight>100 && weight<1000) && (engine_capacity>100 && engine_capacity<1000))
            {
                cout << "You're Eligible for Single Axle Toll" << endl;
                toll();
            }
            else
                cout << "You're not Eligible" << endl;
        }

        void toll()
        {
            cout << "Your Toll is: " << public_transport <<endl;
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

        Double_Axle()
        {
            axle=2;
        }

        void valid()
        {
            if ((weight>1000 && weight<5000) && (engine_capacity>1000 && engine_capacity<5000))
            {
                cout << "You're Eligible for Double Axle Toll" << endl;
                toll();
            }
            else
                cout << "You're not Eligible" << endl;
        }

        void toll()
        {
            cout << "Your Toll is: " << public_transport << endl;
        }
};

class Triple_Axle:public Vehicle
{
    public:

        int goods_weight;
        /*
        axle =3;
        weight= 5000kg - 8000kg
        engine capacity-  5000cc - 8000cc
        goods_weight - max 10000kg
        */
        Triple_Axle()
        {
            axle=3;

            cout << "Weight of Goods? " << endl;
            cin >> goods_weight;
        }

        Triple_Axle(float weight, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public_transport,string payment,int goods_weight):
        Vehicle(weight, prev_toll_distance, fuel, manufacture_date, registation, toll_type, engine_capacity, public_transport,payment)
        {
            axle=3;
            this -> goods_weight = goods_weight;
        }

        void valid()
        {
            if ((weight>100 && weight<1000) && (engine_capacity>100 && engine_capacity<1000) && (goods_weight<10000))
            {
                cout << "You're Eligible for Single Axle Toll" << endl;
                toll();
            }
            else
                cout << "You're not Eligible" << endl;
        }

        void toll()
        {
            cout << "Your Toll is: " << public_transport <<endl;
        }
};

class Quadruple_Axle: public Vehicle
{
    public:
        int goods_weight;
        /*
        axle=4;
        weight= 8000kg to 10000kg
        engine capacity=8000cc+
        goods_weight - 10000kg to 20000kg
        */
        Quadruple_Axle()
        {
            axle=4;

            cout << "Weight of Goods? " << endl;
            cin >> goods_weight;        
        }

        Quadruple_Axle(float weight, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public_transport,string payment,int goods_weight):
        Vehicle(weight, prev_toll_distance, fuel, manufacture_date, registation, toll_type, engine_capacity, public_transport,payment)
        {
            axle=4;
            this -> goods_weight = goods_weight;
        }

        void valid()
        {
            if ((weight>100 && weight<1000) && (engine_capacity>100 && engine_capacity<1000) && (goods_weight>10000 && goods_weight<20000) )
            {
                cout << "You're Eligible for Single Axle Toll" << endl;
                toll();
            }
            else
                cout << "You're not Eligible" << endl;
        }

        void toll()
        {
            cout << "Your Toll is: " <<endl;
        }
};





int main()
{
    vector<Vehicle*> vehicles;
    int num_vehicles;
    cout << "Enter the number of vehicles: ";
    cin >> num_vehicles;

    for (int i = 0; i < num_vehicles; ++i)
    {
        cout << "Vehicle " << i + 1 << ":\n";
        cout << "Select type (1: Single Axle, 2: Double Axle, 3: Triple Axle, 4: Quadruple Axle): ";
        int type;
        cin >> type;

        Vehicle* vehicle = nullptr;
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

        cout<< "Toll Details:"
        for (const auto& vehicle : vehicles)
        {
            vehicle->toll();
        }

