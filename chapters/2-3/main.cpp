#include <iostream>

#include "array.hpp"

using namespace std;

int main() {
  IntArray myArray;

  cout << "myArray size: " << myArray.size() << endl;

  myArray[0] = 1;

  cout << "myArray 0th element: " << myArray[0] << endl;
}
