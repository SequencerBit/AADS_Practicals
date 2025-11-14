#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class Sort{
    T* arr;
    int size;
    int cnt = 0;
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    void quicksort(int low, int high){
        if(low<high){
            int pivot = rand_partition(low, high);
            quicksort(low, pivot-1);
            quicksort(pivot+1,high);
        }
    }
    int rand_partition(int low, int high){
        int randomidx = low + rand() % (high - low + 1);
        swap(arr[high], arr[randomidx]);
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j<high ; j++){
            cnt++;
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    public:
    Sort(T* arr, int size):arr(arr),size(size){srand(time(0));}
    void quicksort(){
        quicksort(0,size-1);
    }
    void print(){
        cout<<endl<<"Sorted array is: ";
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<"No. of comparisons are: "<<cnt<<endl;
    }
};


int main() {

    int arr[] = {9, 4, 6, 2, 7, 1, 8, 10};
    int n = 8;

    Sort<int> s(arr, n);
    s.quicksort();
    s.print();

}