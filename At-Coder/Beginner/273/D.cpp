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
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int n;
    cin >> n;
    map<int,set<int>> mr, mc;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        mr[a].insert(b);
        mc[b].insert(a);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int l;
        char d;
        cin >> d >> l;
        if(d == 'U'){//move r--
            if(mc.count(c)){
                auto it = mc[c].lower_bound(r);
                if(it != mc[c].begin()){
                    it = prev(it);
                    r = max(*it + 1, r - l);
                    l = 0;
                }
            }
            r = max(1, r - l);
        }else if(d == 'D'){
            if(mc.count(c)){
                auto it = mc[c].lower_bound(r);
                if(it != mc[c].end()){
                    r = min(*it - 1, r + l);
                    l = 0;
                }
            }
            r = min(h, r + l);
        }else if(d == 'L'){
            if(mr.count(r)){
                auto it = mr[r].lower_bound(c);
                if(it != mr[r].begin()){
                    it = prev(it);
                    c = max(*it + 1, c - l);
                    l = 0;
                }
            }
            c = max(1, c - l);
        }else{ // 'R'
            if(mr.count(r)){
                auto it = mr[r].lower_bound(c);
                if(it != mr[r].end()){
                    c = min(*it - 1, c + l);
                    l = 0;
                }
            }
            c = min(w, c + l);
        }
        cout << r << " " << c << "\n";
    }
}
