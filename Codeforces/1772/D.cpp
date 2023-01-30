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
        int n, lo =0, hi = 1e9, clo, chi, maxint = 1e9;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
        for(int i=1;i<n;i++){
            clo = 0, chi = maxint;
            if(v[i-1] < v[i]){
                clo = 0;
                chi = v[i-1] + (v[i]-v[i-1])/2;
            }
            if(v[i-1] > v[i]){
                clo = v[i] + (v[i-1]-v[i])/2;
                if((v[i-1] - v[i]) & 1) clo++;
                chi = maxint;
            }
            lo = max(lo, clo);
            hi = min(hi, chi);
        }
        if(lo <= hi) cout << lo << "\n";
        else cout << "-1\n";
    }
}
