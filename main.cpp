#include <iostream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

#include <fstream> //used for ifstream
#include <string> // used for stod()
#include <cstdint> // used for memcpy()
#include <cstring> // used for memcpy()

using namespace std;

main()
{
  int size;
  string userFile;

  // ask user for file name
  cout << "Enter the name of the file you would like to use...";
  cin >> userFile;

  // open file using name from user input
  ifstream inputFile;
  inputFile.open(userFile);

  // if user file does not exist
  if(!inputFile)
  {
    cout << "Unable to find file" << endl;
    exit(1);
  }

  // 1st line from userfile is size of array
  string s;
  getline(inputFile, s);
  size = stoi(s);
  double array[size];

  // read the rest of the userfile and add to array
  int counter = 0;
  while(getline(inputFile, s))
  {
    array[counter] = stod(s);
    counter++;
  }

  // run a timed BubbleSort
  double bubbleArray[size];
  memcpy(bubbleArray, array, sizeof(bubbleArray));
  BubbleSort bs;
  bs.timedBubbleSort(bubbleArray, size);

  // run a timed InsertionSort
  double insertionArray[size];
  memcpy(insertionArray, array, sizeof(insertionArray));
  InsertionSort is;
  is.timedInsertionSort(insertionArray, size);

  // run a timed QuickSort
  double quickArray[size];
  memcpy(quickArray, array, sizeof(quickArray));
  QuickSort qs;
  qs.timedQuickSort(quickArray, 0, size);

  // run a timed SelectionSort
  double selectionArray[size];
  memcpy(selectionArray, array, sizeof(selectionArray));
  SelectionSort ss;
  ss.timedSelectionSort(selectionArray, size);
}
