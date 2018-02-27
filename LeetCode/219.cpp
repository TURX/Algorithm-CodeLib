#include <iostream>
#include <vector> 
#include <cstdio>
using namespace std;
vector<int> nums; int k;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = i - k; j < i + k; j++) {
        		if(j == i || j < 0) continue;
        		if(nums[j] == nums[i]) return true;
			}
		}
		return false;
    }
};

/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	vector<int>::iterator i, j;
        for(i = nums.begin(); i != nums.end(); i++) {
        	int diff = 0;
        	for(j = i - k; j != i + k; j++) {
        		diff++;
        		if(j == i) continue;
        		if(*j == *i) return true;
			}
		}
		return false;
    }
};
*/

int main() {
	Solution sol;
	while(true) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
		if(getchar() == '\n') break;
	}
	cin >> k;
	cout << sol.containsNearbyDuplicate(nums, k) << endl;
}
