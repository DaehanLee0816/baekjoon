#include <iostream>
#include <vector>

void check(char *op, int &M, bool *is_contained, std::vector<bool> &count_check) {
    if (op[0] == 'a') {
        is_contained[M-1] = true;
    } else if (op[0] == 'r') {
        is_contained[M-1] = false;
    } else if (op[0] == 'c') {
        if (is_contained[M-1] == true) {
            count_check.push_back(true);
        } else if (is_contained[M-1] == false) {
            count_check.push_back(false);
        }
    } else {
        if (is_contained[M-1] == true) {
            is_contained[M-1] = false;
        } else if (is_contained[M-1] == false) {
            is_contained[M-1] = true;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    
    bool is_contained[20] = { false };
    std::vector<bool> count_check;
    
    for (int n = 0; n < N; n++) {
        char op[7];
        scanf("%s", op);
        if (op[0] == 'a' && op[1] == 'l') {
            for (int i = 0; i < 20; i++) {
                is_contained[i] = true;
            }
        } else if (op[0] == 'e') {
            for (int i = 0; i < 20; i++) {
                is_contained[i] = false;
            }
        } else {
            int M;
            scanf("%d", &M);
            check(op, M, is_contained, count_check);
        }
    }
    
    for (int i = 0; i < count_check.size(); i++) {
        if (count_check[i] == true) {
            printf("%d\n",1); 
        } else {
            printf("%d\n",0); 
        }
    }
    
    return 0;
}