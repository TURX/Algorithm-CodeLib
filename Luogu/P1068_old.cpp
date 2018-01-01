#include<iostream>
#include<algorithm>
using namespace std;
int n,m,least,passedpeople,k[100],s[100];
bool flag; 
void bubbleSort(int (&EnterIntArray)[100],int (&AnotherArray)[100]) {
	flag = true;
	for (int i = 0; flag; i++)
	{
	    flag = false;
	    for (int j = n - 1; j >= i + 1; j--)
	    {
	        if (EnterIntArray[j] > EnterIntArray[j - 1])
	        {
	        	swap(EnterIntArray[j],EnterIntArray[j - 1]);
	        	swap(AnotherArray[j],AnotherArray[j - 1]);
	            flag = true;
	        }
	    }
	}
} 
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int t=0;t<n;t++) cin>>k[t]>>s[t];
	passedpeople=m*1.5;
	bubbleSort(s,k);
	sort(s,s+n);
	least=s[passedpeople];
	cout<<least<<" "<<passedpeople<<endl;
	for(int t=0;t<=passedpeople;t++) cout<<k[t]<<" "<<s[t]<<endl;
	return 0;
}