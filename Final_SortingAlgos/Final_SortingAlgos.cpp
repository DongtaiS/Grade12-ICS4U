#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

long long operations = 0;

void printArr(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> getNumsFromFile(string name)
{
    vector<int> result;
    ifstream file(name);
    int temp;
    while (file >> temp)
    {
        result.push_back(temp);
    }
    return result;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSortOp(vector<int>& arr)
{
    bool didSwap;
    operations += 2; //Declare didSwap, initialize i
    for (int i = 0; i < arr.size(); i++)
    {
        didSwap = false;
        operations += 3; //Set didSwap to false, compare i to arr.size(), initialize j
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            operations += 2; //Compare j to arr.size() - i - 1, compare arr[j] to arr[j+1] 
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); 
                didSwap = true;
                operations += 4; //Swap is 3 operations, setting didSwap = true is 1 more
            }
            operations++; //Increment j 
        }
        operations++; //Check if didSwap is false
        if (!didSwap)
        {
            break;
        }
        operations++; //Increment i
    }
}

void bubbleSort(vector<int>& arr)
{
    bool didSwap;
    for (int i = 0; i < arr.size(); i++)
    {
        didSwap = false;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
        {
            break;
        }
    }
}

void selectionSortOp(vector<int>& arr)
{
    operations++; //Initialize left
    for (int left = 0; left < arr.size() - 1; left++)
    {
        operations += 3; //Compare left to arr.size()-1, initialize minIndex to left, initialize j to left+1
        int minIndex = left;
        for (int j = left + 1; j < arr.size(); j++)
        {
            operations += 2; //Compare j to arr.size(), compare arr[j] to arr[minIndex]
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                operations++; //Set minIndex to j
            }
            operations++; //Increment j
        }
        swap(arr[left], arr[minIndex]);
        operations += 4; //Swap is 3 operations, increment left
    }
}

void selectionSort(vector<int>& arr)
{
    for (int left = 0; left < arr.size() - 1; left++)
    {
        int minIndex = left;
        for (int j = left + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[left], arr[minIndex]);
    }
}

void insertionSortOp(vector<int>& arr)
{
    operations++; //Initialize i
    for (int i = 1; i < arr.size(); i++)
    {
        operations += 2; //Compare i to arr.size(), initialize j
        for (int j = i; j > 0; j--)
        {
            operations += 2; //Compare j to 0, compare arr[j] to arr[j-1]
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                operations += 3; //Swap is 3 operations
            }
            else
            {
                break;
            }
            operations++; //Decrement j
        }
        operations++; //Increment i
    }
}

void insertionSort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

void mergeOp(vector<int>& arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);
    operations += 6;// Initialize leftSize and rightSize, declare leftArr and rightArr, initialize i and j to 0
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i + left];
        operations += 3; //Compare i to leftSize, leftArr[i] to arr[i + left], increment i 
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArr[j] = arr[j + mid + 1];
        operations += 3; //Compare j to rightSize, rightArr[j] to arr[j + mid + 1], increment j 
    }
    int lCount = 0;
    int rCount = 0;
    int current = left;
    operations += 3; // Initialize lCount, rCount, and current
    while (lCount < leftArr.size() && rCount < rightArr.size())
    {
        operations += 3; // Compare lCount to leftArr.size() and rCount to rightArr.sze(), and compare leftArr[lCount to rightArr[rCount]
        if (leftArr[lCount] <= rightArr[rCount])
        {
            arr[current] = leftArr[lCount];
            lCount++;
            operations += 2; //Set arr[current] to leftArr[lCount] and increment lCount
        }
        else
        {
            arr[current] = rightArr[rCount];
            rCount++;
            operations += 2; //Set arr[current] to rightArr[rCount] and increment rCount
        }
        current++;
        operations++; //Increment current
    }
    while (lCount < leftArr.size())
    {
        arr[current] = leftArr[lCount];
        lCount++;
        current++;
        operations += 4; // Compare lCount to leftArr.size(), set arr[current] to leftArr[lCount], increment lCount and current
    }
    while (rCount < rightArr.size())
    {
        arr[current] = rightArr[rCount];
        rCount++;
        current++;
        operations += 4; // Compare rCount to rightArr.size(), set arr[current] to rightArr[rCount], increment rCount and current
    }
}

void mergeSortOp(vector<int>& arr, int left, int right)
{
    operations++; //Compare left to right
    if (left < right)
    {
        operations++; //Initialize mid
        int mid = (left + right-1) / 2;
        mergeSortOp(arr, left, mid);
        mergeSortOp(arr, mid + 1, right);

        mergeOp(arr, left, mid, right);
    }
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i + left];
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArr[j] = arr[j + mid + 1];
    }
    int lCount = 0;
    int rCount = 0;
    int current = left;
    while (lCount < leftSize && rCount < rightSize)
    {
        if (leftArr[lCount] <= rightArr[rCount])
        {
            arr[current] = leftArr[lCount];
            lCount++;
        }
        else
        {
            arr[current] = rightArr[rCount];
            rCount++;
        }
        current++;
    }
    while (lCount < leftSize)
    {
        arr[current] = leftArr[lCount];
        lCount++;
        current++;
    }
    while (rCount < rightSize)
    {
        arr[current] = rightArr[rCount];
        rCount++;
        current++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right - 1) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        cout << "Merging: left = " << left << " mid = " << mid << " right = " << right << endl;
        merge(arr, left, mid, right);
        printArr(arr);
    }
}

int partitionOp(vector<int>& arr, int left, int right)
{
    int pivotIndex = (left + right) / 2;
    int pivot = arr[pivotIndex];
    int current = left;
    swap(arr[pivotIndex], arr[right]);

    operations += 7; //Initialize pivotIndex, pivot, and current. Swap is 3 operations, initialize i to left
    for (int i = left; i < right; i++)
    {
        operations += 2; //Compare i to right, compare arr[i] to pivot
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[current]);
            current++;
            operations += 4; //Swap is 3 operations, increment current
        }
        operations++; //Increment i
    }
    swap(arr[current], arr[right]);
    operations += 4; //Swap is 3 operations, return current
    return current;
}

void quickSortOp(vector<int>& arr, int left, int right)
{
    operations++; //Compare left to right
    if (left < right)
    {
        operations++; //Initialize pivotIndex
        int pivotIndex = partitionOp(arr, left, right);
        quickSortOp(arr, left, pivotIndex - 1);
        quickSortOp(arr, pivotIndex + 1, right);
    }
}

int partition(vector<int>& arr, int left, int right)
{
    int pivotIndex = (left + right) / 2;
    int pivot = arr[pivotIndex];
    int current = left;
    swap(arr[pivotIndex], arr[right]);
    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[current]);
            current++;
        }
    }
    swap(arr[current], arr[right]);
    return current;
}

void quickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

bool validate(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string file1 = "randomNumbers.txt";
    string file2 = "randomNumbers2.txt";
    string file3 = "randomNumbers3.txt";
    string file4 = "randomNumbers4.txt";
    vector<int> testArr = { 4, 2, 1, 3 };
    cout << "Starting array: " << endl;
    printArr(testArr);
    cout << endl;

    mergeSort(testArr, 0, testArr.size() - 1);

    for (int i = 0; i < 10; i++)
    {
        vector<int> arr = getNumsFromFile(file1);
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size()-1);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        cout << "Time in nanoseconds: " << duration.count() << endl;
        if (validate(arr))
        {
            cout << "Valid sort" << endl;
        }
        else
        {
            cout << "Invalid sort" << endl;
        }
        cout << "Operations: " << operations << endl;
        operations = 0;
    }
}