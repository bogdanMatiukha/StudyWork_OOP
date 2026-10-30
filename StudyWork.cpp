#include <iostream>

#include "Triad.h"

using namespace std;

Triad processTriad(Triad& value)
{
    value.increaseFirst();
    value.increaseSecond();
    value.increaseThird();

    return value;
}

int main()
{
    cout << "===== Triad =====" << endl;

    Triad triad(1, 2, 3);

    cout << "Initial triad: ";
    triad.print();

    triad.increaseFirst();
    triad.increaseSecond();
    triad.increaseThird();

    cout << "After increasing: ";
    triad.print();

    cout << "\n===== Time =====" << endl;

    Time time(12, 30, 58);

    cout << "Initial time: ";
    time.print();

    time.increaseThird();

    cout << "After increasing seconds by 1: ";
    time.print();

    time.increaseSeconds(125);

    cout << "After increasing seconds by 125: ";
    time.print();

    time.increaseMinutes(10);

    cout << "After increasing minutes by 10: ";
    time.print();

    cout << "\n===== Substitution principle =====" << endl;

    Time anotherTime(10, 59, 59);

    Triad& baseReference = anotherTime;

    cout << "Before processing: ";
    baseReference.print();

    Triad result = processTriad(baseReference);

    cout << "After processing: ";
    baseReference.print();

    cout << "Returned base object: ";
    result.print();

    return 0;
}