#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num;
char str[100003];

int main() {
    sprintf(str, "%d", num);
    for(int t = 0; t < strlen(str); t++) {
        cout << str[t] << endl;
    }
    return 0;
}