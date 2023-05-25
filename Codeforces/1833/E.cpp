#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
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
        vector<set<int>> v(n+1);
        init(n);
        for(int i=1;i<=n;i++){
            int j;
            cin >> j;
            unite(i, j);
            v[i].insert(j);
            v[j].insert(i);
        }
        int cnt = 0;
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            if(!mp.count(get(i))) mp[get(i)] = ++cnt;
        }
        int maxans = cnt;
        int minans = 0;
        vector<int> cntt(cnt+1, 0);
        for(int i=1;i<=n;i++){
            if(v[i].size() == 1) cntt[mp[get(i)]]++;
        }
        int t1 = 0, t2 = 0, t3 = 0;
        for(int i=1;i<=cnt;i++){
            if(cntt[i] == 0) t1++;
            else if(cntt[i] == 1) t2++;
            else t3++;
        }
        minans = t1;
        if(t2 || t3){
            minans++;
            t2 = max(0, t2-2);
        }
        minans += (t2+1)/2;
        cout << minans << " " << maxans << "\n";
    }
}
