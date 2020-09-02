//Easy problem, dirty solution
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cont=0;
    int len = s.size();
    s.resize(105);
    for(int i=0; i<len;i++){
            if(s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='k'&&s[i+3]=='i'&&s[i+4]=='t'&&s[i+5]=='a') cont++;
            if(s[i]=='A'&&s[i+1]=='n'&&s[i+2]=='n') cont++;
            if(s[i]=='S'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='a') cont++;
            if(s[i]=='O'&&s[i+1]=='l'&&s[i+2]=='y'&&s[i+3]=='a') cont++;
            if(s[i]=='D'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='i'&&s[i+4]=='l') cont++;
    }

    if(cont==1) cout << "YES";
    else cout << "NO";

}
