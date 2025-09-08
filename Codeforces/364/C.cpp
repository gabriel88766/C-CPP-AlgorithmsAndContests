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
    // freopen("out", "w", stdout); //test input
    int k;
    cin >> k;
    vector<int> v1, v2, v3;
    if(k >= 1000){
        for(int i=165;i<=2*k*k;i+=165){
            int j = i;
            while(j % 2 == 0) j /= 2;
            while(j % 3 == 0) j /= 3;
            while(j % 5 == 0) j /= 5;
            while(j % 7 == 0) j /= 7;
            while(j % 11 == 0) j /= 11;
            while(j % 13 == 0) j /= 13;
            if(j == 1){
                if(i % 30030 == 0) v3.push_back(i);
                else v1.push_back(i);
            }
        }
        for(int i=182;i<=2*k*k;i+=182){
            int j = i;
            if(i % 30030 == 0) continue;
            while(j % 2 == 0) j /= 2;
            while(j % 3 == 0) j /= 3;
            while(j % 5 == 0) j /= 5;
            while(j % 7 == 0) j /= 7;
            while(j % 11 == 0) j /= 11;
            while(j % 13 == 0) j /= 13;
            if(j == 1){
                v2.push_back(i);
            }
        }
    }else{
        for(int i=14;i<=2*k*k;i+=14){
            int j = i;
            while(j % 2 == 0) j /= 2;
            while(j % 3 == 0) j /= 3;
            while(j % 5 == 0) j /= 5;
            while(j % 7 == 0) j /= 7;
            if(j == 1){
                if(i % 210 == 0) v3.push_back(i);
                else v1.push_back(i);
            }
        }
        for(int i=15;i<=2*k*k;i+=15){
            int j = i;
            if(i % 210 == 0) continue;
            while(j % 2 == 0) j /= 2;
            while(j % 3 == 0) j /= 3;
            while(j % 5 == 0) j /= 5;
            while(j % 7 == 0) j /= 7;
            if(j == 1){
                v2.push_back(i);
            }
        }
    }
    while(k && v3.size()){
        cout << v3.back() << " ";
        v3.pop_back();
        k--;
    }
    while(k){
        if(k % 2){
            if(v1.size()){
                cout << v1.back() << " ";
                v1.pop_back();
            }else{
                cout << v2.back() << " ";
                v2.pop_back();
            }
        }else{
            if(v2.size()){
                cout << v2.back() << " ";
                v2.pop_back();
            }else{
                cout << v1.back() << " ";
                v1.pop_back();
            }
        }
        k--;
    }
    
}
