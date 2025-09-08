#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<long double> cds;
int get_pos(long double value){
    return lower_bound(cds.begin(), cds.end(), value) - cds.begin();
}
int n; //n must be cds.size()
const int N = 2e5+3; 

//Using Li Chao Tree..

template<int type>
struct Line{//1 max, 0 min
    ll a, b;//make int128 if needed ax+b;
    Line(){
        this->a = 0; //inf to min, -inf to max 
        this->b = type ? -INF_LL : INF_LL; 
    }
    Line(ll a, ll b){
        this->a = a; 
        this->b = b; 
    }
    long double get(long double x){
        long double ans = x * a;
        ans += b;
        return ans;
    }
};

template<int type>
struct LiChaoTree{
    vector<Line<type>> st;
    LiChaoTree(){
        st.resize(4*N);
    }
    // (4*N);
    //max or min...
    void add(Line<type> nl, int p = 1, int l = 0, int r = n-1){
        int m = (l + r)/2;
        bool lwl = type ? nl.get(cds[l]) > st[p].get(cds[l]) : nl.get(cds[l]) < st[p].get(cds[l]); //change to > if max
        bool lwm = type ? nl.get(cds[m]) > st[p].get(cds[m]) : nl.get(cds[m]) < st[p].get(cds[m]); //change to > if max
        if(lwm){
            swap(nl, st[p]); //nl is better
        }
        if(l == r) return;
        if(lwl == lwm){
            add(nl, 2*p+1, m+1, r);
        }else{
            add(nl, 2*p, l, m);
        }
    }
    long double get(int pos, int p = 1, int l = 0, int r = n-1){
        int m = (l + r)/2;
        if(l == r) return st[p].get(cds[pos]);  
        else if(pos <= m) return type ? max(st[p].get(cds[pos]), get(pos, 2*p, l, m)) : min(st[p].get(cds[pos]), get(pos, 2*p, l, m)); //change to max
        else return type ? max(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)) : min(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)); //change to max
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    vector<tuple<int, int, int, int>> vq;
    vector<ll> ans(q+1, INF_LL);
    ll mxx = -INF_INT, mxy = -INF_INT, mnx = INF_INT, mny = INF_INT;
    for(int i=1;i<=q;i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        vq.push_back({a, b, c, d});
        mxx = max(mxx, a);
        mnx = min(mnx, a);
        mxy = max(mxy, b);
        mny = min(mny, b);
        if(c == 0 && d == 0) ans[i] = 0;
        else if(c == 0){
            if(d > 0) ans[i] = d * mxy;
            else ans[i] = d * mny;
        }else if(d == 0){
            if(c > 0) ans[i] = c * mxx;
            else ans[i] = c * mnx;
        }else{
            long double x = c;
            x /= d;
            cds.push_back(x);
        }
    }
    cds.push_back(-INF_INT);
    cds.push_back(INF_INT);
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    n = cds.size();

    LiChaoTree<1> lmax;
    LiChaoTree<0> lmin;

    for(int i=1;i<=q;i++){
        auto [x, y, a, b] = vq[i-1];
        lmax.add(Line<1>(x, y));
        lmin.add(Line<0>(x, y));
        if(a != 0 && b != 0){
            long double xx = a;
            xx /= b;
            long double val;
            if(b > 0){
                val = lmax.get(get_pos(xx));
            }else{
                val = lmin.get(get_pos(xx));
            }
            val *= b;
            if(val + EPS < 0) ans[i] = val - 0.5;
            else ans[i] = val + 0.5;
        }
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
