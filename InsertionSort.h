#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

class InsertionSort
{
public:
  InsertionSort()
  {

  }

  ~InsertionSort()
  {

  }

  // prints array in cout
  void printarray(double *array, int size)
  {
      int i = 0;
      while(i < size){
          cout << array[i] << " ";
          i++;
      }
      cout << "\n";
  }

  // sorts array using InsertionSort method
  void insertionSort(double array[], int size)
  {
    int temp;
    double num;
    for(int i = 1; i < size; i++)
    {
      num = array[i];
      temp = i - 1;
      while(array[temp] > num)
      {
        array[temp + 1] = array[temp];
        temp = temp - 1;
      }
      array[temp + 1] = num;
    }
  }

  // sorts array using InsertionSort method and is timed
  void timedInsertionSort(double array[], int size)
  {
    cout << endl;
    cout << "=--- INSERTION SORT ---=" << endl;
    cout << "Starting array" << endl;
    printarray(array, size);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertionSort(array, size);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Sorted array" << endl;
    printarray(array, size);

    cout << "Time Taken" << endl;
    cout << duration << " ms" << endl;

    cout << endl;
  }
};
