#include <cassert>

class IntArray {
public:
  // constructors
  explicit IntArray(int sz = DefaultArraySize) { init(sz, 0); };
  IntArray(int *array, int sz) { init(sz, array); };
  IntArray(const IntArray &rhs) { init(rhs.size(), rhs.ia); };

  // destructor
  ~IntArray() { delete[] ia; };

  // indexing operator
  int &operator[](int index);

  // equality and inequality operations - #2b:
  bool operator==(const IntArray &) const;
  bool operator!=(const IntArray &) const;

  // assignment operator - #2b:
  IntArray &operator=(const IntArray &);

  int size() const { return _size; } // #1
  void sort();                       // #4

  int min() const; // #3a
  int max() const; // #3b

  // if the value is found within the array,
  // return the index of its first ocurrence
  // otherwise, return -1
  int find(int value) const; // 3c

private:
  void init(int sz, int *array);

  static const int DefaultArraySize = 12;
  int _size;
  int *ia;
};

void IntArray::init(int sz, int *array) {
  _size = sz;
  ia = new int[_size];

  for (int i = 0; i < _size; i++) {
    if (!array) {
      ia[i] = 0;
    } else {
      ia[i] = array[i];
    }
  }
}

int &IntArray::operator[](int index) {
  assert(index >= 0 && index < _size);
  return ia[index];
}
