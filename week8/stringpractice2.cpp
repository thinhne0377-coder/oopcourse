#include <iostream>
#include <string>

using namespace std;

// =====================================================
// BAI 1: INSERT A STRING
// =====================================================

void insertString()
{
    string originalString;
    string stringToInsert;
    int position;

    cout << "Nhap chuoi ban dau: ";
    getline(cin, originalString);

    cout << "Nhap chuoi can chen: ";
    getline(cin, stringToInsert);

    cout << "Nhap vi tri can chen: ";
    cin >> position;
    cin.ignore();

    // Kiem tra vi tri
    if (position < 0 || position > originalString.length())
    {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    originalString.insert(position, stringToInsert);

    cout << "Ket qua: " << originalString << endl;
}


// =====================================================
// BAI 2: FIND A SUBSTRING
// =====================================================

void findSubstring()
{
    string text;
    string substring;

    cout << "Nhap chuoi: ";
    getline(cin, text);

    cout << "Nhap chuoi con can tim: ";
    getline(cin, substring);

    size_t position = text.find(substring);

    if (position != string::npos)
    {
        cout << "Position: " << position << endl;
    }
    else
    {
        cout << "Substring does not exist." << endl;
    }
}


// =====================================================
// BAI 3: COUNT CHARACTERS
// =====================================================

void countCharacters()
{
    string text;

    cout << "Nhap chuoi: ";
    getline(cin, text);

    int countAll = text.length();
    int countWithoutSpaces = 0;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            countWithoutSpaces++;
        }
    }

    cout << "So ky tu (co ca khoang trang): "
         << countAll << endl;

    cout << "So ky tu (khong tinh khoang trang): "
         << countWithoutSpaces << endl;
}


// =====================================================
// BAI 4: REPLACE A SUBSTRING
// =====================================================

void replaceSubstring()
{
    string originalString;
    string substring;
    string newString;

    cout << "Nhap chuoi ban dau: ";
    getline(cin, originalString);

    cout << "Nhap chuoi can thay the: ";
    getline(cin, substring);

    cout << "Nhap chuoi moi: ";
    getline(cin, newString);

    size_t position = originalString.find(substring);

    if (position != string::npos)
    {
        originalString.replace(
            position,
            substring.length(),
            newString
        );

        cout << "Ket qua: " << originalString << endl;
    }
    else
    {
        cout << "Khong tim thay chuoi can thay the!" << endl;
    }
}


// =====================================================
// BAI 5: EXTRACT A SUBSTRING
// =====================================================

void extractSubstring()
{
    string text;
    int startPosition;
    int length;

    cout << "Nhap chuoi: ";
    getline(cin, text);

    cout << "Nhap vi tri bat dau: ";
    cin >> startPosition;

    cout << "Nhap do dai: ";
    cin >> length;
    cin.ignore();

    if (startPosition < 0 ||
        startPosition >= text.length() ||
        length < 0)
    {
        cout << "Vi tri hoac do dai khong hop le!" << endl;
        return;
    }

    string result = text.substr(startPosition, length);

    cout << "Ket qua: " << result << endl;
}


// =====================================================
// MAIN
// =====================================================

int main()
{
    int choice;

    do
    {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "       STRING OPERATIONS IN C++" << endl;
        cout << "==========================================" << endl;
        cout << "1. Insert a String" << endl;
        cout << "2. Find a Substring" << endl;
        cout << "3. Count Characters" << endl;
        cout << "4. Replace a Substring" << endl;
        cout << "5. Extract a Substring" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================================" << endl;

        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        cout << endl;

        switch (choice)
        {
            case 1:
                insertString();
                break;

            case 2:
                findSubstring();
                break;

            case 3:
                countCharacters();
                break;

            case 4:
                replaceSubstring();
                break;

            case 5:
                extractSubstring();
                break;

            case 0:
                cout << "Ket thuc chuong trinh!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 0);

    return 0;
}