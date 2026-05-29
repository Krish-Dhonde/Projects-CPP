#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*
Example-
Input: [3, 55, 32, 12, 90, 89]
Output: 89

Approach:
- First find out the Largest element and store it in the 'largest' variable.
- Consider the second largest element as 0 or -1 initially.
- Now slide the pointer from the index[0] to index[n-1].
- While looping check every value of each index if secondLargest < arr[i] and
arr[i] != largest element then update the secondLargest's value at that pass.

  Example-
  Input: [3, 55, 32, 12, 90, 89]
  largest = 90, secondLargest = 0

  Pass 1 (i = 0) -> arr[0] = 3, 0 < 3 and 3 != 90 then secondLargest = 3

  Pass 2 (i = 1) -> arr[1] = 55, 3 < 55 and 55 != 90 then secondLargest = 55

  Pass 3 (i = 2) -> arr[2] = 32, 55 > 32 then secondLargest = 55, No change

  Pass 4 (i = 3) -> arr[3] = 12, 55 > 12 then secondLargest = 55, No change

  Pass 5 (i = 4) -> arr[4] = 90, 55 < 90 and 90 = largest then secondLargest =
55, No change

  Pass 6 (i = 5) -> arr[5] = 89, 55 < 89 and 89 != 90 then secondLargest = 89

*/

void print(string msg) { cout << msg; }

int largestElement(const vector<int> &arr) {
  int largest = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

void secondLargestElement(const vector<int> &arr) {

  if (arr.size() < 2) {
    print("Array must contain at least 2 elements!\n");
    return;
  }

  int largest = largestElement(arr);
  int secondLargest = INT_MIN;
  bool found = false;

  for (size_t i = 0; i < arr.size(); ++i) {
    if (secondLargest < arr[i] && largest != arr[i]) {
      secondLargest = arr[i];
      found = true;
    }
  }

  if (!found) {
    print("No second largest exists!\n");
    return;
  }

  print("Second Largest Elements is: " + to_string(secondLargest));
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  print("Enter size of your array: ");
  if (!(cin >> n)) {
    print("Invalid Input!");
    return -1;
  }

  vector<int> arr(n);

  print("Enter elements of your array: ");
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  secondLargestElement(arr);
}