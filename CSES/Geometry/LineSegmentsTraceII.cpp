#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
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

const int N = 1e5+3; //must be greater than cds
//if compression of coordinates
vector<ll> cds;
int get_pos(ll value){
    return lower_bound(cds.begin(), cds.end(), value) - cds.begin();
}
int n; //n must be cds.size()
Line st[4*N];
//max or min...
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
            //THEN NL IS BETTER BOTH IN L AND M, BUT IT IS NOT NECESSARILY BETTER AFTER M
            //HOW TO PROVE IT'S CORRECT?? still not sure
            add(nl, i, j, 2*p+1, m+1, r);
        }else{
            add(nl, i, j, 2*p, l, m);
        }
    }else{
        add(nl, i, j, 2*p+1, m+1, r);
        add(nl, i, j, 2*p, l, m);
    }
}


ll get(int pos, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(l == r) return st[p].get(cds[pos]);  
    else if(pos <= m) return max(st[p].get(cds[pos]), get(pos, 2*p, l, m)); //change to max
    else return max(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)); //change to max
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input

    int m, ttp;
    cin >> ttp >> m;
    cds.resize(m+1);
    iota(cds.begin(), cds.end(), 0);
    n = m+1;

    for(int i=0;i<ttp;i++) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll m = (y2-y1)/(x2-x1); //constraint x1 < x2
        //mx1 + b = y1
        add(Line(m, y1 - m*x1), x1, x2);
        // break;
    }
    for(int i=0;i<=m;i++){
        ll val = get(i);
        if(val < 0) val = -1; //yeah... this is a way to make this code work.
        cout << val << " ";
    }
    cout << "\n";
}