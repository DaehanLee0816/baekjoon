#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void sort_orders (vector<string> &orders) {
    for (int i = 0; i < orders.size(); i++) {
        string &str = orders[i];
        sort(str.begin(), str.end());
    }
}

vector<string> find_subset(string &i_th_order, int course_len) {
    vector<string> ret;
    if (ret.empty()) {
        for (int i = 0; i < i_th_order.size(); i++) {
            string str;
            str.push_back(i_th_order[i]);
            ret.push_back(str);
        }
    }
    
    while (ret.front().size() < course_len) {
        vector<bool> used_menu;
        used_menu.assign(i_th_order.size(), false);
        string menu = ret[0];
        for (int i = 0; i < menu.size(); i++) {
            for (int j = 0; j < i_th_order.size(); j++) {
                if (menu[i] == i_th_order[j]) {
                    used_menu[j] = true;
                    break;
                }
            }
        }
        int count_menu_elem = 0;
        for (int i = 0; i < i_th_order.size(); i++) {
            if (used_menu[i] == true) {
                count_menu_elem++;
                continue;
            }
            
            if (used_menu[i] == false && count_menu_elem >= menu.size()) {
                menu.push_back(i_th_order[i]);
                ret.push_back(menu);
                menu.pop_back();
                used_menu[i] = true;
            }
        }
        ret.erase(ret.begin());
    }
    
    return ret;
}

void make_sub_course(string &i_th_order, int course_len, vector<string> &ret, vector<int> &cnt) {
    if (i_th_order.size() < course_len) {
        return;
    }
    
    vector<string> subset = find_subset(i_th_order, course_len);
    
    int ret_len = ret.size();
    if (ret_len == 0) {
        for (int i = 0; i < subset.size(); i++) {
            ret.push_back(subset[i]);
            cnt.push_back(1);
        }
        return;
    }
    
    
    for (int i = 0; i < subset.size(); i++) {
        for (int j = 0; j < ret_len; j++ ) {
            if (subset[i] == ret[j]) {
                cnt[j]++;
                break;
            }
            
            if (j == ret_len - 1 && subset[i] != ret[j]) {
                ret.push_back(subset[i]);
                cnt.push_back(1);
            }
        }
    }
    
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    sort_orders(orders);
    
    for (int i = 0; i < course.size(); i++) {
        int course_len = course[i];
        vector<string> i_th_subset;
        vector<int> i_th_cnt;
        for (int j = 0; j < orders.size(); j++) {
            string order = orders[j];
            make_sub_course(order, course_len, i_th_subset, i_th_cnt);
        }
        int ans_course_cnt = 0;
        for (int j = 0; j < i_th_subset.size(); j++) {
            if (ans_course_cnt < i_th_cnt[j]) {
                ans_course_cnt = i_th_cnt[j];
            }
        }
        
        for (int j = 0; j < i_th_subset.size(); j++) {
            if (i_th_cnt[j] == ans_course_cnt && ans_course_cnt > 1) {
                answer.push_back(i_th_subset[j]);
            }
        }
    
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> orders;
    vector<int> course;
    int n, m;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string i_th_order;
        getline(cin, i_th_order);
        orders.push_back(i_th_order);
    }

    for (int i = 0; i < m; i++) {
        int course_len;
        cin >> course_len;
        course.push_back(course_len);
    }
    vector<string> ans;
    ans = solution(orders, course);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}