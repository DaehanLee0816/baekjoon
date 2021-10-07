#include <iostream>
#include <vector>
static int NumBall = 3;

void divide(int N, int *ret) {
    ret[0] = N/100;
    N -= 100*ret[0];
    ret[1] = N/10;
    N -= 10*ret[1];
    ret[2] = N;
}

int ret_strike(int *divided, std::vector<int> &cand) {
    int num_strikes=0;
    for (int i = 0; i < NumBall; i++) {
        if (divided[i] == cand[i])
            num_strikes++;
    }
    return num_strikes;
}

int ret_ball(int *divide, std::vector<int> &cand) {
    int num_balls = 0;
    for (int i = 0; i < NumBall; i++) {
        for (int j = 0; j < NumBall; j++) {
            if (divide[i] == cand[j] && i!=j) {
                num_balls++;
                break;
            }
        }
    }
    return num_balls;
}

void check(std::vector<std::vector<int>> &cand_vec, int shot, int strike, int ball) {
    int three_shot[3];
    divide(shot, three_shot);

    for (int i = 0; i < cand_vec.size(); i++) {
        std::vector<int> cand = cand_vec[i];
        int num_strike = ret_strike(three_shot, cand);
        int num_ball = ret_ball(three_shot, cand);
        if (strike != num_strike || ball != num_ball) {
            cand_vec.erase(cand_vec.begin() + i);
            i--;
        }
    }
}

int main() {
    int cnt;
    scanf("%d", &cnt);
    int shot[cnt], strike[cnt], ball[cnt];
    std::vector<std::vector<int>> all_nums;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                std::vector<int> i_th_ret;
                i_th_ret.push_back(i);
                i_th_ret.push_back(j);
                i_th_ret.push_back(k);
                all_nums.push_back(i_th_ret);
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        scanf("%d %d %d", &shot[i], &strike[i], &ball[i]);
        check(all_nums, shot[i], strike[i], ball[i]);
    }

    printf("%d", all_nums.size());
    return 0;
}