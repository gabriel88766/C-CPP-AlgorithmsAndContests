#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(vector<int> &num){
    cout << "? ";
    for(auto x : num) cout << x << " ";
    cout << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
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
        vector<deque<int>> dq(n+1);
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                dq[i+1].push_back(n*i + j);
            }
        }
        for(int i=1;i<=n;i++){
            vector<int> q1;
            for(auto x : dq[i]) q1.push_back(x);
            int ans = query(q1);
            for(int j=1;j<n;j++) if(ans == dq[i][j]) swap(dq[i][j], dq[i][0]);
        }
        vector<int> ans;
        int bef = -1;
        for(int i=1;i<=n*n-n+1;i++){
            if(bef != -1){
                if(dq[bef].size() > 1){
                    vector<int> qn;
                    for(auto x : dq[bef]) qn.push_back(x);
                    for(int j=1;j<=n;j++){
                        if(j == bef) continue;
                        if(dq[j].size() == 1) qn.push_back(dq[j][0]);
                        else{
                            for(int k=1;k<dq[j].size();k++){
                                qn.push_back(dq[j][k]);
                                if(qn.size() == n) break;
                            }
                        }
                        if(qn.size() == n) break;
                    }
                    int ans = query(qn);
                    for(int j=1;j<=n;j++){
                        for(int k=0;k<dq[j].size();k++){
                            if(ans == dq[j][k]){
                                swap(dq[j][k], dq[bef][0]);
                            }
                        }
                    }
                }else if(dq[bef].size() == 0){
                    for(int j=1;j<=n;j++){
                        //arbitrary
                        if(dq[j].size() > 1 && bef != j){
                            dq[bef].push_back(dq[j].back());
                            dq[j].pop_back();
                            break;
                        }
                    }
                }
            }
            vector<int> qn;
            for(int j=1;j<=n;j++) qn.push_back(dq[j][0]);
            int an = query(qn);
            ans.push_back(an);
            for(int j=1;j<=n;j++){
                if(dq[j][0] == an){
                    bef = j;
                    dq[j].pop_front();
                }
            }
        }
        cout << "! ";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
        cout.flush();
    }
}
