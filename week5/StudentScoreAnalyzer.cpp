#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // =====================================
    // NHAP SO LUONG HOC SINH
    // =====================================

    int N;

    do {
        cout << "Nhap so luong hoc sinh: ";
        cin >> N;

        if (N < 2 || N > 20) {
            cout << "So luong khong hop le! "
                 << "Vui long nhap tu 2 den 20.\n";
        }

    } while (N < 2 || N > 20);


    // =====================================
    // NHAP DIEM
    // =====================================

    double scores[20];

    for (int i = 0; i < N; i++) {

        do {
            cout << "Nhap diem cho hoc sinh "
                 << i + 1 << ": ";

            cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Diem khong hop le! "
                     << "Vui long nhap tu 0 den 10.\n";
            }

        } while (scores[i] < 0 || scores[i] > 10);
    }


    // =====================================
    // 1. COUNT EXCELLENT STUDENTS
    // =====================================

    int excellentCount = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] >= 9.0) {
            excellentCount++;
        }
    }

    cout << "\n===== 1. COUNT EXCELLENT =====\n";

    cout << "Number of excellent students: "
         << excellentCount
         << endl;


    // =====================================
    // 2. COUNT STUDENTS IN SCORE RANGE
    // =====================================

    double a, b;

    cout << "\n===== 2. SCORE RANGE =====\n";

    cout << "Enter minimum score: ";
    cin >> a;

    cout << "Enter maximum score: ";
    cin >> b;

    int rangeCount = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] >= a && scores[i] <= b) {
            rangeCount++;
        }
    }

    cout << "Students in range: "
         << rangeCount
         << endl;


    // =====================================
    // 3. STUDENTS ABOVE AVERAGE
    // =====================================

    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += scores[i];
    }

    double average = sum / N;

    cout << "\n===== 3. ABOVE AVERAGE =====\n";

    cout << "Average score: "
         << fixed
         << setprecision(2)
         << average
         << endl;

    cout << "Students above average:\n";

    for (int i = 0; i < N; i++) {

        if (scores[i] > average) {

            cout << "Student "
                 << i + 1
                 << ": "
                 << scores[i]
                 << endl;
        }
    }


    // =====================================
    // 4. SECOND HIGHEST SCORE
    // =====================================

    double highest = scores[0];
    double secondHighest = -1;

    for (int i = 1; i < N; i++) {

        if (scores[i] > highest) {

            secondHighest = highest;
            highest = scores[i];
        }
        else if (scores[i] > secondHighest &&
                 scores[i] < highest) {

            secondHighest = scores[i];
        }
    }

    cout << "\n===== 4. SECOND HIGHEST =====\n";

    cout << "Highest score: "
         << highest
         << endl;

    cout << "Second highest score: "
         << secondHighest
         << endl;


    // =====================================
    // 5. SEARCH FOR A SCORE
    // =====================================

    double searchScore;

    cout << "\n===== 5. SEARCH FOR SCORE =====\n";

    cout << "Enter score to search: ";
    cin >> searchScore;

    bool found = false;

    cout << "Found at:\n";

    for (int i = 0; i < N; i++) {

        if (scores[i] == searchScore) {

            cout << "Student "
                 << i + 1
                 << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Score not found.\n";
    }


    // =====================================
    // 6. COUNT SCORE FREQUENCY
    // =====================================

    cout << "\n===== 6. SCORE FREQUENCY =====\n";

    cout << "Enter score: ";
    cin >> searchScore;

    int frequency = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] == searchScore) {
            frequency++;
        }
    }

    cout << "Score "
         << searchScore
         << " appears "
         << frequency
         << " times."
         << endl;


    // =====================================
    // 7. FIRST FAILING STUDENT
    // =====================================

    cout << "\n===== 7. FIRST FAILING STUDENT =====\n";

    bool foundFail = false;

    for (int i = 0; i < N; i++) {

        if (scores[i] < 5) {

            cout << "First failing student: Student "
                 << i + 1
                 << ": "
                 << scores[i]
                 << endl;

            foundFail = true;

            break;
        }
    }

    if (!foundFail) {
        cout << "All students pass!" << endl;
    }


    // =====================================
    // 8. COMPARE ADJACENT STUDENTS
    // =====================================

    cout << "\n===== 8. COMPARE ADJACENT STUDENTS =====\n";

    for (int i = 0; i < N - 1; i++) {

        if (scores[i + 1] > scores[i]) {

            cout << "Student "
                 << i + 2
                 << " improved compared to Student "
                 << i + 1
                 << endl;
        }
    }


    // =====================================
    // 9. LONGEST PASS STREAK
    // =====================================

    cout << "\n===== 9. LONGEST PASS STREAK =====\n";

    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] >= 5) {

            currentStreak++;

            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        }
        else {
            currentStreak = 0;
        }
    }

    cout << "Longest pass streak: "
         << longestStreak
         << " students"
         << endl;


    // =====================================
    // 10. SCORE DISTRIBUTION
    // =====================================

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] < 5) {
            count1++;
        }
        else if (scores[i] < 6.5) {
            count2++;
        }
        else if (scores[i] < 8) {
            count3++;
        }
        else if (scores[i] < 9) {
            count4++;
        }
        else {
            count5++;
        }
    }

    cout << "\n===== 10. SCORE DISTRIBUTION =====\n";

    cout << "0 - <5    : " << count1 << endl;
    cout << "5 - <6.5  : " << count2 << endl;
    cout << "6.5 - <8  : " << count3 << endl;
    cout << "8 - <9    : " << count4 << endl;
    cout << "9 - 10    : " << count5 << endl;


    return 0;
}