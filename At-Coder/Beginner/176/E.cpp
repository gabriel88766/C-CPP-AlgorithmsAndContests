#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int ch[N], cw[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, m;
    cin >> h >> w >> m;
    map<pair<int, int>, bool> mp;
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        ch[x]++;
        cw[y]++;
        mp[{x, y}] = true;
    }
    vector<int> mh = {0};
    for(int i=1;i<=h;i++){
        if(ch[i] > ch[mh.back()]){
            mh.clear();
            mh.push_back(i);
        }else if(ch[i] == ch[mh.back()]){
            mh.push_back(i);
        }
    }
    vector<int> mw = {0};
    for(int i=1;i<=w;i++){
        if(cw[i] > cw[mw.back()]){
            mw.clear();
            mw.push_back(i);
        }else if(cw[i] == cw[mw.back()]){
            mw.push_back(i);
        }
    }
    bool ok = false;
    for(auto x : mh){
        for(auto y : mw){
            if(!mp.count({x, y})){
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout << ch[mh.back()] + cw[mw.back()] << "\n";
    else cout << ch[mh.back()] + cw[mw.back()]-1 << "\n";
}
