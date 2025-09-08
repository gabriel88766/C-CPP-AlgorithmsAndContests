#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(int l, int r, int k){
    if(l == r){
        cout << k << " ";
        return;
    }
    int m = (l + r)/2;
    if(k % 2){
        solve(l, m, k/2);
        solve(m+1, r, k/2 + 1);
    }else{
        solve(l, m, k/2);
        solve(m+1, r, k/2);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    if(k % (1 << n)){
        cout << "1\n";
        solve(0, (1 << n) - 1, k);
        cout << "\n";
    }else{
        cout << "0\n";
        for(int i=0;i<(1 << n);i++) cout << k/(1 << n) << " ";
        cout << "\n";
    }
}
