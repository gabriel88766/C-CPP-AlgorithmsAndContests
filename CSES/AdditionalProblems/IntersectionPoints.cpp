#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+6;
const int SN = 1e6+1;

ll bit[N];
ll v[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    b += SN;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}

ll query(int a, int b){
    if(b < a) return 0;
    return query(b) - query(a-1);
}

void add(int b, ll value){ //add value to position b
    b += SN;
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
struct Modify{
    int n, pos, type;
    Modify(int n, int pos, int type){
        this->n = n, this->pos = pos, this->type = type;
    }
    bool operator< (Modify c){
        if(n != c.n) return n < c.n;
        else return make_pair(pos, type) < make_pair(c.pos, c.type);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int x1, y1, x2, y2;
    int m;
    int cntv = 0;
    n = N-1;
    cin >> m;
    vector<Modify> v;
    vector<pair<int,pair<int,int>>> check;
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            v.emplace_back(y1+1, x1, 1);
            v.emplace_back(y2, x1, -1);
        }else{
            check.push_back({y1, {x1+1, x2-1}});
        }
    }
    sort(v.begin(), v.end());
    sort(check.begin(), check.end());
    ll ans = 0;
    int bp = 0;
    for(int i=0;i<check.size();i++){
        while(bp < v.size() && v[bp].n <= check[i].first){
            add(v[bp].pos,v[bp].type);
            bp++;
        }
        ans += query(check[i].second.first, check[i].second.second);
    }
    cout << ans;
}   
