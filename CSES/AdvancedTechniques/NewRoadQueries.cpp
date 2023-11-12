#include <bits/stdc++.h>
#pragma GCC optimize("O2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;   
int ans[N];
vector<int> cmp[N];
vector<pair<int,int>> p[N];
 
void init(){
    for(int i=1;i<N;i++){
        p[i].push_back({i, 0});
        cmp[i].push_back(i);
    }
}
 
int get(int a){ 
    return p[a].back().first;
}
 
int cnt = 0;
void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(cmp[a].size() < cmp[b].size()) swap(a,b);
    for(auto x : cmp[b]){
        cmp[a].push_back(x);
        p[x].push_back({a, cnt});
    }
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin); //test input
    //freopen("out.txt", "w", stdout);
    init();
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cnt++;
        unite(a, b);
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        if(a == b){
            cout << "0\n";
            continue;
        }
        int p1 = p[a].size() - 1;
        int p2 = p[b].size() - 1;
        if(p[a][p1].first != p[b][p2].first) cout << "-1\n";
        else{
            while(p[a][p1].first == p[b][p2].first && p[a][p1].second == p[b][p2].second) p1--, p2--;
            cout << max(p[a][p1].second, p[b][p2].second) << "\n";
        }
    }
}