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
        string s;
        cin >> n >> s;
        priority_queue<pair<int, char>> pq;
        vector<int> cnt(26, 0);
        for(auto c : s){
            cnt[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i] != 0) pq.push({cnt[i], 'a'+i});
        }
        string ans = "";
        while(!pq.empty()){
            if(pq.size() == 2){
                auto p1 = pq.top();
                pq.pop();
                auto p2 = pq.top();
                pq.pop();
                ans += p1.second;
                ans += p2.second;
                p1.first--;
                p2.first--;
                if(p1.first > 0) pq.push(p1);
                if(p2.first > 0) pq.push(p2);
            }else{
                auto p1 = pq.top();
                pq.pop();
                ans += p1.second;
                p1.first--;
                if(p1.first > 0) pq.push(p1);
            }
        }
        cout << ans << "\n";
    }
}
