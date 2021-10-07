#include <iostream>
#include <vector>
#include <algorithm>

int CandNum, RecommendNum;

int main() {
    scanf("%d", &CandNum);
    scanf("%d", &RecommendNum);

    int Recommend[101] = { 0 };
    std::vector<int> Cand; 
    for (int i = 0; i < RecommendNum; i++) {
        int i_th_recommend;
        scanf("%d", &i_th_recommend);

        if (Cand.size() < CandNum && Recommend[i_th_recommend] == 0) {
            Cand.push_back(i_th_recommend);
            Recommend[i_th_recommend]++;
            continue;
        }

        bool is_found = false;
        for (int j = 0; j < Cand.size(); j++) {
            if (Cand[j] == i_th_recommend) {
                Recommend[i_th_recommend]++;
                is_found = true;
                break;
            }
        }

        if (is_found) {
            continue;
        }

        int del = Cand[0];
        int del_idx = 0;
        for (int j=0; j < Cand.size(); j++) {
            if (Recommend[del] > Recommend[Cand[j]]) {
                del = Cand[j];
                del_idx = j;
            }
        }
        Recommend[del] = 0;
        for (int j = del_idx + 1; j < Cand.size(); j++) {
            Cand[j-1] = Cand[j];
        }
        Cand.back() = i_th_recommend;
        Recommend[i_th_recommend]++;
    }

    std::sort(Cand.begin(), Cand.end());
    for (int i = 0; i < Cand.size(); i++) {
        printf("%d ", Cand[i]);
    }

    return 0;
}