#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int res = 0, count = 0;
    while(count <= n){
        int sum = v[n-res-1];
        count++;
        while(sum <= d){
            count++;
            sum += v[n-res-1];
        }
        if(count > n) break;
        res++;
    }
    cout << res;
}