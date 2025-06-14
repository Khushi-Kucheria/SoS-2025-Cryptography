#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// Secret value to guess (like an HMAC, password, etc.)
string secret = "HELLO";

// Insecure comparison function
bool insecureCompare(string input) {
    for (size_t i = 0; i < secret.length(); ++i) {
        if (i >= input.length() || input[i] != secret[i])
            return false;
        this_thread::sleep_for(chrono::milliseconds(50));  // simulate timing leak
    }
    return input.length() == secret.length();
}

// Attacker simulation: guess one character at a time
string timingAttack() {
    string guessed = "";
    string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (size_t pos = 0; pos < secret.length(); ++pos) {
        char best_char = 'A';
        long long best_time = 0;

        for (char c : charset) {
            string attempt = guessed + c;
            auto start = high_resolution_clock::now();
            insecureCompare(attempt);
            auto end = high_resolution_clock::now();

            long long duration = duration_cast<microseconds>(end - start).count();

            if (duration > best_time) {
                best_time = duration;
                best_char = c;
            }
        }

        guessed += best_char;
        cout << "Guessed so far: " << guessed << " (delay: " << best_time << " μs)" << endl;
    }

    return guessed;
}

int main() {
    cout << "Starting Timing Attack Simulation...\n";
    string recovered = timingAttack();
    cout << "\nRecovered Secret: " << recovered << endl;
    return 0;
}
