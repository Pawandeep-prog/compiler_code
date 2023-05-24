#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNonTerminal(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool isContextFreeGrammar(const vector<string>& productions) {
    for (const string& production : productions) {
        char nonTerminal = production[0];
        if (!isNonTerminal(nonTerminal)) {
            cout << "Invalid grammar. LHS of production is not a non-terminal." << endl;
            return false;
        }

        if (production.length() < 4 || production[1] != '-' || production[2] != '>') {
            cout << "Invalid grammar. Incorrect production format: " << production << endl;
            return false;
        }

        for (size_t i = 3; i < production.length(); i++) {
            char symbol = production[i];
            if (!isNonTerminal(symbol) && !isalpha(symbol) && !isspace(symbol)) {
                cout << "Invalid grammar. Invalid symbol: " << symbol << endl;
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<string> productions;
    string input;
    cout << "Enter the grammar productions (one per line), 'done' to finish:" << endl;

    while (true) {
        cin>>input;

        if (input == "done") {
            break;
        }

        productions.push_back(input);
    }

    bool isCFG = isContextFreeGrammar(productions);
    if (isCFG) {
        cout << "The given grammar is a context-free grammar." << endl;
    } else {
        cout << "The given grammar is not a context-free grammar." << endl;
    }

    return 0;
}
