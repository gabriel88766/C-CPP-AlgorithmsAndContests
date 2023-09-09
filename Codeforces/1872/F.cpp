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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1),  c(n+1), cp(n+1, 0);
        vector<bool> used(n+1, false);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            cp[a[i]]++;
        }
        for(int i=1;i<=n;i++) cin >> c[i];
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(cp[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            cout << u << " ";
            q.pop();
            used[u] = true;
            cp[a[u]]--;
            
            if(cp[a[u]] == 0) q.push(a[u]);
        }
        for(int i=1;i<=n;i++){
            if(!used[i]){
                vector<pair<int,int>> values;
                int cur = i;
                do{
                    used[cur] = true;
                    values.push_back({c[cur], cur});
                    cur = a[cur];
                }while(cur != i);
                sort(values.begin(), values.end());
                cur = a[values[0].second];
                while(cur != values[0].second){
                    cout << cur << " ";
                    cur = a[cur];
                }
                cout << values[0].second << " ";
            }
        }
        cout <<  "\n";
    }
}