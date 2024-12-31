#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Calculate the number of 'V' and 'I'
    int num_v = n / 5;  // One 'V' every 5 days
    int num_i = n % 5;  // Remaining 'I's

    // Construct the output
    string result(num_v, 'V'); // Add 'V's
    result.append(num_i, 'I'); // Add remaining 'I's

    // Print the result
    cout << result << endl;

    return 0;
}
