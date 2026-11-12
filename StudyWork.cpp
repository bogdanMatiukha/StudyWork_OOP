
#include <iostream>
#include "Figure.h"

using namespace std;

int main()
{
    cout << "===== Rectangle =====" << endl;

    Rectangle rectangle(10, 20, 100, 50);

    cout << "\nInitial information:" << endl;
    rectangle.printInfo();

    cout << "\n===== Show figure =====" << endl;
    rectangle.show();

    cout << "\n===== Move figure =====" << endl;
    rectangle.move(5, 10);
    rectangle.hide();
    rectangle.show();

    cout << "\n===== Rotate figure =====" << endl;
    rectangle.rotate(45);
    rectangle.hide();
    rectangle.show();

    cout << "\n===== Hide figure =====" << endl;
    rectangle.hide();

    rectangle.show();
    rectangle.rotate(45);
    rectangle.move(10, 5);
    rectangle.hide();

    return 0;
}
