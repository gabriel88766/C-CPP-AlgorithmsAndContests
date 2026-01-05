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
    // freopen("in", "r", stdin); //test input
    int k, n, m, q;
    string s;
    getline(cin, s);
    istringstream iss(s);
    iss >> k >> n >> m >> q;
    map<string, int> mp;
    vector<string> nm(n + m + 1);
    for(int i=1;i<=n;i++){
        string s;
        getline(cin, s);
        mp[s] = i;
        nm[i] = s;
    }
    vector<vector<pair<int, int>>> rec(m+1);
    for(int i=1;i<=m;i++){
        string s;
        getline(cin, s);
        istringstream iss(s);
        string cv;
        string name;
        int num;
        iss >> nm[n + i];
        nm[n+i].pop_back();
        while(iss >> cv >> num){
            char c;
            iss >> c;
            rec[i].push_back({mp[cv], num});
        }
    }
    vector<vector<int>> qt(k+1, vector<int>(n+m+1, 0));
    for(int i=1;i<=q;i++){
        int num;
        string s;
        cin >> num >> s;
        qt[num][mp[s]]++;
        for(int j=1;j<=m;j++){
            bool cok = true;
            for(auto [a, b] : rec[j]){
                if(qt[num][a] < b) cok = false;
            }
            if(cok){
                for(auto [a, b] : rec[j]){
                    qt[num][a] -= b;
                }
                qt[num][n+j]++;
            }
        }
    }
    for(int i=1;i<=k;i++){
        int tt = 0;
        vector<pair<string, int>> ans;
        for(int j=1;j<=n+m;j++){
            if(qt[i][j]){
                tt++;
                ans.push_back({nm[j], qt[i][j]});
            }
        }
        cout << tt << "\n";
        sort(ans.begin(), ans.end());
        for(auto [a, b] : ans){
            cout << a << " " << b << "\n";
        }
    }
}
