#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        char hassol = true, hasn = false, has1 = false;
        cin >> n;
        vector<int> ans1(n+1,0), ans2(n+1,0);
        vector<int> avail1(n+2,1), avail2(n+2,1);
        vector<pair<int,int>> v(n+1);
        v[0] = {0,0};
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            if(aux == n) hasn = true;
            v[i] = {aux, i};
        }
        if(!hasn){
            cout << "NO\n";
            continue;
        }
        sort(v.begin(), v.end());
        
        int p1 = 1, p2 = 1;
        for(int i=1;i<=n;i++){
            if(avail1[v[i].first]){
                avail1[v[i].first] = 0;
                ans1[v[i].second] = v[i].first;
                while(!avail2[p2]) p2++;
                if(p2 <= v[i].first){
                    avail2[p2] = 0;
                    ans2[v[i].second] = p2;
                }else{
                    hassol = false; break;
                }
            }else if(avail2[v[i].first]){
                avail2[v[i].first] = 0;
                ans2[v[i].second] = v[i].first;
                while(!avail1[p1]) p1++;
                if(p1 <= v[i].first){
                    avail1[p1] = 0;
                    ans1[v[i].second] = p1;
                }else{
                    hassol = false; break;
                }
            }else{
                hassol = false;
                break;
            }
        }


        if(!hassol) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << ans1[i] << " ";
            cout <<"\n";
            for(int i=1;i<=n;i++) cout << ans2[i] << " ";
            cout <<"\n";
        }
    }
}
