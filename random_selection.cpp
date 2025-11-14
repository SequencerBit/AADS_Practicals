#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class RandomSelect{
    T* arr;
    int size;
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    T select(int ithsmallest, int low, int high){
        if (low==high){
            return arr[low];
        }
        int pivot = rand_partition(low, high);

        if(ithsmallest==pivot){
            return arr[pivot];
        }
        else if(ithsmallest>pivot){
            return select(ithsmallest, pivot+1,high);
        }
        else{
            return select(ithsmallest, low, pivot-1);
        }

    }
    int rand_partition(int low, int high){
        int randomidx = low + rand() % (high - low + 1);
        swap(arr[high], arr[randomidx]);
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j<high ; j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    public:
    RandomSelect(T* arr, int size):arr(arr),size(size){srand(time(0));}
    T select(int ithsmallest){    
        if (ithsmallest<0||ithsmallest>size){
            throw out_of_range("Index is out of range");
        }
        return select(ithsmallest-1,0,size-1);
    }
};

int main() {
    int arr[] = {1,9,12,5,123,5,999};
    int n = sizeof(arr) / sizeof(arr[0]);

    RandomSelect<int> rs(arr, n);
    int k = 4; // looking for the 2nd smallest (index = 1)
    cout << "2nd smallest: " << rs.select(k) << endl;

    return 0;
}