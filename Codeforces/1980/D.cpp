#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bool tst(vector<int> &v, int j){
    int x = 0;
    for(int i=1;i<v.size();i++){
        if(i == j){
            if(i+1 < v.size()){
                if(gcd(v[i-1], v[i+1]) >= x) x = gcd(v[i-1], v[i+1]);
                else return false;
            }
        }else if(i == j+1) continue;
        else{
            if(gcd(v[i], v[i-1]) >= x) x = gcd(v[i], v[i-1]);
            else return false;
        }
    }
    return true;
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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int val = 0;
        int i1 = 0;
        for(int i=1;i<n;i++){
            if(gcd(v[i], v[i-1]) >= val){
                i1 = i;
                val = gcd(v[i], v[i-1]);
            }else break;
        }
        if(i1 == n+1) cout << "YES\n";
        else{
            bool ok = false;
            for(int i=max(i1-1, 0);i<=min(i1+1, n-1);i++){
                if(tst(v, i)) ok = true;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
 