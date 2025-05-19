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
    bool operator< (const Line &c) const {
        return beg < c.beg;
    }
};

//Hint: above the curve: maximization; below the curve: minimization
struct ConvexHull{
    vector<Line> lines;
    void add(ll x, ll C){
        Frac beg = {0, 1};
        while(lines.size()){
            auto l = lines.back(); 
            if(l.x == x && l.C >= C) return; //above : l.C >= C, below C >= l.C
            else if(l.C <= C) lines.pop_back(); //above : l.C <= C below C <= l.C 
            else{
                //l.C - C > 0
                beg = { l.C - C, x - l.x}; //above: (l.C-C)/(x-l.x), below (C-l.C)/(l.x-x)
                if(beg < l.beg) lines.pop_back(); 
                else break;
            }
        }
        lines.push_back({beg, x, C});
    }
    ll get(ll val){
        Line cp = {{val, 1}, 0, 0};
        auto index = prev(upper_bound(lines.begin(), lines.end(), cp)) - lines.begin();
        return lines[index].x * val + lines[index].C;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v1, v2;
    for(int i=1;i<=n;i++){
        int y1, y2;
        cin >> y1 >> y2;
        v1.push_back({y1, (y2-y1)/m});
    }
    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    ConvexHull ch;
    for(auto &[a, b] : v1){
        ch.add(b, a);
    }
    for(int i=0;i<=m;i++){
        cout << ch.get(i) << " ";
    }
    cout << "\n";
}
