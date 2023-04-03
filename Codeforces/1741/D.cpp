#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void swap(vector<int> &t, int p, int x){
    for(int i=p;i<x;i++) swap(t[i], t[x-p+i]);
}




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> t(n);
        int ans = 0;
        for(int i=0;i<n;i++) cin >> t[i];
        for(int i=n/2;i>=1; i>>=1){
            for(int j=0; j+i < n; j+= 2*i){
                if(t[j] > (j+i)) {swap(t, j, j+i); ans++;}
            }
        }
        bool ok = true;
        for(int i=0;i<n;i++) if(t[i] != (i+1)) ok = false;
        if(ok) cout << ans << "\n";
        else cout << "-1\n";
    }
}   
