#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int N;
		cin >> N;
		vector<lld> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		if (N == 0)
			cout << "Case " << k << ": 0" << endl;
		else if (N == 1)
			cout << "Case " << k << ": " << arr[0] << endl;
		else if (N == 2)
			cout << "Case " << k << ": " << max(arr[0], arr[1]) << endl;
		else{
			vector<lld> dp(N);
			dp[0] = arr[0];
			dp[1] = max(arr[0],arr[1]);
			for (int i = 2; i < N; i++)
				dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
			cout << "Case " << k << ": " << dp[N - 1] << endl;
		}
	}
} 