#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int cnt[N];
vector<int> b[N];
vector<int> c[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    stack<int> st;
    for(int i=1;i<=m;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            b[i].push_back(x);
            c[x].push_back(i);
        }
        int cur = b[i].back();
        cnt[cur]++;
        if(cnt[cur] == 2) st.push(cur);
    }
    int tt = 0;
    while(!st.empty()){
        auto u = st.top();
        st.pop();
        tt++;
        for(auto j : c[u]){
            b[j].pop_back();
            if(b[j].size()){
                cnt[b[j].back()]++;
                if(cnt[b[j].back()] == 2) st.push(b[j].back());
            }
        }
    }
    if(tt == n) cout << "Yes\n";
    else cout << "No\n";
}
