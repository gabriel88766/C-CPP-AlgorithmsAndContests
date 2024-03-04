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
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int len = s.size();
            reverse(s.begin(), s.end());
            int p = 0;
            while(s[p] == '0') p++;
            vp.push_back({p, len});
        }
        int lentt = 0;
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            if(i % 2) lentt += vp[i].second;
            else lentt += vp[i].second - vp[i].first;
        }
        if(lentt > m) cout << "Sasha\n";
        else cout << "Anna\n";
    }
}
