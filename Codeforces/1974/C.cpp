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
        map<pair<int,int>, int> mp1, mp2, mp3;
        map<tuple<int,int,int>, int> mpt;
        ll ans = 0;
        for(int i=2;i<n;i++){
            int a = v[i-2], b = v[i-1], c = v[i];
            ans += mp1[{b,c}] + mp2[{a, c}] + mp3[{a,b}] - 3*mpt[{a, b, c}];
            mp1[{b, c}]++;
            mp2[{a, c}]++;
            mp3[{a, b}]++;
            mpt[{a, b, c}]++;
        }
        cout << ans << "\n";
    }
}
