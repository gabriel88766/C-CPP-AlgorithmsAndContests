
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< int, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
# define PI          3.141592653589793238462643383279502884L
//matrix vector<vector<int>> matrix(row,vector<int>(col));

using namespace std;


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s,cur;
char flag,quote=34;
cin >> s;
vector<string> numbers;
vector<string> strings;
int beginp,endp=0,cont=0;
beginp=0;
while(endp<s.size()){
    if(s[endp]==',' || s[endp]==';'){
        flag=0;
        cur = s.substr(beginp,endp-beginp);
        if(cur.size()==1 && cur[0] >= '0' && cur[0] <='9'){
            numbers.push_back(cur);
        }else{
            if((cur[0]=='0'&&cur.size()>1)||cur.size()==0){
                flag=1;
            }else{
                for(int i=0;i<cur.size();i++){

                    if(cur[i]>='0' && cur[i]<='9'){
                        continue;
                    }else{
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)strings.push_back(cur);
                else numbers.push_back(cur);
        }
        endp++;
        beginp=endp;
    }else{
        endp++;
    }
}

//repeat;
    flag=0;
        cur = s.substr(beginp,endp-beginp);
        if(cur.size()==1 && cur[0] >= '0' && cur[0] <='9'){
            numbers.push_back(cur);
        }else{
            if((cur[0]=='0'&&cur.size()>1)||cur.size()==0){
                flag=1;
            }else{
                for(int i=0;i<cur.size();i++){

                    if(cur[i]>='0' && cur[i]<='9'){
                        continue;
                    }else{
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)strings.push_back(cur);
                else numbers.push_back(cur);
        }
     if(!numbers.size()) cout << "-" << endl;
     else{
        cout << quote;
        for(int i=0;i<numbers.size();i++){
            if(i!=(numbers.size()-1)) cout << numbers[i] << ",";
            else cout << numbers[i];
        }
        cout << quote << endl;
     }
     if(!strings.size()) cout << "-";
     else{
        cout << quote;
        for(int i=0;i<strings.size();i++){
            if(i!=(strings.size()-1)) cout << strings[i] << ",";
            else cout << strings[i];
        }
        cout << quote;
     }

}
