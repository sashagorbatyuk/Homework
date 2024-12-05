#include <iostream>
#include <list>
#include <numeric> // для std::accumulate
#include <algorithm> // для std::sort
using namespace std;

void displayList(const list<int>& scores) {
    if (scores.empty()) {
        cout << "No scores available. \n";
        return;
    }
    cout << "Scores: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << "\n";
}

int main() {
    list<int> scores;
    int choice;
    do {
        cout << "\n1. Add score \n"
            << "2. Remove lowest score \n"
            << "3. Calculate average \n"
            << "4. Display scores \n"
            << "5. Sort scores \n"
            << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int score;
            cout << "Enter score: ";
            cin >> score;
            scores.push_back(score);
            break;
        }
        case 2: {
            if (!scores.empty()) {
                scores.remove(*min_element(scores.begin(), scores.end()));
                cout << "Lowest score removed. \n";
            }
            else {
                cout << "No scores to remove. \n";
            }
            break;
        }
        case 3: {
            if (!scores.empty()) {
                double average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
                cout << "Average score: " << average << "\n";
            }
            else {
                cout << "No scores to calculate average. \n";
            }
            break;
        }
        case 4: {
            displayList(scores);
            cout << "Reverse order: ";
            for (auto it = scores.rbegin(); it != scores.rend(); ++it) {
                cout << *it << " ";
            }
            cout << "\n";
            break;
        }
        case 5: {
            scores.sort();
            cout << "Scores sorted in ascending order. \n";
            displayList(scores);
            break;
        }
        case 6:
            cout << "Exiting... \n";
            break;
        default:
            cout << "Invalid choice. \n";
        }
    } while (choice != 6);
    return 0;
}