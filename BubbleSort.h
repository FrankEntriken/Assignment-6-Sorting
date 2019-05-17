#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

class BubbleSort
{
public:
  BubbleSort()
  {

  }

  ~BubbleSort()
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

  // sorts array using BubbleSort method
  void bubbleSort(double array[], int size)
  {
    for(int i = 0; i < size - 1; i++)
    {
      for(int k = 0; k < size - i - 1; k++)
      {
        if(array[k] > array[k + 1])
        {
          swap(&array[k + 1], &array[k]);
        }
      }
    }
  }

  // sorts array using BubbleSort method and is timed
  void timedBubbleSort(double array[], int size)
  {
    cout << endl;
    cout << "=--- BUBBLE SORT ---=" << endl;
    cout << "Starting array" << endl;
    printarray(array, size);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bubbleSort(array, size);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Sorted array" << endl;
    printarray(array, size);

    cout << "Time Taken" << endl;
    cout << duration << " ms" << endl;

    cout << endl;
  }
};
