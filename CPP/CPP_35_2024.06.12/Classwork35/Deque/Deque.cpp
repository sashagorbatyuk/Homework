#include <iostream>
#include <deque>
#include <string>
using namespace std;

void displayHistory(const deque<string>& history) {
    if (history.empty()) {
        cout << "History is empty. \n";
        return;
    }
    cout << "Browser History: \n";
    for (const string& url : history) {
        cout << url << "\n";
    }
}

int main() {
    deque<string> browserHistory;
    deque<string> forwardStack; // Для функції "Вперед"
    int choice;

    do {
        cout << "\n1. Visit URL \n"
            << "2. Back \n"
            << "3. Forward \n"
            << "4. Display History \n"
            << "5. Clear History \n"
            << "6. Delete by Index \n"
            << "7. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string url;
            cout << "Enter URL: ";
            cin.ignore();
            getline(cin, url);
            browserHistory.push_back(url);
            forwardStack.clear(); // Очистити стек "вперед", коли відвідано нову сторінку
            cout << "Visited: " << url << "\n";
            break;
        }
        case 2: {
            if (browserHistory.size() > 1) {
                forwardStack.push_front(browserHistory.back());
                browserHistory.pop_back();
                cout << "Back to: " << browserHistory.back() << "\n";
            }
            else {
                cout << "No previous pages. \n";
            }
            break;
        }
        case 3: {
            if (!forwardStack.empty()) {
                browserHistory.push_back(forwardStack.front());
                forwardStack.pop_front();
                cout << "Forward to: " << browserHistory.back() << "\n";
            }
            else {
                cout << "No forward pages. \n";
            }
            break;
        }
        case 4:
            displayHistory(browserHistory);
            break;
        case 5:
            browserHistory.clear();
            forwardStack.clear();
            cout << "History cleared. \n";
            break;
        case 6: {
            if (!browserHistory.empty()) {
                int index;
                displayHistory(browserHistory);
                cout << "Enter index to delete : ";
                cin >> index;
                if (index >= 0 && index < browserHistory.size()) {
                    auto it = browserHistory.begin();
                    advance(it, index);
                    browserHistory.erase(it);
                    cout << "Entry deleted. \n";
                }
                else {
                    cout << "Invalid index. \n";
                }
            }
            else {
                cout << "History is empty. \n";
            }
            break;
        }
        case 7:
            cout << "Exiting... \n";
            break;
        default:
            cout << "Invalid choice. \n";
        }
    } while (choice != 7);

    return 0;
}