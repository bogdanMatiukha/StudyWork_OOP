#include "Triad.h"

#include <iostream>

using namespace std;

Triad::Triad(int first, int second, int third)
{
    this->first = first;
    this->second = second;
    this->third = third;
}

void Triad::increaseFirst()
{
    first++;
}

void Triad::increaseSecond()
{
    second++;
}

void Triad::increaseThird()
{
    third++;
}

void Triad::print() const
{
    cout << first << ", " << second << ", " << third << endl;
}

Time::Time(int hours, int minutes, int seconds)
    : Triad(hours, minutes, seconds)
{
    first = ((hours % 24) + 24) % 24;
    second = ((minutes % 60) + 60) % 60;
    third = ((seconds % 60) + 60) % 60;
}

void Time::increaseFirst()
{
    first = (first + 1) % 24;
}

void Time::increaseSecond()
{
    second++;

    if (second >= 60)
    {
        second = 0;
        increaseFirst();
    }
}

void Time::increaseThird()
{
    third++;

    if (third >= 60)
    {
        third = 0;
        increaseSecond();
    }
}

void Time::increaseSeconds(int seconds)
{
    int totalSeconds = first * 3600 + second * 60 + third + seconds;

    totalSeconds = ((totalSeconds % 86400) + 86400) % 86400;

    first = totalSeconds / 3600;
    second = (totalSeconds % 3600) / 60;
    third = totalSeconds % 60;
}

void Time::increaseMinutes(int minutes)
{
    increaseSeconds(minutes * 60);
}

void Time::print() const
{
    cout << (first < 10 ? "0" : "") << first << ":"
        << (second < 10 ? "0" : "") << second << ":"
        << (third < 10 ? "0" : "") << third << endl;
}