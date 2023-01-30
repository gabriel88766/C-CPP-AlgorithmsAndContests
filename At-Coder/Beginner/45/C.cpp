#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll myatoi(string s, int i, int j){
    ll ans = 0;
    for(int k=i; k <= j; k++){
        ans *= 10;
        ans += (s[k] - '0');
    }
    return ans;
}


ll sum(string s, int i, int j){ //all sums from i to j
    if(i == j) return (s[i]-'0');
    ll ans = myatoi(s, i, j);
    for(int k = i; k<j ; k++){
        ans += myatoi(s, i, k)*(1 << (j - k - 1)) + sum(s, k+1, j);
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    ll ans = sum(s, 0, s.size()-1);
    cout << ans;
}

