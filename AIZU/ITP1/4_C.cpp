#include<bits/stdc++.h>

const double PI = acos(-1.);
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    char c;
    cin >> a >> c >> b;
    while(c != '?'){
        if(c == '+') cout << a+b << "\n";
        else if(c == '-') cout << a-b << "\n";
        else if(c == '*') cout << a*b << "\n";
        else cout << a/b << "\n";
        cin >> a >> c >> b;
    }
}