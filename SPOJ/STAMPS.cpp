#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	int N;
	cin >> N;
	for(int ct = 0;ct < N;ct++){
		int stamps, frnds;
		cin >> stamps >> frnds;
		vector<int> arr(frnds);
		for (int i = 0; i < frnds; i++)
			cin >> arr[i];
		sort(arr.rbegin(), arr.rend());
		int sum = 0;
		for (int i = 0; i < arr.size(); i++){
			sum += arr[i];
			if (sum >= stamps){
				cout << "Scenario #" << ct + 1 << ":" << endl << i + 1 << endl << endl;
				break;
			}
		}
		if (sum < stamps)
			cout << "Scenario #" << ct + 1 << ":" << endl << "impossible" << endl << endl;
	}
	return 0;
} 