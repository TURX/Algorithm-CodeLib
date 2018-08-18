#include <iostream>
#include <cmath>
using namespace std;

// int pointer;
bool nopr[10000003];
unsigned long long prime[10000003], N, M, Q;
int cnt;

inline bool isPrime(unsigned long long x)//判断素数的函数
{   
     int k=sqrt(x);  
    for(int i=2;i<=k;i++)    
    {       
        if(x%i==0)  
        return 1;  
    }    //判断素数的一个方法，n相继模从2到n的开方，若余数为0则不为素数，反之为素数
    return 0;  
}

/*
inline void init()
{
    bool nopr[10000000];
    for (int i = 2; i <= sqrt(N) + 1; i++)
    {
        if (!nopr[i])
        {
            for (int j = i * 2; j <= N; j += i)
                nopr[j] = 1;
        }
    }
}
*/
/*
inline void euler_sieve(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!nopr[i])
            prime[cnt++] = i;
        for (int j = 0; i * prime[j] <= n; ++j)
        {
            nopr[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    //euler_sieve(N);
    /*
    for(int i = 2; i; i++) {
        if(!nopr[i]) prime[++pointer] = i;
        for(int j = 1; j <= pointer && i * prime[j] <= N; j++) {
            nopr[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    for()
    */
    for (int t = 0; t < M; t++)
    {
        cin >> Q;
        if(Q == 1) {
            cout << "No" << endl;
            continue;
        }
        if(isPrime(Q)) {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
        /*
        if (Q == 2)
            cout << "Yes" << endl;
        else if (!(Q % 2) || Q < 2)
            cout << "No" << endl;
        else
        {
            if (nopr[(Q - 3) / 2])
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
        */
       //if(!nopr[Q]) cout << "Yes" << endl; else cout << "No" << endl;
    }
    return 0;
}