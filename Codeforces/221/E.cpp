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
        this->a = INF_INT; //inf to min, -inf to max 
        this->b = INF_INT; 
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
void add(Line nl, int i, int j, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(i > r || j < l) return;
    if(i <= l && r <= j){
        bool lwl = nl.get(cds[l]) < st[p].get(cds[l]); //change to > if max
        bool lwm = nl.get(cds[m]) < st[p].get(cds[m]); //change to > if max
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

ll get(int pos, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(l == r) return st[p].get(cds[pos]);  
    else if(pos <= m) return min(st[p].get(cds[pos]), get(pos, 2*p, l, m)); //change to max
    else return min(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)); //change to max
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int j=0;j<n;j++) cds.push_back(j);
    vector<int> ord(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ord[x] = i;
    }
    vector<int> vx;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(i >= ord[x]){
            add(Line(-1, i - ord[x]), 0, i-ord[x]);
            add(Line(1, ord[x] - i), i-ord[x], i);
            if(i != n-1) add(Line(-1, n-1 - ord[x] + i + 1), i+1, n-1);
        }else{
            add(Line(1, ord[x] - i), 0, i);
            add(Line(-1, n-1 - ord[x] + i + 1), i+1, i + n - ord[x]);
            add(Line(1, -i - n + ord[x]), i + n - ord[x], n-1);
        }   
    }
    for(int i=0;i<n;i++){
        cout << get(i) << "\n";
    }
}
