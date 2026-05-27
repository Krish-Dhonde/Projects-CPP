#include <iostream>
#include <vector>
using namespace std;

/*
Example-
Input Array: [4, 5, 6, 7, 9, 22, 11]
Output: No! Array is not sorted.

Approach:
 [[prev, next], ...] => [4, [5, 6], ...] the inner window will check if the two
element are properly arranged i.e. prev <= next condition and slide to the end
of element with 1 place. if the condition is not met then array is not sorted
else it is sorted.
*/

void print(const string &msg) { cout << msg << "\n"; }

void ArrayIfSorted(const vector<int> &arr) {
  if (arr.size() < 2) {
    print("Yes! Your Array is already sorted.");
    return;
  }

  for (size_t i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      print("No! Array is not sorted");
      return;
    }
  }
  print("Yes! Your Array is already sorted.");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cout << "Enter the size of array: ";
  if (!(cin >> n) || n < 0) {
    cout << "Invalid size of array!\n";
    return 1;
  }

  vector<int> arr(static_cast<size_t>(n));

  cout << "Enter your array[elements...]: ";
  for (size_t k = 0; k < static_cast<size_t>(n); k++) {
    cin >> arr[k];
  }

  ArrayIfSorted(arr);
  return 0;
}