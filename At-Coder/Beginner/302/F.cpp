#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll d[N];
set<int> has[N];
set<int> v[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(d, 63, sizeof(d));
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for(int i=0;i<n;i++){
        int qt;
        cin >> qt;
        for(int j=0;j<qt;j++){
            int aux;
            cin >> aux;
            v[i].insert(aux);
            has[aux].insert(i);
        }
    }
    d[1] = -1;
    q.push(1);
    for(auto x : has[1]){
        v[x].erase(1);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        queue<int> erl;
        for(auto x : has[u]){
            for(auto y: v[x]){
                if(!erl.empty()){ //remove after visit
                    for(auto k : has[erl.front()]){
                        v[k].erase(erl.front());
                    }
                    erl.pop();
                }
                if(d[y] > d[u] + 1){
                    d[y] = d[u] + 1;
                    q.push(y);
                    erl.push(y);
                }
            }
        }
        
    }
    if(n == 1) d[1] = 0;
    if(d[m] != INF_LL) cout << d[m] << "\n";
    else cout << "-1\n";
}
