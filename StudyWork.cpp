#include <iostream>
#include "PhoneCall.h"

using namespace std;

int main()
{
    PhoneCall phoneCall;

    phoneCall.Init(5, 2.5);

    cout << phoneCall.ToString() << endl;

    phoneCall.Read();

    cout << "\n" << phoneCall.ToString() << endl;

    return 0;
}