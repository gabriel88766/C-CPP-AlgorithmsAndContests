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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        if(n == 1 || n == 2) cout << "-1\n";
        else{
            ll avg = 2*v[(n-1)/2];
            ll sumvg = n;
            sumvg *= avg;
            sumvg += 1;
            ll sumc = 0;
            for(auto x : v) sumc += x;
            if(sumc <= sumvg) cout << sumvg - sumc << "\n";
            else cout << "0\n";
        }
    }
}
