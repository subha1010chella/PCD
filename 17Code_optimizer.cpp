#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
using namespace std;
int ptr;
map<string,int> m;
int mapper(string var){
 int val=m[var];
 if(val!=0)
 return val;
 m[var]=++ptr;
 return ptr;
}
//global declarations
const int maxn=1e3;
string ip;
vector<string> lineList;
vector< vector<int>> varList;
set< int > lastsaved[maxn];
int vis[maxn];
vector<int> adjlist[maxn];
//end global declarations
bool read(){
 ip="";
 while(ip.size()==0)
 getline(cin,ip);
 return !(ip=="$");
}
bool nonVar(char c){
 if(c>='0' && c<='9')
 return false;
 if(c=='+' || c=='-' || c=='/' || c=='*' || c=='=')
 return false;
 return true;
}
vector<int> getVariables(string s){
 int lptr=0,rptr=0;
 vector<int> seq;
 while(rptr!=s.size()){
 if(nonVar(s[rptr])){
 rptr++;
 }
 else{
 if(lptr!=rptr){
 string temp=s.substr(lptr,rptr-lptr);
 int id=mapper(temp);
 seq.pb(id);
 }
 rptr++;
 lptr=rptr;
 }
 }
 if(lptr<rptr){
 string temp=s.substr(lptr,rptr-lptr);
 int id=mapper(temp);
 seq.pb(id);
 }
 return seq;
}
void dfs(int cur){
 vis[cur]=1;
 for(int i=1;i<varList[cur].size();i++){
 int var=varList[cur][i];
 set<int>::iterator it=lastsaved[var].lower_bound(cur);
 if(it==lastsaved[var].begin())
 continue;
 it--;
 if(vis[*it]==0){
 vis[*it]=1;
 dfs(*it);
 }
 }
}
int main()
{
 fastread;
 cout<<"DEAD CODE OPTIMISATION"<<endl<<endl;
 while(read()){
 if((ip.find("=")==string::npos) && ip.find("print(")==string::npos)
 continue;
 while(ip.find(" ")!=string::npos)
 ip.erase(std::find(ip.begin(), ip.end(), ' '));
 lineList.pb(ip);
 }
 for(int i=0;i<lineList.size();i++){
 string u=lineList[i];
 if(u.find("print(")!=string::npos){
 int en=6,st=6;
 while(u[en]!=')')
 en++;
 int prevptr=ptr;
 int id=mapper(u.substr(st,en-st));
 int curptr=ptr;
 if(prevptr!=curptr){
 cout<<u.substr(st,en-st)<<" not used"<<endl;
 return 0;
 }
 set<int>::iterator it=lastsaved[id].end();
 if(!lastsaved[id].empty()){
 it--;
 dfs(*it);
 }
 vis[i]=1;
 vector<int> temp;
 varList.pb(temp);
 continue;
 }
 varList.pb(getVariables(u));
 lastsaved[varList.back()[0]].insert(i);
 for(int j=1;j<varList.back().size();j++){
 set<int>::iterator it=lastsaved[varList.back()[j]].end();
 if(!lastsaved[varList.back()[j]].empty()){
 it--;
 adjlist[i].pb(*it);
 }
 }
 }
 cout<<"Optimised Code"<<endl;
 for(int i=0;i<lineList.size();i++){
 if(vis[i])
 cout<<lineList[i]<<'\n';
 }
 return 0;
}
