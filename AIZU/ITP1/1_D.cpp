#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,h,m,s;
    cin >> a;
    h = a/3600;
    a -= h*3600;
    m = a/60;
    a -= m*60;
    s = a;
    cout << h << ":" << m << ":" << s << "\n";


}