// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


void mrg(int beg, int end, vector<int>& arr) {
	int mid = (beg + end) / 2;
	int lhs = beg;
	int rhs = mid + 1;
	vector<int> temp;

	//save temp array 
	while (lhs <= mid && rhs <= end) {
		if (arr[lhs] < arr[rhs]) {
			temp.push_back(arr[lhs++]);
		}
		else {
			temp.push_back(arr[rhs++]);
		}
	}
	while (lhs <= mid) temp.push_back(arr[lhs++]);
	while (rhs <= end) temp.push_back(arr[rhs++]);
	int j = beg;
	for (int i = 0; i < temp.size(); i++) {
		arr[j++] = temp[i];
	}

}

void mgsrt(int beg, int end, vector<int>& arr) {
	if (beg >= end) return;
	int mid = (beg + end) / 2;
	mgsrt(beg, mid, arr); //search upto mid
	mgsrt(mid+1, end, arr); //search from mid to end
	mrg(beg, end, arr);//sort them out in the end
}


int main()
{
	vector<int> arr = { 7,8,3,5,4,2,1 };
	int beg = 0, end = arr.size() - 1;
	mgsrt(beg, end, arr);
	for (auto x : arr) {
		cout << x << endl;
	}
}


