#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int cnt = 0;
set<int> sn[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<pair<int,int>> pos(n+1);
    map<pair<int,int>, int> mp;
    pos[0] = {0, 0};
    mp[pos[0]] = ++cnt;
    sn[cnt].insert(0);
    for(int i=1;i<=n;i++){
        pos[i] = pos[i-1];
        if(s[i-1] == 'L') pos[i].first--;
        if(s[i-1] == 'R') pos[i].first++;
        if(s[i-1] == 'U') pos[i].second++;
        if(s[i-1] == 'D') pos[i].second--;
        if(!mp.count(pos[i])){
            mp[pos[i]] = ++cnt;
        }
        sn[mp[pos[i]]].insert(i);
    }
    for(int i=0;i<q;i++){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if(mp.count(make_pair(x, y))){
            int pos = mp[{x, y}];
            if(*sn[pos].begin() < l){
                cout << "YES\n";
                continue;
            }
            auto it = sn[pos].lower_bound(r);
            if(it != sn[pos].end()){
                cout << "YES\n";
                continue;
            }
        }
        // inside l, r-1;
        auto p2 = pos[r];
        p2.first += pos[l-1].first - x;
        p2.second += pos[l-1].second - y;
        if(mp.count(p2)){
            auto it = sn[mp[p2]].lower_bound(l);
            if(it != sn[mp[p2]].end() && *it <= (r-1)){
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";

    }
}
