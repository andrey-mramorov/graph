#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;

void InputArray(int *data, int n);
void MergeSort(int *data, int l, int r);
void Merge(int *data, int l, int m, int r);
void BubbleSort(int *data, int n);
void InsertionSort(int *data, int n);
void BinaryInsertionsSort(int *data, int n);
int Partition (int *data, int low, int high);
void QuickSort(int *data, int low, int high);
int BinarySearch(int *data, int x, int low, int high);
void PrintArray(int *data, int n);
void TimeCount(int *W, int n);
void ReturnAmounts(int *W, int n);
void Swap(int *a, int *b);

int *C;

int main()
{
    int n;
    C = new int[n];

    cout << "Input size of array: ";
    cin >> n;
    cout << endl;

    int *W = new int[n];

    InputArray(C, n);
    for(int i = 0; i < n; i++) W[i] = C[i];

    cout << "This is your random array:" << endl << endl;
    PrintArray(C, n);
    cout << endl;
    TimeCount(W, n);
    cout << endl << "This is sorted array:" << endl << endl;
    PrintArray(W, n);
    cout << endl;

    delete [] C;
    delete [] W;

    return 0;
}

void InputArray(int *data, int n)
{
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		data[i] = rand() % 10000000;
}

void PrintArray(int *data, int n)
{
	for(int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
}

void ReturnAmounts(int *W, int n)
{
    for(int i = 0; i < n; i++) W[i] = C[i];
}

void TimeCount(int *W, int n)
{
    clock_t start, finish;
    double duration;

    start = clock();
    BubbleSort(W, n);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Bubble-sort time is " <<  fixed << setprecision(20) << duration << " seconds" << endl;
    ReturnAmounts(W, n);

    start = clock();
    InsertionSort(W, n);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Insertion-sort time is " << fixed << setprecision(20) << duration << " seconds" << endl;
    ReturnAmounts(W, n);

    start = clock();
    MergeSort(W, 0, n - 1);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Merge-sort time is " << fixed << setprecision(20) << duration << " seconds" << endl;
    ReturnAmounts(W, n);

    start = clock();
    BinaryInsertionsSort(W, n);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Binary-Insertions-sort time is " << fixed << setprecision(20) << duration << " seconds" << endl;
    ReturnAmounts(W, n);

    start = clock();
    QuickSort(W, 0, n - 1);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Quick-sort time is " << fixed << setprecision(20) << duration << " seconds" << endl;
}

void Merge(int *data, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
}

void MergeSort(int *data, int l, int r)
{
    if (l < r)
    {
        int m = (l + r)/2;
        MergeSort(data, l, m);
        MergeSort(data, m + 1, r);
        Merge(data, l, m, r);
    }
}

void BubbleSort(int *data, int n)
{
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (data[j] > data[j + 1])
            {
                int t = data[j];
                data[j] = data[j + 1];
                data[j + 1] = t;
            }
}

void InsertionSort(int *data, int n)
{
    for (int i = 1; i < n; i++)
    {
        int t = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > t)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = t;
    }
}

int BinarySearch(int *data, int x, int low, int high)
{
    if (high <= low)
        return (x > data[low]) ? (low + 1): low;

    int mid = (low + high)/2;

    if(x == data[mid])
        return mid + 1;

    if(x > data[mid])
        return BinarySearch(data, x, mid + 1, high);
    return BinarySearch(data, x, low, mid - 1);
}

void BinaryInsertionsSort(int *data, int n)
{
    int location, selected;

    for (int i = 1, j = 1; i < n; ++i)
    {
        j = i - 1;
        selected = data[i];

        location = BinarySearch(data, selected, 0, j);

        while (j >= location)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = selected;
    }
}

void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition (int *data, int low, int high)
{
    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            Swap(data + i, data + j);
        }
    }
    Swap(data + i + 1, data + high);

    return i + 1;
}

void QuickSort(int *data, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(data, low, high);
        QuickSort(data, low, pi - 1);
        QuickSort(data, pi + 1, high);
    }
}
