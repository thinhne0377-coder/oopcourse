#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// =====================================================
// BAI 1: STUDENT PROFILE
// =====================================================

void inputStudent(string &fullName, string &studentID,
                  string &email, string &hometown)
{
    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Enter student ID: ";
    getline(cin, studentID);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter hometown: ";
    getline(cin, hometown);
}

void outputStudent(string fullName, string studentID,
                   string email, string hometown)
{
    cout << "\n===== STUDENT PROFILE =====" << endl;
    cout << "Full name  : " << fullName << endl;
    cout << "Student ID : " << studentID << endl;
    cout << "Email      : " << email << endl;
    cout << "Hometown   : " << hometown << endl;
    cout << "===========================" << endl;
}

void bai1()
{
    string fullName;
    string studentID;
    string email;
    string hometown;

    inputStudent(fullName, studentID, email, hometown);
    outputStudent(fullName, studentID, email, hometown);
}


// =====================================================
// BAI 2: GREETING MESSAGE
// =====================================================

string createGreeting(string name)
{
    string message;

    message = "Hello, " + name + "!\n";
    message += "Welcome to C++ programming!";

    return message;
}

void bai2()
{
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\n" << createGreeting(name) << endl;
}


// =====================================================
// BAI 3: INITIALS
// =====================================================

string getInitials(string fullName)
{
    string initials;

    // Tim ky tu dau tien khac dau cach
    int i = 0;

    while (i < fullName.length() && fullName[i] == ' ')
    {
        i++;
    }

    if (i < fullName.length())
    {
        initials += toupper(fullName[i]);
    }

    // Tim chu cai dau cua cac tu tiep theo
    for (; i < fullName.length(); i++)
    {
        if (fullName[i] == ' ')
        {
            int j = i + 1;

            while (j < fullName.length() && fullName[j] == ' ')
            {
                j++;
            }

            if (j < fullName.length())
            {
                initials += '.';
                initials += toupper(fullName[j]);
            }

            i = j - 1;
        }
    }

    return initials;
}

void bai3()
{
    string fullName;

    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Initials: " << getInitials(fullName) << endl;
}


// =====================================================
// BAI 4: FIND A WORD
// =====================================================

void findWord(string sentence, string word)
{
    size_t position = sentence.find(word);

    if (position != string::npos)
    {
        cout << "The word \"" << word
             << "\" is found at position "
             << position << "." << endl;
    }
    else
    {
        cout << "The word \"" << word
             << "\" is not found." << endl;
    }
}

void bai4()
{
    string sentence;
    string word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Enter a word to find: ";
    getline(cin, word);

    findWord(sentence, word);
}


// =====================================================
// BAI 5: CREATE A USERNAME
// =====================================================

string createUsername(string fullName, int birthYear)
{
    string username;

    // Xoa dau cach va chuyen thanh chu thuong
    for (int i = 0; i < fullName.length(); i++)
    {
        if (fullName[i] != ' ')
        {
            username += tolower(fullName[i]);
        }
    }

    // Them nam sinh vao username
    username += to_string(birthYear);

    return username;
}

void bai5()
{
    string fullName;
    int birthYear;

    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Enter birth year: ";
    cin >> birthYear;

    cout << "Username: "
         << createUsername(fullName, birthYear)
         << endl;
}


// =====================================================
// MAIN
// =====================================================

int main()
{
    int choice;

    do
    {
        cout << "\n========================================" << endl;
        cout << "       PRACTICE EXERCISES WITH STRING" << endl;
        cout << "========================================" << endl;
        cout << "1. Student Profile" << endl;
        cout << "2. Greeting Message" << endl;
        cout << "3. Initials" << endl;
        cout << "4. Find a Word" << endl;
        cout << "5. Create a Username" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        cout << endl;

        switch (choice)
        {
            case 1:
                bai1();
                break;

            case 2:
                bai2();
                break;

            case 3:
                bai3();
                break;

            case 4:
                bai4();
                break;

            case 5:
                bai5();
                break;

            case 0:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}