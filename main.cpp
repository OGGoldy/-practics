#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void primitiveTypes()
{
    int* intValue = new int;
    double* doubleValue = new double;
    float* floatValue = new float;
    char* charValue = new char;
    bool* boolValue = new bool;
    short* shortValue = new short;
    long* longValue = new long;
    long long* longLongValue = new long long;

    cout << "\n--- Vvedennya primitvnykh typiv ---" << endl;

    cout << "Vvedit int: ";
    cin >> *intValue;

    cout << "Vvedit double: ";
    cin >> *doubleValue;

    cout << "Vvedit float: ";
    cin >> *floatValue;

    cout << "Vvedit char: ";
    cin >> *charValue;

    cout << "Vvedit bool (0 abo 1): ";
    cin >> *boolValue;

    cout << "Vvedit short: ";
    cin >> *shortValue;

    cout << "Vvedit long: ";
    cin >> *longValue;

    cout << "Vvedit long long: ";
    cin >> *longLongValue;

    cout << "\n--- Rezultat ---" << endl;
    cout << "int: " << *intValue << endl;
    cout << "double: " << *doubleValue << endl;
    cout << "float: " << *floatValue << endl;
    cout << "char: " << *charValue << endl;
    cout << "bool: " << *boolValue << endl;
    cout << "short: " << *shortValue << endl;
    cout << "long: " << *longValue << endl;
    cout << "long long: " << *longLongValue << endl;

    delete intValue;
    delete doubleValue;
    delete floatValue;
    delete charValue;
    delete boolValue;
    delete shortValue;
    delete longValue;
    delete longLongValue;
}

void doubleReference()
{
    double* pointer = new double;
    double& reference = *pointer;

    cout << "\n--- Posylannya na double ---" << endl;
    cout << "Vvedit znachennya: ";
    cin >> reference;

    cout << "Znachenya: " << reference << endl;

    delete pointer;
}

void reverseArray()
{
    int size;

    cout << "\n--- Dinamichniy masiv ---" << endl;
    cout << "Vvedit rozmir masivu: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Nekorektniy rozmir." << endl;
        return;
    }

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = size - 1 - i;
    }

    cout << "Masiv: ";

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    delete[] array;
}

void printThreeDimensionalArray(float*** array, int x, int y, int z)
{
    cout << "\n--- Trivimirniy masiv ---" << endl;

    for (int i = 0; i < x; i++)
    {
        cout << "Shari " << i + 1 << ":" << endl;

        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << array[i][j][k] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }
}

void threeDimensionalArray()
{
    int x;
    int y;
    int z;

    cout << "\n--- Trivimirniy masiv ---" << endl;

    cout << "Vvedit pershiy rozmir: ";
    cin >> x;

    cout << "Vvedit drugiy rozmir: ";
    cin >> y;

    cout << "Vvedit tretiy rozmir: ";
    cin >> z;

    if (x <= 0 || y <= 0 || z <= 0)
    {
        cout << "Nekorektni rozmiry." << endl;
        return;
    }

    float*** array = new float**[x];

    for (int i = 0; i < x; i++)
    {
        array[i] = new float*[y];

        for (int j = 0; j < y; j++)
        {
            array[i][j] = new float[z];

            for (int k = 0; k < z; k++)
            {
                array[i][j][k] =
                    static_cast<float>(rand()) / RAND_MAX * 100;
            }
        }
    }

    printThreeDimensionalArray(array, x, y, z);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] array[i][j];
        }

        delete[] array[i];
    }

    delete[] array;
}

void showMenu()
{
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Prymitivni typy danych" << endl;
    cout << "2. Posylannya na double" << endl;
    cout << "3. Dinamichniy masiv int" << endl;
    cout << "4. Trivimirniy masiv float" << endl;
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
                primitiveTypes();
                break;

            case 2:
                doubleReference();
                break;

            case 3:
                reverseArray();
                break;

            case 4:
                threeDimensionalArray();
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
