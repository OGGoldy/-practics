#include <iostream>

using namespace std;

struct Vector
{
private:
    int* data;
    int size;
    int capacity;

    void resizeBuffer()
    {
        int newCapacity;

        if (capacity == 0)
            newCapacity = 1;
        else
            newCapacity = capacity * 2;

        int* newData = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    Vector()
    {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    ~Vector()
    {
        delete[] data;
    }

    void pushBack(int value)
    {
        if (size >= capacity)
            resizeBuffer();

        data[size] = value;
        size++;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            cout << "Nekorektniy indeks." << endl;
            return false;
        }

        if (size >= capacity)
            resizeBuffer();

        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;

        return true;
    }

    bool remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Nekorektniy indeks." << endl;
            return false;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;

        return true;
    }

    bool get(int index, int& value) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Nekorektniy indeks." << endl;
            return false;
        }

        value = data[index];

        return true;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void print() const
    {
        if (size == 0)
        {
            cout << "Vektor porozhniy." << endl;
            return;
        }

        cout << "Vektor: ";

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

void showMenu()
{
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Dodaty element v kinets" << endl;
    cout << "2. Dodaty element za indeksom" << endl;
    cout << "3. Vydalyty element za indeksom" << endl;
    cout << "4. Otrymaty element za indeksom" << endl;
    cout << "5. Otrymaty kilkist elementiv" << endl;
    cout << "6. Otrymaty kilkist elementiv v buferi" << endl;
    cout << "7. Pokazaty vektor" << endl;
    cout << "0. Vykhid" << endl;
    cout << "==========================" << endl;
    cout << "Vash vybir: ";
}

int main()
{
    Vector vector;
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int value;

                cout << "Vvedit znachennya: ";
                cin >> value;

                vector.pushBack(value);

                cout << "Element dodano." << endl;
                break;
            }

            case 2:
            {
                int index;
                int value;

                cout << "Vvedit indeks: ";
                cin >> index;

                cout << "Vvedit znachennya: ";
                cin >> value;

                if (vector.insert(index, value))
                    cout << "Element dodano." << endl;

                break;
            }

            case 3:
            {
                int index;

                cout << "Vvedit indeks: ";
                cin >> index;

                if (vector.remove(index))
                    cout << "Element vydaleno." << endl;

                break;
            }

            case 4:
            {
                int index;
                int value;

                cout << "Vvedit indeks: ";
                cin >> index;

                if (vector.get(index, value))
                    cout << "Element: " << value << endl;

                break;
            }

            case 5:
            {
                cout << "Kilkist elementiv: "
                     << vector.getSize() << endl;
                break;
            }

            case 6:
            {
                cout << "Kilkist elementiv v buferi: "
                     << vector.getCapacity() << endl;
                break;
            }

            case 7:
            {
                vector.print();
                break;
            }

            case 0:
                cout << "\nPrograma zavershena." << endl;
                break;

            default:
                cout << "Nekorektniy vybir." << endl;
        }

    } while (choice != 0);

    return 0;
}
