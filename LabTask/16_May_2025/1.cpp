#include <iostream>
using namespace std;

template <typename T>
void deleteElement(T arr[], int &size, T element)
{
    cout << "Original Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            break;
        }
    }

    if (i < size)
    {
        for (int j = i; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        size--;
    }

    cout << "Array After Deletion: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int elementToDelete = 5;

    deleteElement(arr, size, elementToDelete);

    return 0;
}
