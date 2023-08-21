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
        vector<int> cnt(10, 0);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            cnt[aux]++;
        }
        vector<int> v(n), cnt2(10, 0);
        int ind;
        for(int i=0;i<2;i++){
            cout << "- 0\n";
            cout.flush();
            for(int i=1;i<=9;i++) cnt2[i] = 0;
            for(int i=0;i<n;i++){
                int aux;
                cin >> v[i];
                cnt2[v[i]]++;
            }
            bool ok = false;
            for(int i=1;i<=9;i++){
                if(cnt2[i] > cnt[i]){
                    ind = i;
                    ok = true;
                }
            }
            if(ok) break;
        }
        vector<int> rm;
        for(int i=0;i<n;i++){
            if(v[i] != ind) rm.push_back(i+1);
        }
        cout << "- " << rm.size() << " ";
        for(auto x : rm) cout << x << " ";
        cout << "\n";
        cout.flush();
        n -= rm.size();
        int ans;
        for(int i=0;i<2;i++){
            bool ok = false;
            for(int i=0;i<n;i++){
                int aux;
                cin >> aux; 
                if(aux != ind){
                    ans = i+1;
                    ok = true;
                } 
            }
            if(!ok){
                cout << "- 0\n";
                cout.flush();
            }else break;
        }
        cout << "! " << ans << "\n";
        cout.flush();
    }
}
