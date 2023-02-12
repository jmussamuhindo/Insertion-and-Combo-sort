#include <ctime>
#include<iostream>
#include <fstream>
#include <chrono>
using namespace std;
int insertionSort(int n,int array[]){
    int j;
    for(int i=1;i<n;i++){
        int temp=array[i];
        j=i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
    return 0;
}
// code for comb sort
// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort a[0 to n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped) {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}
void print(int* array, int size){
    for(int i=0; i<size; i++)
        cout<<array[i]<<" "<<endl;
}
int* generate(int size) {
    int *newArr = new int[size];
    for (int i = 0; i < size; i++)
        newArr[i] = rand() % 1000;
    return newArr;
}
int main() {
    srand((unsigned) time(0));
    cout << "Insertion" << endl;
    int *I = new int[5000];
    int *C = new int[5000];
    using namespace std::chrono;
    for (int i = 0; i <= 5001; i++) {
        auto start = steady_clock::now();
        int *arr = generate(i);
        insertionSort(i, arr);
        auto stop = steady_clock::now();
        I[i - 1] = duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Comb" << endl;
    for (int i = 0; i <= 5001; i++) {
        auto start = steady_clock::now();
        int *arr = generate(i);
        combSort(arr, i);
        auto stop = steady_clock::now();
        C[i - 1] = duration_cast<nanoseconds>(stop - start).count();
    }
    ofstream myfile;
    myfile.open("result");
    for (int i = 0; i <= 5000; i++)
        myfile << (i + 1) << "\t" << I[i] << "\t" << C[i] << "\t" << endl;
    myfile.close();
    return 0;
}