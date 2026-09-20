#include <iostream>
#include <string>

using namespace std;

int main(){
    // Get length length() / size()
    string s = "Hello C++";
    cout << s.length() << endl;
    cout << s.size() << endl;

    // Check if empty()
    string s1 = "";
    string s2 = "Hi";
    cout << s1.empty() << endl;
    cout << s2.empty() << endl;

    // Find a Substring find()
    string text = "I love C++";
    size_t pos = text.find("C++");
    if (pos != string::npos){
        cout << "Found at: " << pos << endl;
    }
    else {
        cout << "Not found!" << endl;
    }
    
    // Get a Substring substr()
    string a = "Hello World";
    string part1 = a.substr(0, 5); // Hello
    string part2 = a.substr(6, 5); // World
    cout << part1 << endl;
    cout << part2 << endl;

    // Append Text append()
    string b = "Hello";
    b.append(" C++");
    cout << b << endl;

    // Insert Text insert()
    string c = "Hello World";
    c.insert(5, ", C++");   // after Hello
    cout << c << endl;

    // Erase characters erase()
    string d = "Hello World";
    d.erase (5, 6); // remove "World"
    cout << d << endl;

    // Replace Text replace()
    string e = "I like Java";
    s.replace (7, 4, "C++"); // Jave -> C++
    cout << e << endl;

    return 0;
}