#include <iostream>
#include <string>

using namespace std;

// =====================================
// FUNCTION NHAP CAU
// =====================================
void inputSentence(string &sentence)
{
    cout << "Enter a sentence: ";
    getline(cin, sentence);
}

// =====================================
// FUNCTION HIEN THI DO DAI
// =====================================
void showLength(const string &sentence)
{
    cout << "Length: " << sentence.length() << endl;
}

// =====================================
// FUNCTION TIM VI TRI TU "C++"
// =====================================
size_t findWord(const string &sentence, const string &word)
{
    return sentence.find(word);
}

// =====================================
// FUNCTION LAY PHAN CHUOI
// =====================================
void showSubstring(const string &sentence, size_t position)
{
    cout << "Substring from that position: "
         << sentence.substr(position) << endl;
}

// =====================================
// FUNCTION THAY THE TU
// =====================================
void replaceWord(string &sentence,
                 size_t position,
                 const string &oldWord,
                 const string &newWord)
{
    sentence.replace(position, oldWord.length(), newWord);
}

// =====================================
// MAIN
// =====================================
int main()
{
    string sentence;

    // 1. Nhap cau
    inputSentence(sentence);

    // 2. Hien thi do dai
    cout << "\n===== STRING INFORMATION =====" << endl;

    showLength(sentence);

    // 3. Tim tu C++
    string word = "C++";

    size_t position = findWord(sentence, word);

    if (position != string::npos)
    {
        // Hien thi vi tri tim thay
        cout << "Found \"C++\" at position: "
             << position << endl;

        // 4. Trich xuat phan chuoi
        showSubstring(sentence, position);

        // 5. Thay C++ bang Programming
        replaceWord(sentence,
                    position,
                    "C++",
                    "Programming");

        // 6. Hien thi cau moi
        cout << "New sentence: "
             << sentence << endl;
    }
    else
    {
        cout << "\"C++\" not found." << endl;
    }

    cout << "==============================" << endl;

    return 0;
}