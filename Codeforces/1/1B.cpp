//Implementation, decode.

// s.substr(int pos, int len);

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
using namespace std;

int cpos;

bool isRC(string s){
    if(s[0]!='R') return false;
    int sizeofs = s.size();
    if(s[1]>='0' && s[1] <= '9'){
    } else return false;
    for(int i=2;i<sizeofs;i++){
        if(s[i]=='C'){
            cpos=i;
            return true;
        }
    }
    return false;
}

int pow26[] = {1,26,26*26,26*26*26,26*26*26*26,26*26*26*26*26,26*26*26*26*26*26};
string inttoAA(int n){
    vector<char> v;
    string s = "";
    int cont=0;
    while(n!=0){
        if(n%26!=0){
            v.push_back(n%26 + 'A'-1);
        }else{
            v.push_back('Z');
            n-=26;
        }
        n/=26;
        cont ++;
    }
    while(v.size()>0){
        s+=v[v.size()-1];
        v.pop_back();
    }
    return s;
}
int AAtoInt(string s){
    int result=0;
    for(int i=s.size()-1;i>=0;i--){
        result+=(s[i]-'A'+1) * pow26[s.size()-1-i];
    }
    return result;
}

void fromRCtoAI(string s){
    string outp;
    outp = s.substr(cpos+1,s.size()-1);
    cout << inttoAA(atoi(outp.c_str()));
    outp = s.substr(1,cpos-1);
    cout << outp << endl;
}

void fromAItoRC(string s){
    int fl,i;
    for(i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') {
                break;
        }
    }
    cout << "R" << s.substr(i,s.size()-1) << "C" << AAtoInt(s.substr(0,i)) << endl;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s;
int n;
cin >> n;
for(int i=0;i<n;i++){
    cin >> s;
    if(isRC(s)){
        fromRCtoAI(s);
    }else{
        fromAItoRC(s);
    }
}


}
