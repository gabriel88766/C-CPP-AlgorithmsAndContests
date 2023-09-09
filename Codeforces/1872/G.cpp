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
        vector<int> v(n+1), n1;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] != 1){
                n1.push_back(i);
            }
        }
        if(n1.size() <= 1) cout << "1 1\n";
        else{
            ll P = 1;
            for(int i=n1[0]; i<= n1.back(); i++){
                P = min((ll)INF_INT, P * v[i]);
            }
            if(P == INF_INT) cout << n1[0] << " " << n1.back() << "\n";
            else{
                //in this case, afn1 * afn1+1 * .... aln1 < INF_INT, brute force hehehe!!
                vector<int> ps(n+1, 0);
                for(int i=1;i<=n;i++){
                    ps[i] = ps[i-1] + v[i];
                }
                pair<int,int> ans = {1, 1};
                ll maxsum = ps[n];
                for(int i=0;i<n1.size();i++){
                    ll curP = v[n1[i]];
                    for(int j=i+1;j<n1.size();j++){
                        curP *= v[n1[j]];
                        int l = n1[i], r = n1[j];
                        ll cursum = ps[l-1] + ps[n] - ps[r] + curP;
                        if(cursum > maxsum){
                            maxsum = cursum;
                            ans = {l, r};
                        }
                    }
                }
                cout << ans.first << " " << ans.second << "\n";

            }
        }
        
    }
}
