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
    cin >> n >> m;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    set<string> ss;
    map<string,int> mp;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        ss.insert(s);
        mp[s]++;
    }
    vector<int> qt;
    for(auto x : ss) qt.push_back(mp[x]);
    sort(qt.begin(), qt.end(), greater<int>());
    int sz = qt.size();
    int minv = 0, maxv = 0;
    for(int i=0;i<sz;i++){
        minv += qt[i]*(*(p.begin()+i));
        maxv += qt[i]*(*(p.rbegin()+i));
    }
    cout << minv << " " << maxv << "\n";
}
