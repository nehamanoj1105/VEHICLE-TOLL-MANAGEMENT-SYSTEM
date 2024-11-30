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
};


class Single_Axle
{
    /* 
    axle=1;
    weight= 100kg -1000kg
    engine capacity- 100cc to 1000cc;


    */
};

class Double_Axle
{

    /*
    axle=2;
    weight= 1000kg - 5000kg;
    engine capacity- 1000cc to 5000cc
    */

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
};
