//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

vector<vector<int>> resr;
vector<vector<int>> arrr(35);
bool use[30];
void ring(vector<int> t, int i, int n) {
	if ((int) t.size() == n - 1) {
		for (int r = 0; r < (int) arrr[i].size() && arrr[i][r] <= n; r++)
			if (arrr[i][r] == 1) {
				resr.push_back(t);
				return;
			}
		return;
	}
	for (int r = 0; r < (int) arrr[i].size() && arrr[i][r] <= n; r++) {
		if (use[arrr[i][r]])
			continue;
		use[arrr[i][r]] = true;
		t.push_back(arrr[i][r]);
		ring(t, arrr[i][r], n);
		use[arrr[i][r]] = false;
		if (!t.empty())
			t.pop_back();
	}
}

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 524 - Prime Ring Problem
	int n, i = 1;
	int ak[] =
			{ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 };
	for (int i = 1; i <= 30; i++)
		for (int k = 1; k < 30; k++)
			if (binary_search(ak, ak + 10, (i + k)))
				arrr[i].push_back(k);

	for (int i = 1; i <= 30; i++) {
		for (int k = 0; k < arrr[i].size(); k++) {
			for (int m = k + 1; m < arrr[i].size(); m++)
				if (arrr[i][m] == arrr[i][k])
					arrr[i].erase(arrr[i].begin() + m);
		}
	}
	for (int i = 1; i <= 30; i++)
		sort(all(arrr[i]));
	vector<int> v;
	int c = 0;
	while (cin >> n) {
		if (c++)
			cout << endl;
		v.clear();
		resr.clear();
		for (int i = 0; i < 30; i++)
			use[i] = false;
		use[1] = true;
		ring(v, 1, n);
		cout << "Case " << i++ << ":\n";
		for (int k = 0; k < resr.size(); k++) {
			cout << 1 << " ";
			for (int m = 0; m < resr[k].size(); m++) {
				cout << resr[k][m];
				if (m != resr[k].size() - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
