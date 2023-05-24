#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<char, unordered_set<char>> first;
unordered_map<char, unordered_set<char>> follow;
unordered_map<char, vector<string>> rules;
vector<vector<string>> parseTable;

void computeFirst(const char var, const unordered_map<char, vector<string>>& rules) {
    if (first.count(var) > 0) {
        return;  // First set already computed for the variable
    }

    for (const string& rule : rules.at(var)) {
        char symbol = rule[0];

        if (isupper(symbol)) {
            computeFirst(symbol, rules);
            const unordered_set<char>& symbolFirst = first.at(symbol);
            first[var].insert(symbolFirst.begin(), symbolFirst.end());
        } else {
            first[var].insert(symbol);
        }
    }
}

void computeFollow(const char var, const unordered_map<char, vector<string>>& rules) {
    if (follow.count(var) > 0) {
        return;  // Follow set already computed for the variable
    }

    if (var == rules.begin()->first) {
        follow[var].insert('$');
    }

    for (const auto& rulePair : rules) {
        const char lhs = rulePair.first;
        const vector<string>& ruleList = rulePair.second;

        for (const string& rule : ruleList) {
            const int ruleLen = rule.length();
            for (int i = 0; i < ruleLen; i++) {
                if (rule[i] == var) {
                    if (i < ruleLen - 1) {
                        char nextSymbol = rule[i + 1];

                        if (isupper(nextSymbol)) {
                            follow[var].insert(first[nextSymbol].begin(), first[nextSymbol].end());

                            if (first[nextSymbol].find('#') != first[nextSymbol].end()) {
                                follow[var].erase('#');
                                computeFollow(lhs, rules);
                                follow[var].insert(follow[lhs].begin(), follow[lhs].end());
                            }
                        } else {
                            follow[var].insert(nextSymbol);
                        }
                    } else {
                        computeFollow(lhs, rules);
                        follow[var].insert(follow[lhs].begin(), follow[lhs].end());
                    }
                }
            }
        }
    }
}

string toString(char c){
    return string()+c;
}

void computeParseTable(){
    vector<string> tmp;
    string first_="";
    for(auto& [var, rule_]: rules){
        for(auto& rule: rule_){

            first_ = "";
            if(rule[0]>='a' && rule[0]<='z') first_=rule[0];
            else for(auto& i: first[rule[0]]){
                first_ += (toString(i)+", ");
            }
            
            tmp.push_back(toString(var));
            tmp.push_back(first_);
            tmp.push_back(toString(var)+"->"+rule);

            parseTable.push_back(tmp);
            tmp.clear();
        }
    }
}

void printRules(){
    for(auto& [var, rule]: rules){
        std::cout<<var<<"\t"<<rule[0]<<"\n";
    }
}

void printParseTable(){
    std::cout<<"variable\tnon_term\t\trule\n";
    for(auto& i: parseTable){
        std::cout<<i[0]<<"\t\t"<<i[1]<<"\t\t"<<i[2]<<std::endl;
    }
}


int main() {
    int ruleCount;

    cout << "Enter the number of production rules: ";
    cin >> ruleCount;

    cout << "Enter the production rules:" << endl;

    for (int i = 0; i < ruleCount; i++) {
        string rule;
        cin >> rule;

        char lhs = rule[0];
        string rhs = rule.substr(2);

        rules[lhs].push_back(rhs);
    }

    for (const auto& rulePair : rules) {
        char var = rulePair.first;
        computeFirst(var, rules);
        computeFollow(var, rules);
    }

    printFirstAndFollowSets();

    std::cout<<"\n";

    computeParseTable();
    printParseTable();

    return 0;
}

