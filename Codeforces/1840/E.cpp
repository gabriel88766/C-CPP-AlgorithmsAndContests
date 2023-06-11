#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;

ll v[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int T;
    cin >> T;
    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        int sum = 0, n;
        n = s1.size();
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                v[i+1] = 1;
                sum++;
            }
        }
        int t, q;
        cin >> t >> q;
        queue<pair<int,int>> list;
        vector<bool> blocked(n+1, false);
        for(int i=1;i<=q;i++){
            if(!list.empty() && list.front().first == i){
                //unblock
                blocked[list.front().second] = false;
                sum += v[list.front().second];
                list.pop();
            }
            int tq;
            cin >> tq;
            if(tq == 1){
                int pos;
                cin >> pos;
                list.push({i+t, pos});
                blocked[pos] = true;
                sum -= v[pos];
            }else if(tq == 2){
                int a,b,c,d;
                cin >> a >> b >> c >> d;
                if(b == d){
                    if(a != c) swap(s1[b-1], s2[b-1]);
                }else{
                    if(!blocked[b]) sum -= v[b];
                    if(!blocked[d]) sum -= v[d];
                    if(a == 1 && c == 1) swap(s1[b-1], s1[d-1]);
                    if(a == 1 && c == 2) swap(s1[b-1], s2[d-1]);
                    if(a == 2 && c == 1) swap(s2[b-1], s1[d-1]);
                    if(a == 2 && c == 2) swap(s2[b-1], s2[d-1]);
                    v[b] = s1[b-1] == s2[b-1] ? 0 : 1;
                    v[d] = s1[d-1] == s2[d-1] ? 0 : 1;
                    if(!blocked[b]) sum += v[b];
                    if(!blocked[d]) sum += v[d];
                }
            }else{
                if(sum == 0) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        //clear globals!
        for(int i=1;i<=n;i++) v[i] = 0;
    }
}
