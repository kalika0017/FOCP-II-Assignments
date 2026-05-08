#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // Seed random number generator
    srand(time(0));

    string name;

    // Take student name input
    cout << "Enter student name: ";
    getline(cin, name);

    // Check empty input
    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 0;
    }

    // Store excuse templates
    vector<string> excuses = {

        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",

        "{name} tried finishing the homework, but the internet stopped working.",

        "{name} was ready to submit the assignment when the file mysteriously disappeared.",

        "{name} accidentally deleted the assignment before saving it.",

        "{name}'s computer froze during the final submission.",

        "{name} thought the deadline was tomorrow instead of today.",

        "{name}'s keyboard stopped working right before submission.",

        "{name} spent hours fixing software errors instead of completing homework.",

        "{name}'s Wi-Fi disconnected exactly when the assignment was about to upload.",

        "{name}'s system restarted automatically during the assignment.",

        "{name} tried to finish the assignment, but the power suddenly went out.",

        "{name}'s pet walked on the keyboard and closed the project file."
    };

    // Randomly select an excuse
    int randomIndex = rand() % excuses.size();

    string selectedExcuse = excuses[randomIndex];

    // Replace {name} placeholder with actual name
    size_t pos = selectedExcuse.find("{name}");

    while (pos != string::npos) {
        selectedExcuse.replace(pos, 6, name);
        pos = selectedExcuse.find("{name}");
    }

    // Display final excuse
    cout << "\nGenerated Excuse:\n";
    cout << selectedExcuse << endl;

    return 0;
}