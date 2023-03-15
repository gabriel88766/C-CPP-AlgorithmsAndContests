#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

typedef pair<int,int> pii;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pii> vp;
    set<pii> sp;
    for(int i=0;i<8;i++){
        int x,y;
        cin >> x >> y;
        pii p = {x,y};
        vp.push_back(p);
        sp.insert(p);
    }
    bool ok = true;
    if(sp.size() != 4) ok = false;
    int h = 0, h1 = 0, h2 = 0;
    set<pii> px, py;
    for(int i=0;i<8;i+=2){
        int x = abs(vp[i].first - vp[i+1].first);
        int y = abs(vp[i].second - vp[i+1].second);
        if(!(x || y)) ok = false;
        if(x && y) ok = false;
        if(x){
            h++;
            px.insert(vp[i]);
            px.insert(vp[i+1]);
        }else{ //last submission was wrong, but passed. 197448132 test 0 0 1 0 0 1 1 1 0 0 0 1 0 0 0 1
            py.insert(vp[i]);
            py.insert(vp[i+1]);
        }
    }
    if(h != 2) ok = false;
    if(px.size() != 4 || py.size() != 4) ok = false;
    if(ok) cout << "YES";
    else cout << "NO";

}
