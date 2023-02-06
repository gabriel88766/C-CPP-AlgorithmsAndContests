#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, lg = 1e9+3, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }  
        if(n == 1){
            cout << "Yes\n";
            continue;
        }
    
        for(int i=0;i<(n-1);i++){
            if(v[i] > v[i+1]) lg = v[i];
            else if(v[i] < v[i+1] && v[i] < lg) {cnt++; lg = v[i+1];}
        }  
        if(v[n-1] < lg) cnt++;
        if(cnt == 1) cout << "Yes\n";
        else cout << "No\n";
    }
}
