#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<string, int>> v;
    int n;
    cin >> n;
    vector<pair<int,int>> aux;
    vector<int> ans(n, -1);

    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
        if(ans[v[i].second] == -1) ans[v[i].second] = i;
        else{
            aux.push_back({v[i].second, i});
        }
    }
    sort(aux.begin(), aux.end(), [&](pair<int,int> u, pair<int,int> v){
        return u.first < v.first;
    });

    int p = 0, p2 = 0;
    bool ok = true;
    stack<int> st;
    while(p < n){
        while(p < n && ans[p] != -1) p++;
        if(p == n) break;
        while(p2 < aux.size() && aux[p2].first <= p){
            st.push(aux[p2++].second);
        }
        if(!st.empty()){
            ans[p] = st.top();
            st.pop();
        }else{
            ok = false;
            break;
        }
    }


    if(ok){
        for(int i=0;i<n;i++){
            if(ans[i] >= n || ans[i] < 0){
                cout << ans[i];
                break;
            }
            cout << v[ans[i]].first << " " << n - v[ans[i]].second  << "\n";
        }
    }else cout << -1 << "\n";

}
