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
        vector<vector<int>> v(n);
        int msz = 0;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            msz = max(msz, k);
            v[i].resize(k);
            for(int j=0;j<k;j++) cin >> v[i][j]; 
        }
        vector<int> pos(n);
        set<int> aux;
        for(int i=0;i<n;i++) aux.insert(i);
        iota(pos.begin(), pos.end(), 0);
        for(int i=0;i<msz;i++){
            int lws = INF_INT;
            for(auto x : pos){
                lws = min(lws, v[x][i]);
            }
            cout << lws << " ";
            //check if any ending;
            bool end = false;
            for(auto x : pos){
                if(v[x][i] == lws && v[x].size() == (i+1)) end = true;
            }
            //resize aux;
            vector<int> rml;
            for(auto x : aux){
                if(v[x].size() == (i+1)) rml.push_back(x);
            }
            for(auto x : rml) aux.erase(x);
            //new pos.
            vector<int> npos;
            if(end){
                for(auto x : aux) npos.push_back(x);
            }else{  
                for(auto x : pos){
                    if(v[x][i] == lws) npos.push_back(x);
                }
            }
            pos = npos;
        }
        cout << "\n";
    }
}
