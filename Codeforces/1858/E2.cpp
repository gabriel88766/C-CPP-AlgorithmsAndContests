#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1, M = 22;
vector<int> adj[N];
int add[N];
int ans[N], h[N];
int p[N][M];
int cnt = 0;

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
            h[cnt] = h[cur] + 1;
            ans[cnt] = ans[cur];
            cur = cnt;
            st.push(cur);
            //check if some k added is ancestor of cur
            /*if(add[k]){
                int lk = add[k];
                if(h[lk] < h[cur]){
                    int diff = h[cur] - h[lk];
                    int aux = cur;
                    for(int j=M-1;j>=0;j--){
                        if(diff & (1 << j)) aux = p[aux][j];
                    }
                    if(aux != lk) ans[cur]++;
                }else ans[cur]++;
            }else ans[cur]++;
            if(!add[k]) add[k] = cur;
            else if(h[add[k]] >= h[cur]) add[k] = cur;*/
        }else if(c == '-'){
            cin >> k;
            for(int j=M-1;j>=0;j--){
                if(k & (1 << j)){
                    cur = p[cur][j];
                }
            }
            st.push(cur);
        }else if(c == '?'){
            cout << ans[cur] << "\n";
            cout.flush();
        }else{
            // rollback
            st.pop();
            cur = st.top();
        }
    }
}
