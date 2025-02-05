#include <iostream>
#include <vector>

int main() {
    int n, A;
    std::cin >> n >> A;
    std::vector<int> receipts(n);
    int total_tickets = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> receipts[i];
        total_tickets += receipts[i] / A;
    }

    std::cout << total_tickets << std::endl;
    return 0;
}
