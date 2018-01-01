#include <iostream>
#include <conio.h>
#include <cstdio>
#include <vector>
using namespace std;
vector<char> comm;
int matrix[10003][10003],n,m; char command;
void spin_l() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n/2;j++) {
			swap(matrix[i][j],matrix[i][n-j-1]);
		}
	}
} 
void spin_u() {
	for(int i=0;i<n/2;i++) {
		for(int j=0;j<n;j++) {
			swap(matrix[i][j],matrix[n-i-1][j]);
		}
	}
}
void spin_x() {
	spin_l();
	spin_u();
}
void spin_y() {
	spin_u();
	spin_l();
}
void spin_t() {
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-1;j++) {
			swap(matrix[i][j],matrix[n-1-j][n-1-i]);
			//swap(matrix[n-j-1][i],matrix[i][j]);
		}
	}
	for(int i=0;i<n/2-1;i++) {
		for(int j=0;j<n-1;j++) {
			swap(matrix[i][j],matrix[n-1-i][j]);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int t=0;t<m;t++) {
		command=getche();
		comm.push_back(command);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	for(int t=0;t<m;t++) {
		command=comm.back();
		comm.pop_back();
		switch(command) {
			case 'L':
				spin_l();
				break;
			case 'U':
				spin_u();
				break;
			case 'X':
				spin_x();
				break;
			case 'Y':
				spin_y();
				break;
			case 'T':
				spin_t();
				spin_u(); 
				break;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
