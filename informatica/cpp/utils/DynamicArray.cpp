#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class DynamicdArray
{

private:
    T *arr = (T *)malloc(sizeof(T) * 0);

public:
    DynamicdArray() = default;

    template <size_t N>
    DynamicdArray(T (&arr)[N])
    {
        for (int i = 0; i < N; i++)
        {
            append(arr[i]);
        }
    }

    ~DynamicdArray()
    {
        free(arr);
    }

    int length = 0;

    DynamicdArray &append(T val)
    {
        arr = (T *)realloc(arr, sizeof(T) * (length + 1));
        arr[length] = val;
        length++;

        return (*this);
    }

    bool hasValue(T value)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == value)
                return true;
        }

        return false;
    }

    void print()
    {
        cout << "[ ";
        for (int i = 0; i < length; i++)
        {
            if (i != 0)
            {
                cout << ", ";
            }
            cout << arr[i];
        }
        cout << " ]" << endl;
    }

    T *begin()
    {
        return arr;
    }

    T *end()
    {
        return arr + length;
    }

    T get(int i)
    {
        return arr[i];
    }

    friend ostream &operator<<(ostream &os, const DopedArray<T> &da)
    {
        os << "[ ";
        for (int i = 0; i < da.length; i++)
        {
            if (i != 0)
            {
                os << ", ";
            }
            os << da.arr[i];
        }
        os << " ]";

        return os;
    }
};

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    DynamicdArray<int> myArr(arr);

    for (int x : myArr)
    {
        cout << x << endl;
    }

    // myArr.append(22).append(10).append(200).append(3);

    // cout << boolalpha;

    // // cout << myArr.hasValue(22) << endl;
    // cout + myArr << endl;

    // for (int i = 0; i < myArr.length; i++)
    // {
    //     cout << myArr.get(i) << endl;
    // }
    return 0;
}