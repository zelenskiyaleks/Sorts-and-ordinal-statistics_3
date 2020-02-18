#include <iostream>
#include <vector>
using namespace std;


int Partition(vector<int>& a, int first, int last) {
	int size = last - first + 1;
	int median = first;
	if (size >= 3) {
		int numb_median = first + size / 2;
		if (((a[first] <= a[numb_median]) and (a[numb_median] <= a[last])) or ((a[last] <= a[numb_median]) and (a[numb_median] <= a[first]))) {
			median = numb_median;
		}
		else if (((a[numb_median] <= a[first]) and (a[first] <= a[last])) or ((a[last] <= a[first]) and (a[first] <= a[numb_median]))) {
			median = first;
		}
		else {
			median = last;
		}
	}

	swap(a[median], a[last]);
	int pivon = a[last];
	int i = 0;
	for (int j = 0; j < last - first; j++) {
		if (a[first + j] <= pivon) {
			if (i == j) {
				i++;
			}
			else {
				swap(a[first + i], a[first + j]);
				i++;
			}
		}
	}
	swap(a[first + i], a[last]);
	return (first + i);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int first = 0;
	int last = n - 1;
	int pivon = Partition(arr, first, last);
	while (pivon != k) {
		if (pivon < k) {
			first = pivon + 1;
			pivon = Partition(arr, first, last);
		}
		else {
			last = pivon - 1;
			pivon = Partition(arr, first, last);
		}
	}
	cout << arr[k] << endl;

}

