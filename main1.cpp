#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point
{
    double x;
    double y;
};

double distanceBetweenPoints(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

bool isRectangle(Point* points, int size)
{
    if (size != 4)
        return false;

    double d01 = distanceBetweenPoints(points[0], points[1]);
    double d12 = distanceBetweenPoints(points[1], points[2]);
    double d23 = distanceBetweenPoints(points[2], points[3]);
    double d30 = distanceBetweenPoints(points[3], points[0]);

    double d02 = distanceBetweenPoints(points[0], points[2]);
    double d13 = distanceBetweenPoints(points[1], points[3]);

    const double eps = 0.000001;

    if (d01 < eps || d12 < eps || d23 < eps || d30 < eps)
        return false;

    bool equalSides =
        fabs(d01 - d23) < eps &&
        fabs(d12 - d30) < eps;

    bool equalDiagonals =
        fabs(d02 - d13) < eps;

    double sideProduct =
        (points[1].x - points[0].x) *
        (points[2].x - points[1].x) +
        (points[1].y - points[0].y) *
        (points[2].y - points[1].y);

    bool rightAngle = fabs(sideProduct) < eps;

    return equalSides && equalDiagonals && rightAngle;
}

double calculateArea(Point* points, int size)
{
    if (!isRectangle(points, size))
        return -1;

    double sideA = distanceBetweenPoints(points[0], points[1]);
    double sideB = distanceBetweenPoints(points[1], points[2]);

    return sideA * sideB;
}

void printPoints(Point* points, int size)
{
    cout << "\n--- Tochky ---" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Tochka " << i + 1 << ": ("
             << points[i].x << ", "
             << points[i].y << ")" << endl;
    }
}

void inputPoints(Point* points, int size)
{
    cout << "\nVvedit koordinaty 4 vershyn:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Tochka " << i + 1 << endl;

        cout << "x: ";
        cin >> points[i].x;

        cout << "y: ";
        cin >> points[i].y;
    }
}

void generatePoints(Point* points, int size)
{
    double x;
    double y;
    double width;
    double height;

    cout << "\nVvedit koordynaty pochatkovoi tochky:" << endl;

    cout << "x: ";
    cin >> x;

    cout << "y: ";
    cin >> y;

    cout << "Vvedit shirynu pryamokutnyka: ";
    cin >> width;

    cout << "Vvedit vysotu pryamokutnyka: ";
    cin >> height;

    if (width <= 0 || height <= 0)
    {
        cout << "Nekorektni rozmiry." << endl;
        return;
    }

    points[0].x = x;
    points[0].y = y;

    points[1].x = x + width;
    points[1].y = y;

    points[2].x = x + width;
    points[2].y = y + height;

    points[3].x = x;
    points[3].y = y + height;
}

void generateRandomPoints(Point* points, int size)
{
    double x = rand() % 21 - 10;
    double y = rand() % 21 - 10;

    double width = rand() % 10 + 1;
    double height = rand() % 10 + 1;

    points[0].x = x;
    points[0].y = y;

    points[1].x = x + width;
    points[1].y = y;

    points[2].x = x + width;
    points[2].y = y + height;

    points[3].x = x;
    points[3].y = y + height;
}

void runManual()
{
    const int size = 4;

    Point* points = new Point[size];

    inputPoints(points, size);

    printPoints(points, size);

    if (!isRectangle(points, size))
    {
        cout << "\nVvedeni tochky ne utvoryuyut pryamokutnyk." << endl;
        delete[] points;
        return;
    }

    double area = calculateArea(points, size);

    cout << "\nPloshcha pryamokutnyka: " << area << endl;

    delete[] points;
}

void runGenerated()
{
    const int size = 4;

    Point* points = new Point[size];

    generateRandomPoints(points, size);

    printPoints(points, size);

    if (!isRectangle(points, size))
    {
        cout << "\nZgenerovani tochky ne utvoryuyut pryamokutnyk." << endl;
        delete[] points;
        return;
    }

    double area = calculateArea(points, size);

    cout << "\nPloshcha pryamokutnyka: " << area << endl;

    delete[] points;
}

void showMenu()
{
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Vvesty koordinaty v ruchnu" << endl;
    cout << "2. Zgeneruvaty koordinaty" << endl;
    cout << "0. Vykhid" << endl;
    cout << "==========================" << endl;
    cout << "Vash vybir: ";
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                runManual();
                break;

            case 2:
                runGenerated();
                break;

            case 0:
                cout << "\nPrograma zavershena." << endl;
                break;

            default:
                cout << "\nNekorektniy vybir." << endl;
        }

    } while (choice != 0);

    return 0;
}
