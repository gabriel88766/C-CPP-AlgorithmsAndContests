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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int> cnt(n+1);
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cnt[l]++;
        cnt[r+1]--;
    }
    for(int i=0;i<n;i++){
        if(i != 0) cnt[i] += cnt[i-1];
        if(cnt[i] % 2){
            swap(s[i], t[i]);
        }
    }
    cout << s << "\n";
}
