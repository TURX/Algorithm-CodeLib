// KMP Algorithm    KMP 算法
// Copyright by (C) 2019  TURX

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1000001

char S[MAXN], T[MAXN];
int NE[MAXN], pos, lenS, lenT;

inline void pre() { // 通过T串自己匹配自己求出预处理的next数组
    NE[1] = 0; // 第一位不能自己和自己匹配
    for(int i = 2, j = 0; i <= lenT; i++) { // 从第二位开始计算，j + 1是因为字符串从1开始
        /* 当失配时回到最近的前缀之后开始匹配
         * e.g. S:  abaabbabaab (i)
         *             ^
         *      TB: abaabbabaab (j + 1)
         *           ^ |                此处失配
         *      TA: abaabbabaab (j + 1)
         *          ^  |                回到前缀（如果没有前缀的话回到0）直到可以匹配（现在回到0的话，j + 1即1，即可以得到匹配的前后缀a，循环退出）
         *      NE: 01120123450
         */
        while(j > 0 && T[i] != T[j + 1]) j = NE[j];
        /* 如果这一位可以匹配（即找到了匹配的前后缀）就继续向后推进，且i会自动++，因为循环重复
         * e.g. S:  abaabbabaab (i)
         *            ^*
         *      TB: abaabbabaab (j + 1)
         *          ^ |                 此处找到了匹配的前后缀a
         *      TA: abaabbabaab (j + 1)
         *           ^ |                往后推进，这样的话也可以找到后面是否有继续的匹配的前后缀
         *      NE: 01120123450
         */
        if(T[i] == T[j + 1]) j++;
        NE[i] = j; // 设置NE的值为当前可以匹配到的前缀长度，即至此（i）之前有多少个字符的后缀有匹配的前缀
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> S + 1 >> T + 1; // next数组的求法限制了从下标0输入的方案，所以只能输入时将指针右移1位来从下标1开始输入
    lenS = strlen(S + 1), lenT = strlen(T + 1);
    pre(); // 预处理，求出next数组
    for(int i = 1; i <= lenS; i++) { // 用T串匹配S串
        /* 失配（S的第i位不能匹配T的pos + 1位），且pos不等于0就回到最近的前缀之后开始匹配（否则将进入无限循环）
         * e.g. S:  abaabaabbabaaabaabbabaab
         *          ^
         *      TB: abaabbabaab
         *          |    ^      此处a与b不匹配，失配
         *      TA: abaabbabaab
         *          | ^         回到最近的前缀开始匹配，因为我们已知前面是ab，所以不必再次对比
         *      NE: 01120123450
         */
        while(pos && S[i] != T[pos + 1]) pos = NE[pos];
        /* 如果当前位（S的第i位和T的pos + 1位）能匹配就继续
         * e.g. S:  abaabaabbabaaabaabbabaab
         *          ^
         *      TB: abaabbabaab
         *          | ^         匹配成功，因为我们可以得到前后缀匹配的串a
         *      TA: abaabbabaab
         *           |  ^       可以实现pos++和i++，就可以进行下一次匹配
         *      NE: 01120123450
         */
        if(S[i] == T[pos + 1]) pos++; // 扩大搜索范围
        if(pos == lenT) { // 搜索范围扩大在搜索范围到达最大的T串长度时结束，即此时整串匹配成功
            cout << i - lenT + 1 << endl; // i为S当前搜索到的长度，减去T的长度，即为T在S中出现的位置，因为此时i在S中T的末端
            pos = NE[pos]; // 从当前的S字符开始重新匹配，即寻找下一个T串
        }
    }
    for(int i = 1; i <= lenT; i++) cout << NE[i] << ' ';
    cout << endl;
    return 0;
}