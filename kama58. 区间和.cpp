#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // 读取数组
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    // 预处理前缀和数组
    std::vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + array[i - 1];
    }

    // 处理每个区间
    int a, b;
    while (std::cin >> a >> b) {
        int total_sum = prefix_sum[b + 1] - prefix_sum[a];
        std::cout << total_sum << std::endl;
    }

    return 0;
}