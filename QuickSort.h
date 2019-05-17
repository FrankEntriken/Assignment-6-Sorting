#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

class QuickSort
{
public:
  QuickSort()
  {

  }

  ~QuickSort()
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

  // calculates pivot point used in QuickSort()
  double pivot(double array[], int left, int right)
  {
    return array[(left + right) / 2];
  }

  // sorts array using QuickSort method
  void quickSort(double array[], int left, int right)
  {
      int mLeft = left;
      int mRight = right;
      double temp;

      while (mLeft <= mRight)
      {
            while (array[mLeft] < pivot(array, left, right))
            {
              mLeft++;
            }

            while (array[mRight] > pivot(array, left, right))
            {
              mRight--;
            }

            if (mLeft <= mRight)
            {
                  temp = array[mLeft];
                  array[mLeft] = array[mRight];
                  array[mRight] = temp;
                  mLeft++;
                  mRight--;
            }
      }

      if(left < mRight)
      {
        quickSort(array, left, mRight);
      }
      if (mLeft < right)
      {
        quickSort(array, mLeft, right);
      }
    }

    // sorts array using QuickSort method and is timed
    void timedQuickSort(double array[], int left, int right)
    {
      cout << endl;
      cout << "=--- QUICK SORT ---=" << endl;
      cout << "Starting array" << endl;
      printarray(array, right);

      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      quickSort(array, left, right-1);
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>( t2 - t1 ).count();

      cout << "Sorted array" << endl;
      printarray(array, right);

      cout << "Time Taken" << endl;
      cout << duration << " ms" << endl;

      cout << endl;
    }
};
