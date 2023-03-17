#include <iostream>
#include <string>
#include <map>

using namespace std;

int romanToNum(string s) {
    map<char, int> roman_map;
    roman_map.insert(make_pair('I', 1));
    roman_map.insert(make_pair('V', 5));
    roman_map.insert(make_pair('X', 10));
    roman_map.insert(make_pair('L', 50));
    roman_map.insert(make_pair('C', 100));
    roman_map.insert(make_pair('D', 500));
    roman_map.insert(make_pair('M', 1000));
    
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i > 0 && roman_map[s[i]] > roman_map[s[i - 1]]) {
            result += roman_map[s[i]] - 2 * roman_map[s[i - 1]];
        } else {
            result += roman_map[s[i]];
        }
    }
    return result;
}

string numToRoman(int num) {
    string roman = "";
    map<int, string> roman_map;
    roman_map.insert(make_pair(1000, "M"));
    roman_map.insert(make_pair(900, "CM"));
    roman_map.insert(make_pair(500, "D"));
    roman_map.insert(make_pair(400, "CD"));
    roman_map.insert(make_pair(100, "C"));
    roman_map.insert(make_pair(90, "XC"));
    roman_map.insert(make_pair(50, "L"));
    roman_map.insert(make_pair(40, "XL"));
    roman_map.insert(make_pair(10, "X"));
    roman_map.insert(make_pair(9, "IX"));
    roman_map.insert(make_pair(5, "V"));
    roman_map.insert(make_pair(4, "IV"));
    roman_map.insert(make_pair(1, "I"));
    
    for (map<int, string>::reverse_iterator it = roman_map.rbegin(); it != roman_map.rend(); it++) {
        while (num >= it->first) {
            roman += it->second;
            num -= it->first;
        }
    }
    return roman;
}

int main() {
    string input;
    int num;
    do {
        cout << "Enter Roman numeral or integer: ";
        cin >> input;
        if (isdigit(input[0])) {
            num = stoi(input);
            if (num < 1 || num > 3999) {
                cout << "Invalid input: please enter an integer between 1 and 3999." << endl;
                continue;
            }
            string roman = numToRoman(num);
            cout << roman << endl;
        } else {
            num = romanToNum(input);
            if (num == 0) {
                cout << "Invalid input: please enter a valid Roman numeral or integer." << endl;
                continue;
            }
            cout << num << endl;
        }
    } while (num < 1 || num > 3999 || input.empty());
    return 0;
}