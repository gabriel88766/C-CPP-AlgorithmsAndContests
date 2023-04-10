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
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        int nxta = s1, nxtb = s2;
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            pq.push({aux, i});
        }
        vector<int> a;
        vector<int> b;
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            if(nxta <= nxtb){
                a.push_back(u.second);
                nxta += s1;
            }else{
                b.push_back(u.second);
                nxtb += s2;
            }
        }
        cout << a.size() << " ";
        for(auto x : a) cout << x << " ";
        cout << "\n";
        cout << b.size() << " ";
        for(auto x : b ) cout << x << " ";
        cout << "\n";
    }
}
