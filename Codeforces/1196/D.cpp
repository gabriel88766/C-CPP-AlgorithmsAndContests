#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}};
//cout << fixed << setprecision(6)

int check(vector<vector<int>> &v, int k){
    int minv = 200005;
    
    for(int i=0;i<3;i++){
        int cur = 0;
        for(int j=0;j<3;j++){
            cur += v[j][(i+j)%3];
        }
        minv = min(minv, k-cur);
    }
    return minv;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<vector<int>> cnt(3, vector<int> (3, 0));
        for(int i=0;i<k;i++){
            cnt[i%3][mp[s[i]]]++;
        }
        int ans = check(cnt, k);
        for(int i=k;i<n;i++){
            cnt[i%3][mp[s[i]]]++;
            cnt[(i-k)%3][mp[s[i-k]]]--;
            ans = min(ans, check(cnt, k));
        }
        cout << ans << "\n";
    }
}
