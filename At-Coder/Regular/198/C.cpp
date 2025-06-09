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
    int sa = 0, sb = 0;
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sa += a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        sb += b[i];
    }
    int cnt = 0;
    if(sa != sb) cout << "No\n";
    else if(n == 2){
        if(a == b) cout << "Yes\n0\n";
        else if(a[2] - 1 == b[1] && a[1] + 1 == b[2]) cout << "Yes\n1\n1 2\n";
        else cout << "No\n";
    }else{
        cout << "Yes\n"; //now construction.
        vector<pair<int, int>> asw;
        auto do_move = [&](int c, int d){
            asw.emplace_back(c, d);
            swap(a[c], a[d]);
            a[c]--;
            a[d]++;
        };
        auto transfer_from = [&](int a, int b){
            do_move(a, n);
            do_move(b, n);
            do_move(a, b);
        };
        auto transfer_to = [&](int a, int b){
            do_move(a, a+1);
            do_move(a+1, b);
            do_move(a, b);
        };
        for(int i=1;i<=n-3;i++){
            while(a[i] > b[i]){
                int ps = min_element(a.begin() + i + 1, a.end()-1) - a.begin();
                transfer_from(i, ps);
            }
            while(a[i] < b[i]){
                int ps = max_element(a.begin() + i + 2, a.end()) - a.begin();
                transfer_to(i, ps);
            }
        }
        //what to do now! LOL
        auto swap = [&](int a, int b){ // a >= 1, b >= 1
            do_move(1, a);
            do_move(1, b);
            do_move(1, a);
        };
        while(max(a[n-1], a[n]) > max(b[n-1], b[n])){
            if(a[n-1] == max(a[n-1], a[n])) swap(n-1, n); 
            transfer_to(n-2, n);
        }
        while(max(a[n-1], a[n]) < max(b[n-1], b[n])){
            if(a[n] == max(a[n-1], a[n])) swap(n-1, n);
            transfer_from(n-2, n-1);
        }
        while(min(a[n-1], a[n]) < min(b[n-1], b[n])){
            if(a[n] == min(a[n-1], a[n])) swap(n-1, n);
            transfer_from(n-2, n-1);
        }
        while(min(a[n-1], a[n]) > min(b[n-1], b[n])){
            if(a[n-1] == min(a[n-1], a[n])) swap(n-1, n);
            transfer_to(n-2, n);
        }
        if(a[n-1] != b[n-1]) swap(n-1, n);
        assert(a == b);
        cout << asw.size() << "\n";
        for(auto &[a, b] : asw) cout << a << " " << b << "\n";

    }
}
