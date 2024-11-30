#include <iostream>
using namespace std;

class Vehicle
{
    private:
        float weight;
        int axle;
        int prev_toll_distance;
        string fuel;
        int manufacture_date;
        string registation; //state of registration
        string toll_type;
        int engine_capacity;
        bool public;
        string payment;
        float toll_fee;
    public:
        Vehicle():
        {}

        virtual toll(){}

        virtual valid(){}

};

class Single_Axle: public Vehicle
{
    /* 
    axle=1;
    weight= 100kg -1000kg
    engine capacity- 100cc to 1000cc;
    */
    Single_Axle():{}

    Single_Axle(float weight, int axle, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public,string payment)
    {
        this -> weight = weight;
        this -> axle = axle;
        this -> prev_toll_distance = prev_toll_distance;
        this -> fuel = fuel;
        this -> manufacture_date = manufacture_date;
        this -> registation = registation; 
        this -> toll_type = toll_type;
        this -> engine_capacity = engine_capacity;
        bool -> public = public;
        string payment;
    }

    void print_details()
};

class Double_Axle
{

    /*
    axle=2;
    weight= 1000kg - 5000kg;
    engine capacity- 1000cc to 5000cc
    */

    Double_Axle():{}

    Double_Axle(float weight, int axle, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public,string payment)
    {
        this -> weight = weight;
        this -> axle = axle;
        this -> prev_toll_distance = prev_toll_distance;
        this -> fuel = fuel;
        this -> manufacture_date = manufacture_date;
        this -> registation = registation; 
        this -> toll_type = toll_type;
        this -> engine_capacity = engine_capacity;
        bool -> public = public;
        string payment;
    }


};

class Triple_Axle
{
    int goods_weight;
    /*
    axle =3;
    weight= 5000kg - 8000kg
    engine capacity-  5000cc - 8000cc
    goods_weight - max 10000kg
        */
    Triple_Axle():{}

    Triple_Axle(float weight, int axle, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public,string payment)
    {
        this -> weight = weight;
        this -> axle = axle;
        this -> prev_toll_distance = prev_toll_distance;
        this -> fuel = fuel;
        this -> manufacture_date = manufacture_date;
        this -> registation = registation; 
        this -> toll_type = toll_type;
        this -> engine_capacity = engine_capacity;
        bool -> public = public;
        string payment;
    }
};

class Quadruple_Axle
{
    int goods_weight;
    /*
    axle=4;
    weight= 8000kg to 10000kg
    engine capacity=8000cc+
    goods_weight - 10000kg to 20000kg
    
    */
    Quadruple_Axle():{}

    Quadruple_Axle(float weight, int axle, int prev_toll_distance, string fuel, int manufacture_date, string registation,string toll_type,int engine_capacity,bool public,string payment)
    {
        this -> weight = weight;
        this -> axle = axle;
        this -> prev_toll_distance = prev_toll_distance;
        this -> fuel = fuel;
        this -> manufacture_date = manufacture_date;
        this -> registation = registation; 
        this -> toll_type = toll_type;
        this -> engine_capacity = engine_capacity;
        bool -> public = public;
        string payment;
    }
};
