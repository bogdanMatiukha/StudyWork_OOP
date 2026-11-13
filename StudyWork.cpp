#include <iostream>
#include <iomanip>
#include "Triangled.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    cout << "===== Triangle by vertices =====" << endl;

    TriangleByVertices triangle1(
        0, 0,
        4, 0,
        0, 3
    );

    triangle1.printInfo();

    cout << "\n===== Triangle by sides =====" << endl;

    TriangleBySides triangle2(5, 5, 6);

    triangle2.printInfo();

    cout << "\n===== Triangle by medians =====" << endl;

    TriangleByMedians triangle3(5, 5, 6);

    triangle3.printInfo();

    cout << "\n===== Median calculation =====" << endl;

    cout << "Median to side A: "
        << triangle2.getMedian(1) << endl;

    cout << "Median to side B: "
        << triangle2.getMedian(2) << endl;

    cout << "Median to side C: "
        << triangle2.getMedian(3) << endl;

    cout << "\n===== Midline calculation =====" << endl;

    cout << "Midline parallel to side A: "
        << triangle2.getMidline(1) << endl;

    cout << "Midline parallel to side B: "
        << triangle2.getMidline(2) << endl;

    cout << "Midline parallel to side C: "
        << triangle2.getMidline(3) << endl;

    cout << "\n===== Right triangle =====" << endl;

    RightTriangle rightTriangle(3, 4);

    rightTriangle.printInfo();

    cout << "\n===== Polymorphism =====" << endl;

    Triangled* triangles[] =
    {
        &triangle1,
        &triangle2,
        &triangle3,
        &rightTriangle
    };

    for (int i = 0; i < 4; i++)
    {
        cout << "\nTriangle " << i + 1 << ":" << endl;
        triangles[i]->printInfo();
    }

    cout << "\n===== Program finished =====" << endl;

    return 0;
}
