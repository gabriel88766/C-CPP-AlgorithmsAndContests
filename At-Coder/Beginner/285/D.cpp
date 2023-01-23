#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+3;
int adj[N];
char visited[N];
char isok[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, cntnode = 1;
    char ispos = true;
    map<string,int> mp;
    vector<pair<int,int>> pairs;
    cin >> n;
    for(int i=0;i<n;i++){
        string a, b;
        cin >> a >> b;
        if(!mp[a]) mp[a] = cntnode++;
        if(!mp[b]) mp[b] = cntnode++;
        pairs.push_back({mp[a], mp[b]});
        adj[mp[a]] = mp[b];
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        int a = pairs[i].first, b = pairs[i].second;
        if(isok[a]) continue;
        if(adj[b]){
            while(adj[b]){
                visited[a] = true;
                st.push(a);
                if(visited[adj[b]]){
                    ispos = false;
                    break;
                }
                a = b;
                b = adj[a];
            }
            while(!st.empty()){
                int cur = st.top();
                st.pop();
                isok[cur] = true;
                visited[cur] = false;
            }    
        }
    }
    if(ispos) cout << "Yes";
    else cout << "No";
}
