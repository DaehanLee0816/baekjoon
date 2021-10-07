#include <iostream>
#include <vector>
#include <queue>

std::vector<int> DFS(std::vector<std::vector<int>> &map, std::queue<int> &sum_q,
         std::queue<std::vector<int>> &pos_q, int size, int tot_sum, int &ret) {

    int sum = sum_q.front();
    std::vector<int> pos = pos_q.front();
    if (pos.size() == size-1) {
        std::vector<int> ret_pos;

        int temp_ret = (tot_sum/2 - sum)*(sum - tot_sum/2);
        if (temp_ret == 0) {
            ret = 0;
            return pos;
        }
        
        if ((tot_sum/2 - sum) >= 0) {
            ret = tot_sum/2 - sum;
        } else {
            ret = sum - tot_sum/2;
        }
        
        for (int i = 0; i < pos.size(); i++) {
            ret_pos.push_back(pos[i]);
        }
        sum_q.pop();
        pos_q.pop();
        
        while (!sum_q.empty()) {
            
            int next_sum = sum_q.front();
            std::vector<int> next_pos = pos_q.front();
            int next_temp_ret = (tot_sum/2 - next_sum)*(next_sum - tot_sum/2);
            if (next_temp_ret < temp_ret) {
                if ((tot_sum/2 - sum) >= 0) {
                    ret = tot_sum/2 - next_sum;
                } else {
                    ret = next_sum - tot_sum/2;
                }
                
                ret_pos.clear();
                for (int i = 0; i < next_pos.size(); i++) {
                    ret_pos.push_back(next_pos[i]);
                }
            }
            sum_q.pop();
            pos_q.pop();
        }
        return ret_pos;
    }
    
    int temp_size = pos.size();
    while (temp_size == pos_q.front().size()) {
        for (int i = pos.back(); i < size; i++) {
            std::vector<int> next_vec(pos);
            int temp_sum = sum;
            int prev_pos = pos.back();
            temp_sum += map[size - i -1][pos_q.front().size()];
            next_vec.push_back(i);

            sum_q.push(temp_sum);
            pos_q.push(next_vec);
            sum_q.pop();
            pos_q.pop();
        }
    }
}

int main()
{
    int size;
    int tot = 0;
    std::vector<std::vector<int>> map;
    std::vector<int> ret_pos;
    std::vector<int> sum;
    int ret = 0;
    std::queue<std::vector<int>> pos_q;
    std::queue<int> sum_q;
    
    for (int i = 0; i < size; i++) {
        std::vector<int> i_th_row;
        for (int j = 0; j < size; j++) {
            int elem;
            std::cin >> elem;
            tot += elem;
            i_th_row.push_back(elem);
        }
        map.push_back(i_th_row);
    }
    
    for (int i = 0; i < size; i++) {
        std::vector<int> init;
        int sum = map[i][0];
        init.push_back(i+1);
        pos_q.push(init);
        sum_q.push(sum);
    }
    
    ret_pos = DFS(map, sum_q, pos_q, size, tot, ret);
    
    std::cout << ret << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << ret_pos[i];
    }
    
    return 0;
}