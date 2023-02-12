#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, a=0,b=0,c=0, ab=0, ac=0, ba=0, bc =0, ca=0, cb=0;
    string s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        if(s[i] == '0') a++;
        else if(s[i] == '1') b++;
        else c++;
    }
    int aim = n/3;
    if(a > aim && b < aim){
        ab = min(a-aim, aim - b);
        a -= ab;
        b += ab;
    }
    if(a > aim && c < aim){
        ac = min(a-aim, aim - c);
        a -= ac;
        c += ac;
    }
    if(b > aim && a < aim){
        ba = min(b-aim, aim-a);
        b -= ba;
        a += ba;
    }
    if(b > aim && c < aim){
        bc = min(b-aim, aim-c);
        b -= bc;
        c += bc;
    }
    if(c > aim && a < aim){
        ca = min(c-aim, aim-a);
        c -= ca;
        a += ca;
    }
    if(c > aim && b < aim){
        cb = min(c-aim, aim-b);
        c -= cb;
        a += cb;
    }

    
    if(ac > 0){
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(cnt == ac) break;
            if(s[i] == '0'){
                s[i] = '2';
                cnt++;
            }
        }
    }
    if(ab > 0){
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(cnt == ab) break;
            if(s[i] == '0'){
                s[i] = '1';
                cnt++;
            }
        }
    }
    if(bc > 0){
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(cnt == bc) break;
            if(s[i] == '1'){
                s[i] = '2';
                cnt++;
            }
        }
    }
    if(ba > 0){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt == ba) break;
            if(s[i] == '1'){
                s[i] = '0';
                cnt++;
            }
        }
    }
    if(ca > 0){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt == ca) break;
            if(s[i] == '2'){
                s[i] = '0';
                cnt++;
            }
        }
    }
    if(cb > 0){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt == cb) break;
            if(s[i] == '2'){
                s[i] = '1';
                cnt++;
            }
        }
    }
    cout << s;
}
