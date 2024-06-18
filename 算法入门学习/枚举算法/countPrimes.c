#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <string.h>
/*
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
循环 n次
定义一个值 等于n
每次循环减一 并且和n相余 为0 则break
*/
bool isPrime(int x)
{
    for (int j = 2; j < x - 1; j++)
    {
        if (x % j == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes_1(int n)
{
    int count = 0;
    for (int i = 2; i < n; ++i)
    {
        count += isPrime(i);
    }
    return count;
}

int countPrimes_2(int n)
{
    if (n < 2)
    {
        return 0;
    }
    int isPrime[n];
    memset(isPrime, 0, sizeof(isPrime));
    int ans = 0;
    for (int i = 2; i < n; ++i)
    {
        if (!isPrime[i])
        {
            ans += 1;
            if ((long long)i * i < n)
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = 1;
                }
            }
        }
    }
    return ans;
}

int countPrimes_3(int n)
{
    if (n < 2)
    {
        return 0;
    }
    int isPrime[n];
    int primes[n], primesSize = 0;
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 2; i < n; ++i)
    {
        if (!isPrime[i])
        {
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && i * primes[j] < n; ++j)
        {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
    return primesSize;
}

int main()
{

    struct timeval start, end;
    long seconds, useconds;
    double mtime;

    gettimeofday(&start, NULL);

    int result = countPrimes_3(999999);
    printf("质数个数:%d\n", result);

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0);

    printf("程序运行时间: %f 毫秒\n", mtime);
    return 0;
}