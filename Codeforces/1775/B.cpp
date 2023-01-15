#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;
const int N = 2e5+3;
int mp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> v(n);
        char ispos = false;
        for(int i=0;i<n;i++){
            int aux, aux2;
            cin >> aux;
            for(int j=0;j<aux;j++){
                cin >> aux2;
                v[i].push_back(aux2);
                mp[aux2]++;
            }
        }
        for(int i=0;i<n;i++){
            char isthis = true;
            for(int j=0;j<v[i].size();j++){
                mp[v[i][j]]--;
                if(!mp[v[i][j]]) isthis = false;
            }
            if(isthis){
                ispos = true;
                break;
            }
            for(int j=0;j<v[i].size();j++){
                mp[v[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++) mp[v[i][j]] = 0;
        } 

        if(ispos) cout << "Yes\n";
        else cout << "No\n";
    }
    
}
