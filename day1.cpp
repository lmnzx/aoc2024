#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(void) {
    std::ifstream f("inputs/day1.txt");
    std::string s;

    std::vector<int> left, right;

    std::map<int, int> m;

    unsigned long sum = 0;

    while (std::getline(f, s)) {
        left.push_back(std::stoi(s.substr(0, 5)));
        right.push_back(std::stoi(s.substr(8, 13)));
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++) {
        if (m.find(right[i]) == m.end()) {
            m[right[i]] = 1;
        } else {
            m[right[i]]++;
        }
    }

    for (int i = 0; i < left.size(); i++) {
        if (m.find(left[i]) != m.end()) {
            sum += left[i] * m.find(left[i])->second;
        }
    }

    std::cout << sum << "\n";

    return 0;
}
