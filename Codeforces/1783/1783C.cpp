#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    vector<pair<int,int>> v(500005);
    int u[500005];
    vector<bool> isin(500005);
    while(t--){
        int n,m;
        cin >> n >> m;

        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            v[i] = {aux, i};
            u[i] = aux;
            isin[i] = false;
        } 
        isin[n] = false; //causing bugs...
        sort(v.begin(), v.begin() + n);
        int cnt = 0, sum = 0, curm=m, pointer=0;
        for(int i=0;i<n;i++){
            if(curm >= v[i].first){
                cnt++;
                curm -= v[i].first;
                isin[v[i].second] = true;
            }else {
                if(i) pointer = i-1;
                break;
            }
        }
        int pos = n - cnt + 1;
        if(pos != 1 && !isin[n-pos+1] && isin[v[pointer].second]){
            if(u[n-pos+1] - curm  <= v[pointer].first){
                isin[n-pos+1] = true;
            }
        }
        if(isin[n-pos+1]) pos--;
        cout << pos << "\n";

    }
}
