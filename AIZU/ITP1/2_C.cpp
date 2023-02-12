#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    if(b > c) swap(b,c);
    if(a > b) swap(a,b);
    if(b > c) swap(b,c);
    cout << a <<  " " << b << " " << c << "\n";
}