//TODO
//WRONG WRONG WRONG!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b;
    bool operator< (const Frac &c) const{
        return a*c.b < b*c.a;
    }
};

struct Line{
    Frac beg;
    ll x, C;
    bool operator< (const Line &c) const { //below the curve ">" instead of "<"
        return x > c.x;
    }
};

struct ConvexHull{
    set<Line> lines;
    void add(ll x, ll C){
        Line l = {{0, 1}, x, C};
        if(lines.size()){
            vector<Line> eraselist;
            auto it = lines.lower_bound(l);
            if(it != lines.end() && it->x == l.x){
                if(it->C <= l.C) return;
                else{
                    lines.erase(*it);
                    it = lines.lower_bound(l);
                }
            }
            Line ins;
            while(it != lines.begin()){
                it = prev(it);
                if(it->C >= l.C){
                    eraselist.push_back(*it);
                    continue;
                }
                Frac beg = {l.C - it->C, it->x - l.x};
                if(it->beg < beg){
                    l.beg = beg;
                    break;
                }else{
                    eraselist.push_back(*it);
                }
            }
            it = lines.lower_bound(l);
            while(it != lines.end()){
                ins = *it;
                eraselist.push_back(*it);
                ins.beg = {(it->C - l.C), (l.x - it->x)};
                if(next(it) == lines.end() || it->beg < next(it)->beg) break;
            }
            for(auto x : eraselist) lines.erase(x);
            lines.insert(ins);
            /* old logic
            auto l = lines.back();
            if(l.x < x) return;
            if(l.x == x && C >= l.C) return; //above : l.C >= C, below C >= l.C
            else if(C <= l.C) lines.pop_back(); //above : l.C <= C [...]
            else{
                //l.C - C > 0
                beg = { C - l.C, l.x-x}; //above: (l.C-C)/(x-l.x), below (C-l.C)/(l.x-x)
                if(beg < l.beg) lines.pop_back(); 
                else break;
            }*/
        }
        lines.insert(l);
    }
    ll get(ll val){
        auto it = lines.begin();
        Frac f = {val, 1};
        while(next(it) != lines.end() && !(f < next(it)->beg)) ++it;
        return it->x * val + it->C;
    }
};
struct Q{
    ll s, f, i;
};
const int N = 2e5+3;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ConvexHull c;
    int n, x;
    cin >> n >> x;
    c.add(x, 0);
    vector<Q> vq(n);
    for(int i=0;i<n;i++) cin >> vq[i].s;
    for(int i=0;i<n;i++){
        cin >> vq[i].f;
        vq[i].i = i;
    }
    for(auto x : c.lines) cout << x.x << " " << x.C << " " << x.beg.a <<"/" << x.beg.b << "\n";
    for(int i=0;i<n;i++){
        ll cur = vq[i].f;
        ll value = c.get(vq[i].s);
        if(vq[i].i == n-1){
             //cout << value;
             break;
        }else{
            c.add(cur, value);
        }
    }
    cout << "\n";
    for(auto x : c.lines) cout << x.x << " " << x.C << " " << x.beg.a <<"/" << x.beg.b << "\n";
}
