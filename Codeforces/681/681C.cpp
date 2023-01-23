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
    vector<pair<string, int>> vp;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int aux;
        cin >> s;
        if(s == "removeMin"){
            if(pq.empty()){
                vp.push_back({"insert", 1});
                pq.push(1);
            }
            vp.push_back({"removeMin", 0});
            pq.pop();
        }else if(s == "insert"){
            cin >> aux;
            vp.push_back({"insert", aux});
            pq.push(aux);
        }else{
            cin >> aux;
            int top = pq.empty() ? INF_INT : pq.top();
            while(top < aux){
                vp.push_back({"removeMin", 0});
                pq.pop();
                top = pq.empty() ? INF_INT : pq.top();
            }
            if(top != aux){
                vp.push_back({"insert", aux});
                pq.push(aux);
            }
            vp.push_back({"getMin", aux});
        }
    }
    cout << vp.size() << "\n";
    for(int i=0;i<vp.size();i++){
        cout << vp[i].first;
        if(vp[i].first != "removeMin") cout << " " << vp[i].second;
        cout << "\n";
    }
}
