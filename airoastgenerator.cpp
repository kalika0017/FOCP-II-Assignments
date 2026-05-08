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

    // Ask user for input
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Store roast templates
    vector<string> roasts = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} writes code so confusing that even AI gets scared.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s keyboard deserves a vacation after all those mistakes.",
        "{name} thinks copying from Stack Overflow is called research.",
        "{name}'s programs crash more often than free Wi-Fi.",
        "{name} writes comments like mystery novels — nobody understands them.",
        "{name}'s coding speed makes turtles look like race cars."
    };

    // Generate random index
    int randomIndex = rand() % roasts.size();

    // Get selected roast
    string selectedRoast = roasts[randomIndex];

    // Replace {name} placeholder
    size_t pos = selectedRoast.find("{name}");

    while (pos != string::npos) {
        selectedRoast.replace(pos, 6, name);
        pos = selectedRoast.find("{name}");
    }

    // Display roast
    cout << "\n🔥 Roast Generated:\n";
    cout << selectedRoast << endl;

    return 0;
}
