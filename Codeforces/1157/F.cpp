#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int qt[200005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    pair<int, int> ans;
    int maxv = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        qt[aux]++;
    }
    int bp = 1, ep = 1, curqt = 0;
    for(int i=1;i<=200001;i++){
        if(qt[i] < 2){
            if(qt[i] == 1){
                ep = i;
                curqt += qt[i];
            }
            if(curqt > maxv){
                maxv = curqt;
                ans = {bp, ep};
            }
            bp = ep = i;
            curqt = qt[i];
        }else{
            ep++;
            curqt += qt[i];
        }
    }
    deque<int> pr;
    for(int i=ans.first; i<= ans.second;i++){
        if(qt[i]) pr.push_front(i);
        for(int j=0;j<(qt[i]-1);j++){
            pr.push_back(i);
        }
    }
    cout << pr.size() << "\n";
    for(int i=0;i<pr.size();i++) cout << pr[i] << " ";
}
