#include <iostream>
#include <algorithm>
using namespace std;
struct president_data {
    string vote;
    int num;
} president[20];
/*bool cmp(president_data lhs, president_data rhs)
{
    if (lhs.vote.size() != rhs.vote.size()) {
		if(lhs.vote>rhs.vote) return 1; else if(lhs.vote<rhs.vote) return 0;
        return lhs.vote.size() > rhs.vote.size();
    }
    else
        return lhs.num < rhs.num;
}*/
int com(string a,string b){
    int l=a.size(),ll=b.size();
    if(l==ll&&a>b) return 1;
    else if(l==ll&&a<b) return 0;
    else if(l>ll) return 1;
    else if(l<ll) return 0;
 }
bool cmp(president_data left, president_data right) {
	return com(left.vote, right.vote);
}

int main() {
    int n;
    cin>>n;
    string str;
    for(int t=0;t<n;t++) {
        cin>>str;
        president[t].vote=str;
        president[t].num=t;
    }
    sort(president,president+n,cmp);
    cout<<president[0].num+1<<endl<<president[0].vote<<endl;
    return 0;
}
