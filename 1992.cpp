#include <iostream>
#include <vector>
using namespace std;

void CheckNode(vector<string> &map, string &ret, int x_start, int x_end, int y_start, int y_end) {
    if (x_start == x_end) {
        return;
    }
    char first = map[y_start][x_start];
    bool homogeneous = true;
    for (int i = x_start; i < x_end; i++) {
        for (int j = y_start; j < y_end; j++) {
            if (map[j][i] != first) {
                homogeneous = false;
                break;
            }
        }
        if (homogeneous == false) {
            break;
        }
    }
    
    if (homogeneous == true) {
        ret.push_back(first);
    } else {
        ret.push_back('(');
        CheckNode(map, ret, x_start, (x_start+x_end)/2, y_start, (y_start+y_end)/2);
        CheckNode(map, ret, (x_start+x_end)/2, x_end, y_start, (y_start+y_end)/2);
        CheckNode(map, ret, x_start, (x_start+x_end)/2, (y_start+y_end)/2, y_end);
        CheckNode(map, ret, (x_start+x_end)/2, x_end, (y_start+y_end)/2, y_end);
        ret.push_back(')');
    }
}


int main()
{
    int size;
    cin >> size;
    vector<string> map;
    string ret;
    cin.ignore();
    for (int i = 0; i < size; i++) {
        string i_th_row;
        getline(cin, i_th_row);
        map.push_back(i_th_row);
    }

    CheckNode(map, ret, 0, size, 0, size);

    cout << ret;
    return 0;
}