#include <bits/stdc++.h>
using namespace std;

int solve(int r, int n, int x){
    vector<int> ba;
    int num = 0;
    for(int i=0;i<=29;i++){
        if(x & (1 << i)) ba.push_back(i);
        else{
            if(n & (1 << i)) num ^= (1 << i);
        }
    }
    if(num > r) return 0;
    int lo = 0, hi = (1 << (ba.size())) - 1;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        int cur = num;
        for(int j=0;j<ba.size();j++){
            if(mid & (1 << j)) cur |= (1 << ba[j]);
        }
        if(cur <= r) lo = mid;
        else hi = mid - 1;
    }
    return lo + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        cout << solve(n-1, n, ~x) << "\n";
    }
}
