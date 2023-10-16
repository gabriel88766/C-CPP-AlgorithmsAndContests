#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
ll st[3][4*N];
int n = 500000;
int mid = 250000; //zero

ll query(int i, int j = n, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[i%3][p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int val, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[i%3][p] += val; return;}
    update(i, val, l, (l + r)/2, 2 * p);
    update(i, val, (l + r)/2 + 1, r, 2 * p + 1);
    for(int i=0;i<3;i++) st[i][p] = st[i][2 * p] + st[i][2 * p + 1]; //some operation
}

int tx(int x){
    return x + mid;
}




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> v(n+1, 0);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(s[i-1] == '-') v[i] = v[i-1] + 1;
            else v[i] = v[i-1] - 1;
            update(tx(v[i]), 1);
        }
        int cur = 0;
        for(int i=1;i<=n;i++){
            ans += query(tx(cur));
            update(tx(v[i]), -1);
            if(s[i-1] == '-') cur++;
            else cur--;
        }
        cout << ans << "\n";
    }
}