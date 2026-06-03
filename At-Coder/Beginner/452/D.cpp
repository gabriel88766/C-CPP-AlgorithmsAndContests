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
    ll ans = 0;
    string s, t;
    cin >> s >> t;
    int n = t.size();
    vector<int> qnt(n+1, 0);
    t = " " + t;
    for(auto c : s){
        vector<int> nqnt(n+1, 0);
        qnt[0] += 1;
        for(int i=0;i<=n;i++){
            if(i == n) nqnt[i] += qnt[i];
            else if(c == t[i+1]) nqnt[i+1] += qnt[i];
            else nqnt[i] += qnt[i];
        }
        qnt = nqnt;
        ans += qnt[n];
    }
    ll rans = s.size();
    rans *= (s.size() + 1);
    rans /= 2;
    rans -= ans;
    cout << rans << "\n";
}
