#include <iostream>

using namespace std;

struct ArrayList
{
private:
    int** data;
    int size;
    int capacity;

    void resizeBuffer()
    {
        int newCapacity;

        if (capacity == 0)
            newCapacity = 1;
        else
            newCapacity = capacity * 2;

        int** newData = new int*[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayList()
    {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    ~ArrayList()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }

    void pushBack(int* array, int arraySize)
    {
        if (array == nullptr || arraySize <= 0)
        {
            cout << "Nekorektniy masiv." << endl;
            return;
        }

        if (size >= capacity)
            resizeBuffer();

        data[size] = new int[arraySize];

        for (int i = 0; i < arraySize; i++)
        {
            data[size][i] = array[i];
        }

        size++;
    }

    bool insert(int index, int* array, int arraySize)
    {
        if (index < 0 || index > size)
        {
            cout << "Nekorektniy indeks." << endl;
            return false;
        }

        if (array == nullptr || arraySize <= 0)
        {
            cout << "Nekorektniy masiv." << endl;
            return false;
        }

        if (size >= capacity)
            resizeBuffer();

        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = new int[arraySize];

        for (int i = 0; i < arraySize; i++)
        {
            data[index][i] = array[i];
        }

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

        delete[] data[index];

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;

        return true;
    }

    bool get(int index, int*& array) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Nekorektniy indeks." << endl;
            return false;
        }

        array = data[index];

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
            cout << "Pereklik masiviv porozhniy." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << "Masiv " << i << ": ";

            for (int j = 0; j < 5; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int* createArray(int& size)
{
    cout << "Vvedit rozmir masivu: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Nekorektniy rozmir." << endl;
        return nullptr;
    }

    int* array = new int[size];

    cout << "Vvedit elementy masivu:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    return array;
}

void showArray(int* array, int size)
{
    if (array == nullptr || size <= 0)
    {
        cout << "Masiv porozhniy." << endl;
        return;
    }

    cout << "Elementy: ";

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

void showMenu()
{
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Dodaty masiv v kinets" << endl;
    cout << "2. Dodaty masiv za indeksom" << endl;
    cout << "3. Vydalyty masiv za indeksom" << endl;
    cout << "4. Otrymaty masiv za indeksom" << endl;
    cout << "5. Otrymaty kilkist masyviv" << endl;
    cout << "6. Otrymaty kilkist elementiv v buferi" << endl;
    cout << "7. Pokazaty pereklik" << endl;
    cout << "0. Vykhid" << endl;
    cout << "==========================" << endl;
    cout << "Vash vybir: ";
}

int main()
{
    ArrayList list;
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int size;
                int* array = createArray(size);

                if (array != nullptr)
                {
                    list.pushBack(array, size);
                    delete[] array;
                    cout << "Masiv dodano." << endl;
                }

                break;
            }

            case 2:
            {
                int index;
                int size;

                cout << "Vvedit indeks: ";
                cin >> index;

                int* array = createArray(size);

                if (array != nullptr)
                {
                    if (list.insert(index, array, size))
                        cout << "Masiv dodano." << endl;

                    delete[] array;
                }

                break;
            }

            case 3:
            {
                int index;

                cout << "Vvedit indeks: ";
                cin >> index;

                if (list.remove(index))
                    cout << "Masiv vydaleno." << endl;

                break;
            }

            case 4:
            {
                int index;
                int* array;

                cout << "Vvedit indeks: ";
                cin >> index;

                if (list.get(index, array))
                {
                    cout << "Masiv otrymano." << endl;
                }

                break;
            }

            case 5:
            {
                cout << "Kilkist masyviv: "
                     << list.getSize() << endl;
                break;
            }

            case 6:
            {
                cout << "Kilkist elementiv v buferi: "
                     << list.getCapacity() << endl;
                break;
            }

            case 7:
            {
                list.print();
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
