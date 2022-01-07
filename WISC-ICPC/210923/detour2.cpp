#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
const int INF=0x3f3f3f3f;
struct node{
    int s,t,c,ne;
} ;
node edge[maxn];
int tot;
int dis[maxn];
int head[maxn],pre[maxn];
bool vis[maxn];
bool f;
int ans[maxn],len=0;
struct nod{
    int t,c;
    nod(int _t=0,int _c=0):t(_t),c(_c) {}
    bool operator <(const nod &r)const
    {
        return c>r.c;
    }
};
void addedge(int s,int t,int cost)
{
    edge[tot].s=s;
    edge[tot].t=t;
    edge[tot].c=cost;
    edge[tot].ne=head[s];
    head[s]=tot++;
}
void Dj(int n,int start){
    priority_queue<nod> q;
    while(!q.empty()) q.pop();
    dis[start]=0;
    q.push(nod(start,0));
    nod tmp;
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        int u=tmp.t;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].ne){
            int v=edge[i].t;
            int c=edge[i].c;
            if(!vis[v]&&dis[v]>dis[u]+c){
                pre[v]=u;
                dis[v]=dis[u]+c;
                q.push(nod(v,dis[v]));
            }
        }
       
    }
}
void print_ans(int point)
{
    if(point==1)
    {
        cout<<" "<<0;
        return ;
    }
    print_ans(point-1);
    cout<<" "<<ans[point]-1;
}
int n,m;
void dfs(int t,int p){
    ans[++len]=t;
    vis[t]=1;
    if(t==2){
        f=1;
        cout<<len;
        print_ans(len);
        cout<<endl;
        return ;
    }
    for(int i=head[t];i!=-1;i=edge[i].ne){
        int v=edge[i].t;
        if(pre[t]==v||vis[v]) continue;
        dfs(v,t);
        if(f) return ;
       
    }
    len--;
}
int main(){
	freopen("test.in", "r", stdin);
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    memset(head,-1,sizeof(head));
    f=tot=0;
    cin>>n>>m;
    for(int i=1,s,t,c;i<=m;i++){
        cin>>s>>t>>c;
        addedge(s+1,t+1,c);
        addedge(t+1,s+1,c);
    }
    Dj(n,2);
    memset(vis,0,sizeof(vis));
    dfs(1,-1);
    if(!f) cout<<"impossible"<<endl;
	for (int t = 1; t <= n; t++)
		cout << dis[t] << " ";
    cout << endl;
	for (int t = 1; t <= n; t++)
		cout << pre[t] << " ";
    cout << endl;
    return 0;
   
}