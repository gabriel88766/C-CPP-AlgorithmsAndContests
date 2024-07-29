#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int N = 1e6+500;   
int p[N], sz[N];
int vis[N];
void init(int n){
    for(int i=0;i<n;i++) {p[i] = i; sz[i] = 1;}
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
        int n, m;
        cin >> n >> m;
        vector<string> gr(n);
        for(int i=0;i<n;i++) cin >> gr[i];
        init(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gr[i][j] == '#'){
                    for(int k=0;k<4;k++){
                        int di = i + dx[k];
                        int dj = j + dy[k];
                        if(di >= 0 && di < n && dj >= 0 && dj < m){
                            if(gr[di][dj] == '#') unite(di*m+dj, i*m + j);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ivr(n*m);
        vector<vector<int>> ivc(n*m);
        vector<int> ar(n), ac(m);
        for(int i=0;i<n;i++){
            vector<int> cur;
            for(int j=0;j<m;j++){
                if(!vis[get(i*m+j)]){
                    cur.push_back(get(i*m+j));
                    vis[get(i*m+j)] = 1;
                }
                for(int k=0;k<4;k++){
                    int di = i + dx[k];
                    int dj = j + dy[k];
                    if(di >= 0 && di < n && dj >= 0 && dj < m){
                        if(!vis[get(di*m+dj)] && gr[di][dj] == '#'){
                            cur.push_back(get(di*m+dj));
                            vis[get(di*m+dj)] = 1;
                        }
                    }
                }
            }
            for(auto x : cur) {ivr[x].push_back(i); ar[i] += sz[x];}
            for(auto x : cur) vis[x] = 0;
        }
        for(int j=0;j<m;j++){
            vector<int> cur;
            for(int i=0;i<n;i++){
                if(!vis[get(i*m+j)]){
                    cur.push_back(get(i*m+j));
                    vis[get(i*m+j)] = 1;
                }
                for(int k=0;k<4;k++){
                    int di = i + dx[k];
                    int dj = j + dy[k];
                    if(di >= 0 && di < n && dj >= 0 && dj < m){
                        if(!vis[get(di*m+dj)] && gr[di][dj] == '#'){
                            cur.push_back(get(di*m+dj));
                            vis[get(di*m+dj)] = 1;
                        }
                    }
                }
            }
            for(auto x : cur) {ivc[x].push_back(j); ac[j] += sz[x];}
            for(auto x : cur) vis[x] = 0;
        }


        //begin H2
        int ans = 0;
        vector<vector<int>> arc(n, vector<int>(m));
        //how to calculate arc????
        for(int i=0;i<n*m;i++){
            if(i != get(i)) continue;
            for(auto x : ivr[i]){
                for(auto y : ivc[i]){
                    arc[x][y] += sz[i];
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, ar[i] + ac[j] - arc[i][j]);
            }
        }
        cout << ans << "\n";
    }
}
