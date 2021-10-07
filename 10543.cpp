#include <iostream>
#include <vector>
#include <stdio.h>

inline long long Sum (int N) {
    return (long long)N*(N+1)/2;
}

long long Calcul(int N, int divide) {
    int Remainder = N%(divide+1);
    int Quot = N/(divide+1);
    return ((divide+1-Remainder)*Sum(Quot) + (Remainder)*Sum(Quot+1));
}

void find_next(std::vector<int> &NumStudInBuild, std::vector<long long> &m_th_dp, int& NumMov, int &cnt, long long &ret) {
    if (cnt > NumStudInBuild.size()) {
        ret = m_th_dp[NumMov];
        return;
    }

    std::vector<long long> next_dp;

    for (int i = 0; i <= NumMov; i++) {
        long long i_th_ret = m_th_dp[i] + Calcul(NumStudInBuild[cnt], 0);
        for (int j = 0; j <= i; j++) {
            i_th_ret = std::min(i_th_ret, m_th_dp[i - j] + Calcul(NumStudInBuild[cnt], j));
        }
        next_dp.push_back(i_th_ret); 
    }
    m_th_dp.clear();
    cnt++;
    find_next(NumStudInBuild, next_dp, NumMov, cnt, ret);
}

int main()
{
    int NumStud, NumBuild, NumMov;
    scanf("%d %d %d", &NumStud, &NumBuild, &NumMov);
    long long ret = 0;
    std::vector<int> NumStudInBuild;
    NumStudInBuild.assign(NumBuild, 0);
    for (int i = 0; i < NumStud; i++) {
        int MovBuildNum;
        scanf("%d", &MovBuildNum);
        ++NumStudInBuild[MovBuildNum-1];
    }

    std::vector<long long> m_th_dp;
    for (int i = 0; i <= NumMov; i++) {
        m_th_dp.push_back(Calcul(NumStudInBuild[0], i));
    }
    
    int cnt = 1;
    find_next(NumStudInBuild, m_th_dp, NumMov, cnt, ret);
    printf("%lld\n", ret);
    return 0;
}