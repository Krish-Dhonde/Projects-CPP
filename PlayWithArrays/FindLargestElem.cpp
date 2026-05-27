#include <iostream>
#include <vector>
using namespace std;

/*
Example-
Input: [1, 2, 4, 5, 21, 3, 79, 6]
Output: 6

Approach:
- First consider the starting value is the largest and save it seperately in
'max' variable.
- Slide the pointer over the array and compare the elements with the max
variable.
- Check the condition if the elem > max then overwrite 'max' variable.
- after the loop end your 'max' variable will be storing the largest element.

Example:
Input: [1, 2, 4, 5, 21, 3, 79, 6]
max = 1
pointer = 2 => 2 > 1 => max = 2
pointer = 4 => 4 > 2 => max = 4
pointer = 5 => 5 > 4 => max = 5
pointer = 21 => 21 > 5 => max = 21
pointer = 3 => 3 > 21 => No change
pointer = 79 => 79 > 21 => max = 79
pointer = 6 => 6 > 79 => No change
Output: 79
*/

void print(const string &msg) { cout << msg << endl; }

void largestElement(const vector<int> &arr) {
  if (arr.size() == 0) {
    print("Your Array is empty!");
    return;
  }

  int largest = arr[0];

  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  print("Largest Element:" + to_string(largest));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cout << "Enter the size of array: ";
  if (!(cin >> n) || n < 0) {
    print("Invalid Array!");
    return 1;
  }

  vector<int> arr(static_cast<size_t>(n));

  cout << "Enter your array elements: ";
  for (size_t k = 0; k < static_cast<size_t>(n); ++k) {
    cin >> arr[k];
  }

  largestElement(arr);
  return 0;
}