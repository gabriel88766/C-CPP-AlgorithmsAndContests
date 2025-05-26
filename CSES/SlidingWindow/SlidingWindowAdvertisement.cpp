//OVERKILL!!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Using Li Chao Tree..
struct Line{
    ll a, b;//make int128 if needed ax+b;
    Line(){
        this->a = -INF_INT; //inf to min, -inf to max 
        this->b = -INF_INT; 
    }
    Line(ll a, ll b){
        this->a = a; 
        this->b = b; 
    }
    ll get(ll x){
        return a*x + b;
    }
};

const int N = 4e5+3; //must be greater than cds
//if compression of coordinates
vector<ll> cds;
int get_pos(ll value){
    return lower_bound(cds.begin(), cds.end(), value) - cds.begin();
}
int n; //n must be cds.size()
Line st[4*N];
//max or min...
ll get(int pos, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(l == r) return st[p].get(cds[pos]);  
    else if(pos <= m) return max(st[p].get(cds[pos]), get(pos, 2*p, l, m)); //change to max
    else return max(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)); //change to max
}

//RANGE UPDATES: O(log^2 n)
void add(Line nl, int i, int j, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(i > r || j < l) return;
    if(i <= l && r <= j){
        bool lwl = nl.get(cds[l]) > st[p].get(cds[l]); //change to > if max
        bool lwm = nl.get(cds[m]) > st[p].get(cds[m]); //change to > if max
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, k;
    cin >> m >> k;
    n = m+1;
    cds.resize(n);
    iota(cds.begin(), cds.end(), 0);
    vector<pair<ll, ll>> v(n);
    for(int i=1;i<=m;i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    set<int> s;
    s.insert(0);
    s.insert(m+1);
    for(auto [val, j] : v){
        auto it = s.lower_bound(j);
        int l = *prev(it) + 1;
        int r = *it - 1;
        if(r - l + 1 >= k){
            //then reach to k and decrease after r
            // val * l + b =  val => b = val * (1 - l);
            add(Line(val, val * (1 - l)), l, l + k - 1);
            if(r - l + 1 != k) add(Line(0, val*k), l+k, r);
            add(Line(-val, val * (r + k)), r, m);
        }else{
            //increase till r, then decrease
            add(Line(val, val * (1 - l)), l, r);
            //(r-l+1) * val will be the another line... from r to ??
            int dif = k - (r - l + 1);
            assert(dif);
            if(dif){
                add(Line(0LL, (r-l+1)*val), r, min(r + dif, m));
                if(r + dif + 1 <= m) add(Line(-val, (2*r+dif-l+1)*val), r+dif+1, m);
            }
            // else add(Line(-val, val * (2*r-l+1)), r, m);
        }
        s.insert(j);
    }
    for(int i=k;i<=m;i++){
        cout << get(i) << " ";
    }
    cout << "\n";
}
