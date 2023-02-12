#include<bits/stdc++.h>

const double PI = acos(-1.);
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, minv = 1000001, maxv = -1000001;
    long long int sum = 0;
    cin >> n;
    while(n--){
        int cur;
        cin >> cur;
        sum += cur;
        minv = min(minv, cur);
        maxv = max(maxv, cur);
    }
    cout << minv << " " << maxv << " " << sum << "\n";
}