#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

class SelectionSort
{
public:
  SelectionSort()
  {

  }

  ~SelectionSort()
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

  // swaps positions of two elements of an array
  void swap(double *a, double *b)
  {
      double temp = *a;
      *a = *b;
      *b = temp;
  }

  // sorts array using SelectionSort method
  void selectionSort(double array[], int size)
  {
    int minPos;
    for(int i = 0; i < size-1; i++)
    {
      minPos = i;
      for(int j = i + 1; j < size; j++)
      {
        if(array[j] < array[minPos])
        {
          minPos = j;
        }
      }
      swap(&array[i], &array[minPos]);
    }
  }

  // sorts array using SelectionSort method and is timed
  void timedSelectionSort(double array[], int size)
  {
    cout << endl;
    cout << "=--- SELCTION SORT ---=" << endl;
    cout << "Starting array" << endl;
    printarray(array, size);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    selectionSort(array, size);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Sorted array" << endl;
    printarray(array, size);

    cout << "Time Taken" << endl;
    cout << duration << " ms" << endl;

    cout << endl;
  }
};
