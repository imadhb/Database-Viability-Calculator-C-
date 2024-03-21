#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Factor {
    string name;
    double weight;
    double rating;
};

double calculateFeasibilityScore(const vector<Factor>& factors) {
    double totalWeight = 0.0;
    double weightedSum = 0.0;

    for (const auto& factor : factors) {
        totalWeight += factor.weight;
        weightedSum += factor.rating * factor.weight;
    }

    return (weightedSum / totalWeight);
}

double getUserInput(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
    }
    return input;
}

void displayFactors(const vector<Factor>& factors) {
    cout << "Factors affecting feasibility:" << endl;
    for (const auto& factor : factors) {
        cout << "- " << factor.name << " (Weight: " << factor.weight << ")" << endl;
    }
}

int main() {
    vector<Factor> factors = {
        {"Cost", 0.2, 0.0},
        {"Regulations", 0.1, 0.0},
        {"Scalability", 0.3, 0.0},
        {"Security", 0.25, 0.0},
        {"Workforce", 0.15, 0.0}
    };

    displayFactors(factors);

    for (auto& factor : factors) {
        factor.rating = getUserInput("Enter rating for " + factor.name + ": ");
    }

    cout << endl << "Factors with ratings:" << endl;
    for (const auto& factor : factors) {
        cout << "- " << factor.name << ": " << factor.rating << endl;
    }

    double feasibilityScore = calculateFeasibilityScore(factors);
    cout << endl << "Feasibility Score: " << feasibilityScore << endl;

    return 0;
}
