#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 362885; 

map<string, int> mp;
int d[N];
int adj[10][10];
int cnt = 0;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string goal = "123456789";
    int m;
    do{
        mp[goal] = ++cnt;
    }while(next_permutation(goal.begin(), goal.end()));
    memset(d, 63, sizeof(d));
    string src = "999999999";

    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i=1;i<=8;i++){
        int pos;
        cin >> pos;
        src[pos-1] = i+'0';
    }
    d[mp[src]] = 0;
    queue<string> q;
    q.push(src);

    while(!q.empty()){
        string u = q.front();
        q.pop();
        int ind;
        for(int i=0;i<9;i++) if(u[i] == '9') ind = i+1;
        string v = u;

        for(int i=1;i<=9;i++){
            if(i == ind) continue;
            if(adj[ind][i]){
                swap(v[i-1], v[ind-1]);
                if(d[mp[v]] > d[mp[u]] + 1){
                    q.push(v);
                    d[mp[v]] = d[mp[u]] + 1;
                }
                swap(v[ind-1], v[i-1]);
            }
        }
    }

    if(d[mp["123456789"]] != INF_INT) cout << d[mp["123456789"]];
    else cout << "-1";
}
