#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<int, int> mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    int ans = -1;
    for(auto &[k, v] : mp){
        if(v == 1) ans = k;
    }
    if(ans == -1) cout << "-1\n";
    else{
        for(int i=0;i<n;i++){
            if(v[i] == ans) cout << i+1 << "\n";
        }
    }
}
