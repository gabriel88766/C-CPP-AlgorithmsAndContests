#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    long long int n,ans,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans=0;
        while(n){
            if(n%k){
                ans+=(n%k);
                n-=(n%k);
            }else {
                n/=k;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}