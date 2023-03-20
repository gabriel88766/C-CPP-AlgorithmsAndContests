#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int m = t.size();
    int lo = 0, hi = n, mid;
    while(lo != hi){
        mid = (lo+hi+1)/2;
        bool ok = false;
        vector<bool> forb(n, false);
        for(int i=0;i<mid;i++) forb[v[i]-1] = true;;
        int bp = 0;
        for(int i=0;i<n;i++){
            if(forb[i]) continue;
            if(s[i] == t[bp]) bp++;
            if(bp == m){
                ok = true;
                break;
            }
        }
        if(!ok) hi = mid-1;
        else lo = mid;
    }
    cout << lo << "\n";
}

