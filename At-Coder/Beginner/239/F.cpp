#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];
vector<int> need[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(need[a].size() < need[b].size()) swap(a,b);
    if(need[a].size() == 0 && sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    for(auto x : need[b]){
        need[a].push_back(x);
    }
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> d(n+1);
    ll sum = 0;
    for(int i=1;i<=n;i++){
        cin >> d[i];
        sum += d[i];
    }
    bool ok = true;
    if(sum != 2*(n-1)){
        ok = false;
    }
    init();    
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        unite(a, b); 
        d[a]--;
        d[b]--;
    }
    
    vector<int> cmps;
    for(int i=1;i<=n;i++) cmps.push_back(get(i));
    sort(cmps.begin(), cmps.end());
    cmps.resize(unique(cmps.begin(), cmps.end()) - cmps.begin());
    for(int i=1;i<=n;i++){
        if(d[i] < 0) ok = false;
        for(int j=0;j<d[i];j++){
            need[get(i)].push_back(i);
        }
    }
    for(auto x : cmps) if(need[x].size() == 0) ok = false;
    if(ok){
        priority_queue<pair<int,int>> pq;
        for(auto x : cmps){
            pq.push({need[x].size(), x});
        }
        while(!pq.empty()){
            assert(pq.size() >= 2);
            auto u = pq.top();
            pq.pop();
            auto v = pq.top();
            pq.pop();
            cout << need[u.second].back() << " " << need[v.second].back() << endl;
            need[u.second].pop_back();
            need[v.second].pop_back();
            unite(u.second, v.second);
            if(need[get(u.second)].size() >= 1){
                pq.push({need[get(u.second)].size(), get(u.second)});
            }
        }
    }else cout << "-1\n";
    


}
