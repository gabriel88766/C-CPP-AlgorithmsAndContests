#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1, M = 22;
vector<int> adj[N];
int ans[N], v[N];
int p[N][M];
int rt = 0;
int cnt = 0;

int ccur[N];
int ansc = 0;
void dfs(int u){
    if(u){
        if(!ccur[v[u]]) ansc++;
        ccur[v[u]]++;
    }
    ans[u] = ansc;
    for(auto v : adj[u]){
        dfs(v);
    }
    ccur[v[u]]--;
    if(!ccur[v[u]]) ansc--;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int cur = 0;
    vector<int> nq; //node of ith query
    int n;
    cin >> n;
    stack<int> st;
    st.push(0);
    for(int i=0;i<n;i++){
        char c;
        int k;
        cin >> c;
        if(c == '+'){
            cin >> k;
            adj[cur].push_back(++cnt);
            p[cnt][0] = cur;
            for(int j=1;j<M;j++){
                p[cnt][j] = p[p[cnt][j-1]][j-1];
            }
            cur = cnt;
            v[cur] = k;
            st.push(cur);
        }else if(c == '-'){
            cin >> k;
            for(int j=M-1;j>=0;j--){
                if(k & (1 << j)){
                    cur = p[cur][j];
                }
            }
            st.push(cur);
        }else if(c == '?'){
            nq.push_back(cur);
        }else{
            // rollback
            st.pop();
            cur = st.top();
        }
    }
    dfs(0);
    for(auto x : nq){
        cout << ans[x] << "\n";
    }
}
