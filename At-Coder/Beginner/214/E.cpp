#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 18000000;
int st[M], lc[M], rc[M], cnt = 1; //216MB 
int MAX_INT = 1e9;

void update(int pos, int add, int l = 1, int r = MAX_INT, int p = 1){
    if(l == r){ st[p] += add; return;}
    int mid = (l+r)/2;
    if(pos > mid){
        if(!rc[p]) rc[p] = ++cnt; 
        update(pos, add, mid+1, r, rc[p]);
    }else{
        if(!lc[p]) lc[p] = ++cnt;
        update(pos, add, l, mid, lc[p]);
    }
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int a, int b, int l = 1, int r = MAX_INT, int p = 1){
    if(a > r || b < l) return 0;
    if(l == r) return l;
    int ans = 0;
    if(!lc[p]) lc[p] = ++cnt;
    if(st[lc[p]] < (l+r)/2-l+1) ans = query(a,b,l,(l+r)/2,lc[p]);
    if(ans) return ans;
    if(!rc[p]) rc[p] = ++cnt;
    if(st[rc[p]] < r-(l+r)/2) ans = query(a,b,(l+r)/2+1,r,rc[p]);
    return ans;
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
        cin >> n;
        vector<pair<int,int>> evts;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            evts.push_back({a,b});
        }
        sort(evts.begin(), evts.end(), [&](pair<int,int> u, pair<int,int> v){
            return u.second < v.second;
        });
        bool ok = true;
        for(int i=0;i<n;i++){
            int f = query(evts[i].first, evts[i].second);
            //cout << evts[i].first << " " << evts[i].second << " " << f << "\n";
            update(f, 1);
            if(f == 0) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
        for(int i=1;i<=cnt;i++){
            st[i] = rc[i] = lc[i] = 0;
        }
        cnt = 1;
    }
}
