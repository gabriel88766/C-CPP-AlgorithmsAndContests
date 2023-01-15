#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 3e5+5;
int pr[N]; // 0 if prime, 1 if not prime
int p[N], d[N];
int visited[N];
vector<int> pf[N];
vector<int> pi[N];
void sieve(){
    for(ll i=2; i<=N; i++){
        if(!pr[i]){
            for(ll j = i; j < N; j += i){
                pr[j] = 1;
                pf[j].push_back(i);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, s, t;
    cin >> n;
    sieve();
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
    }
    cin >> s >> t;
    if(s == t) {
        cout << "1\n" << s << "\n";
        return 0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<pf[v[i]].size();j++){
            int prim = pf[v[i]][j];
            pi[prim].push_back(i);
        }
    }
    queue<int> q;
    q.push(s);
    for(int i=0;i<N;i++) d[i] = INF_INT;
    d[s] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<pf[v[cur]].size();i++){
            int prim = pf[v[cur]][i];
            if(!visited[prim]){
                visited[prim] = true;
                for(int j=0; j<pi[prim].size();j++){
                    int curp = pi[prim][j];
                    if(d[cur] + 1 < d[curp]){
                        q.push(curp);
                        p[curp] = cur;
                        d[curp] = d[cur] + 1;
                    }
                }
            }
        }
    }

    if(p[t]){
        int curn = t;
        vector<int> ans;
        ans.push_back(t);
        while(curn != s){
            curn = p[curn];
            ans.push_back(curn);
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    }else{
        cout << "-1";
    }
}
