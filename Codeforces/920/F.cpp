#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
int d[N];

void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            d[j]++;
        }
    }
}

const int M = 3e5+6;
 
ll bit[M];
ll v[M];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
ll query(int a, int b){
    return query(b) - query(a-1);
}

void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
void build(){
    for(int i=1;i<=n;i++) add(i, v[i]);
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    int q;
    cin >> n >> q;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        s.insert(i);
    }
    build();
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            auto it = s.lower_bound(b);
            while(it != s.end()  && *it <= c){
                int ival = *it;
                int cur = v[ival];
                int nxt = d[cur];
                v[ival] = nxt;
                ++it;
                if(cur == nxt) s.erase(ival);
                else add(ival, nxt-cur);
            }
        }else{
            cout << query(b, c) << "\n";
        }
    }
}
