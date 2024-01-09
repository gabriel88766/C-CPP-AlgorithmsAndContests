#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int solve(string &s, char let, int l, int r){
    if(l == r){
        return s[l] == let ? 0 : 1;
    }else{
        int m = (l + r)/2;
        assert(m-l+1 == r-m);
        int opt1 = 0, opt2 = 0;
        for(int i=l;i<=m;i++) if(s[i] != let) opt1++;
        for(int i=m+1;i<=r;i++) if(s[i] != let) opt2++;
        return min(opt1 + solve(s, let+1, m+1, r), opt2 + solve(s, let+1, l, m));
    }
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
        string s;
        cin >> n >> s;
        cout << solve(s, 'a', 0, n-1) << "\n";
    }
}
