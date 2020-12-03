#include <bits/stdc++.h>
using namespace std;

int main(){
int k,a,b;
cin >>k;
while(k--){
    cin >> a >> b;
    if ((a+b)%3) cout << "NO" << endl;
    else{
        if((max(a,b)-min(a,b))> (a+b)/3 ) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
}
}
