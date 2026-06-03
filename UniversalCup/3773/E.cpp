#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


// const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //uncomment

struct Line{
    ll a, b;
    Line() : a(0), b(0) {}
    Line(ll a, ll b){
        this->a = a; 
        this->b = b; 
    }
    ll get(ll x){
        return a*x + b;
    }
};

template<bool isMax>
struct LiChaoTree{
    // function<ll(ll, ll)> gmax = [](ll a, ll b){ return std::max(a, b);};
    // function<ll(ll, ll)> gmin = [](ll a, ll b){ return std::min(a, b);};
    // function<bool(ll, ll)> cpmin = [](ll a, ll b){ return a < b;};
    // function<bool(ll, ll)> cpmax = [](ll a, ll b){ return a > b;};
    // function<bool(ll, ll)> cpx;
    // function<ll(ll, ll)> gx;
    vector<ll> dom;
    vector<Line> st;
    int n;
    bool cpx(ll a, ll b){
        if constexpr(isMax){
            return a > b;
        }else{
            return a < b;
        }
    }
    ll gx(ll a, ll b){
        if constexpr(isMax){
            return std::max(a, b);
        }else{
            return std::min(a, b);
        }
    }
    LiChaoTree(vector<ll> domain){
        Line lx(0,0);
        if(isMax){
            // cpx = cpmax;
            // gx = gmax;
            lx = Line(0, -INF_LL);
        }else{
            // cpx = cpmin;
            // gx = gmin;
            lx = Line(0, INF_LL);
        }
        dom = domain;
        sort(dom.begin(), dom.end());
        dom.resize(unique(dom.begin(), dom.end()) - dom.begin());
        n = dom.size();
        st.assign(4 * n, lx);
    }
    void add(Line nl, int p, int l, int r){
        int m = (l + r)/2;
        bool lwl = cpx(nl.get(dom[l]), st[p].get(dom[l])); 
        bool lwm = cpx(nl.get(dom[m]), st[p].get(dom[m])); 
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
    void add(Line nl){
        add(nl, 1, 0, n-1);
    }
    ll get(int pos, int p, int l, int r){
        int m = (l + r)/2;
        if(l == r) return st[p].get(dom[pos]);  
        else if(pos <= m) return gx(st[p].get(dom[pos]), get(pos, 2*p, l, m)); 
        else return gx(st[p].get(dom[pos]), get(pos, 2*p+1, m+1, r));
    }
    ll get(int pos){
        return get(pos, 1, 0, n-1);
    }
    //RANGE UPDATES: O(log^2 n)
    void add(Line nl, int i, int j, int p, int l, int r){
        int m = (l + r)/2;
        if(i > r || j < l) return;
        if(i <= l && r <= j){
            bool lwl = cpx(nl.get(dom[l]), st[p].get(dom[l])); 
            bool lwm = cpx(nl.get(dom[m]), st[p].get(dom[m])); 
            if(lwm){
                swap(nl, st[p]); //nl is better
            }
            if(l == r) return;
            if(lwl == lwm){
                add(nl, i, j, 2*p+1, m+1, r);
            }else{
                add(nl, i, j, 2*p, l, m);
            }
        }else{
            add(nl, i, j, 2*p+1, m+1, r);
            add(nl, i, j, 2*p, l, m);
        }
    }
    void addrange(Line nl, int i, int j){
        add(nl, i, j, 1, 0, n-1);
    }
    Line getLine(int pos, int p, int l, int r){
        int m = (l + r)/2;
        if(l == r) return st[p];  
        else if(pos <= m){
            Line l1 = getLine(pos, 2*p, l, m);
            Line l2 = st[p];
            return cpx(l1.get(dom[pos]), l2.get(dom[pos])) ? l1 : l2;
        }else{
            Line l1 = getLine(pos, 2*p+1, m+1, r);
            Line l2 = st[p];
            return cpx(l1.get(dom[pos]), l2.get(dom[pos])) ? l1 : l2;
        }
    }
    Line getLine(int pos){
        return getLine(pos, 1, 0, n-1);
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m, q;
        cin >> m >> q;
        vector<ll> val(m+1);
        ll ansx = -INF_LL;
        for(int i=1;i<=m;i++){
            cin >> val[i];
            ansx = max(ansx, val[i]);
            val[i] += val[i-1];
        }
        vector<pair<int, int>> vxq;
        vector<ll> ans(q+1);
        vector<ll> cds;
        for(int i=1;i<=q;i++){
            int x;
            cin >> x;
            vxq.push_back({x, i});
            cds.push_back(x);
        }
        sort(vxq.begin(), vxq.end());
        sort(cds.begin(), cds.end());
        LiChaoTree<true> lmax(cds);
        LiChaoTree<false> lmin(cds);
        for(int i=m;i>=1;i--){
            lmax.add(Line(i, val[i]));
        }
        lmax.add(Line(0, 0));
        int x = 0, px = 0;
        for(int i=0;i<cds.size();i++){
            Line ln = lmax.getLine(i);
            cout << ln.a << " " << ln.b << " ";
            while(px < ln.a){
                lmin.add(Line(px, val[px]));
                px++;
            }
            ll cans;
            if(px == 0) cans = ansx + cds[i];
            else cans = lmax.get(i) - lmin.get(i);
            cout << cds[i] << " " << cans << "\n";
            while(x < vxq.size() && vxq[x].first == cds[i]){
                ans[vxq[x].second] = cans;
                x++;
            }
        }
        for(int i=1;i<=q;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
