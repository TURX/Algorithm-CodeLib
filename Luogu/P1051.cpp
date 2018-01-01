#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N;
struct student {
	string name;
	long long average=0;
	long long classown=0;
	bool leader=0;
	bool western=0;
	long long essay=0;
	long long scolar() {
		long long calc_temp=0;
		if(average>80&&essay>0) calc_temp+=8000;
		if(average>85&&classown>80) calc_temp+=4000;
		if(average>90) calc_temp+=2000;
		if(average>80&&western==1) calc_temp+=1000;
		if(classown>80&&leader==1) calc_temp+=850;
		return calc_temp;
	}
	friend bool operator <(student left, student right) {
		return left.scolar()<right.scolar();
	}
};
student make_stu(string name,long long average,long long classown,bool leader,bool western,long long essay) {
	student temp_stu;
	temp_stu.name=name; temp_stu.average=average; temp_stu.classown=classown; temp_stu.leader=leader; temp_stu.western=western; temp_stu.essay=essay;
	return temp_stu;
}
priority_queue<student> stu;
long long totalSco() {
	long long scoTotal=0;
	student stu_temp;
	while(!stu.empty()) {
		stu_temp=stu.top();
		scoTotal+=stu_temp.scolar();
		stu.pop();
	}
	return scoTotal;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N;
	string name;
	long long average,classown,essay;
	bool leader,western;
	char temp1,temp2;
	for(int t=0;t<N;t++) {
		cin>>name>>average>>classown>>temp1>>temp2>>essay;
		if(temp1=='Y') leader=1; else leader=0;
		if(temp2=='Y') western=1; else western=0;
		stu.push(make_stu(name,average,classown,leader,western,essay));
	}
	student top_stu=stu.top();
	cout<<top_stu.name<<endl<<top_stu.scolar()<<endl;
	cout<<totalSco()<<endl;
}
