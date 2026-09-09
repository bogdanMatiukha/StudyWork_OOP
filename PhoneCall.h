#pragma once
#include <string>
using namespace std;

struct PhoneCall
{
    int first;
    double second;

    void Init(int f, double s);
    void Read();
    void Display();
    double cost();
    string ToString();
};