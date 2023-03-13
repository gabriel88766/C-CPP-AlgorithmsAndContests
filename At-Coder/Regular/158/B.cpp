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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> pos, neg;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] > 0) pos.emplace_back(v[i]);
        else neg.emplace_back(v[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    double minans = 1e300, maxans = -1e300;
    //first case, only pos
    int szpos = pos.size(), szneg = neg.size();
    if(szpos >= 3){
        maxans = (double)(pos[0]+pos[1]+pos[2])/(pos[0]*pos[1]*pos[2]);
        minans = (double)(pos[szpos-1]+pos[szpos-2]+pos[szpos-3])/(pos[szpos-1]*pos[szpos-2]*pos[szpos-3]);
    }
    if(szneg >= 1 && szpos >= 2 ){
        for(int i=0;i<neg.size();i++){
            maxans = max(maxans, (double)(neg[i] + pos[0] + pos[1])/(neg[i]*pos[0]*pos[1]));
            minans = min(minans, (double)(neg[i] + pos[0] + pos[1])/(neg[i]*pos[0]*pos[1]));
            maxans = max(maxans, (double)(neg[i] + pos[szpos-2] + pos[szpos-1])/(neg[i]*pos[szpos-2]*pos[szpos-1]));
            minans = min(minans, (double)(neg[i] + pos[szpos-2] + pos[szpos-1])/(neg[i]*pos[szpos-2]*pos[szpos-1]));
        }
    }
    if(szneg >= 2 && szpos >= 1){
        for(int i=0;i<pos.size();i++){
            minans = min(minans, (double)(pos[i] + neg[0] + neg[1])/(pos[i]*neg[0]*neg[1]));
            minans = min(minans, (double)(pos[i] + neg[szneg-2] + neg[szneg-1])/(pos[i]*neg[szneg-2]*neg[szneg-1]));
            maxans = max(maxans, (double)(pos[i] + neg[0] + neg[1])/(pos[i]*neg[0]*neg[1]));
            maxans = max(maxans, (double)(pos[i] + neg[szneg-2] + neg[szneg-1])/(pos[i]*neg[szneg-2]*neg[szneg-1]));
        }
    }
    if(szneg >= 3){
        maxans = max(maxans, (double)(neg[szneg-1]+neg[szneg-2]+neg[szneg-3])/(neg[szneg-3]*neg[szneg-2]*neg[szneg-1]));
        minans =  min(minans, (double)(neg[0]+neg[1]+neg[2])/(neg[0]*neg[1]*neg[2]));
    }
    cout << fixed << setprecision(15) << minans << "\n" << maxans;
}
 