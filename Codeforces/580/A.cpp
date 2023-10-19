#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, ans = 1, cur = 1;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=1;i<n;i++){
        if(v[i] >= v[i-1]) cur++;
        else cur = 1;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}