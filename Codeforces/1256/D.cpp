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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        deque<pair<int,ll>> dq;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') cnt++;
            else{
                dq.push_back({i, cnt});
            }
        }
        int cnt0 = 0, cnt1;
        while(k >= 0 && dq.size()){
            if(k >= dq.front().second){
                k -= dq.front().second;
                cnt0++;
                dq.pop_front();
            }else{
                cnt1 = dq.front().second - k;
                break;
            }
        }
        for(int i=0;i<cnt0;i++) cout << "0";
        if(dq.size()){
            for(int i=0;i<cnt1;i++) cout << "1";
            cout << "0";
            for(int i=cnt0+cnt1+1;i<=dq.front().first;i++) cout << "1";
            for(int i=dq.front().first+1;i<n;i++) cout << s[i];
        }else{
            for(int i=cnt0;i<n;i++) cout << "1";
        }
        cout << "\n";
    }
}
