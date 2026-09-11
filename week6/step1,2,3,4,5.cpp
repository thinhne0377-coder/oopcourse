#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==================================================
// STEP 1: Function without parameters and return value
// ==================================================

void showMenu() {
    cout << "\n===== STEP 1: SHOW MENU =====" << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Display students" << endl;
    cout << "2. Show statistics" << endl;
    cout << "3. Exit" << endl;
    cout << "==============" << endl;
}
// ==================================================
// STEP 2: Function with one parameter, no return value
// ==================================================

void showStudentID(int id) {
    cout << "\n===== STEP 2: SHOW STUDENT ID =====" << endl;
    cout << "Student ID: " << id << endl;
}
// ==================================================
// STEP 3: Function with multiple parameters, no return value
// ==================================================

void printStudentInfo(string name, int id) {
    cout << "\n===== STEP 3: STUDENT INFORMATION =====" << endl;
    cout << "------------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
    cout << "------------------------" << endl;
}
// ==================================================
// STEP 4: Function with parameters and one return value
// ==================================================

double calculateAverage(double score1, double score2) {
    double sum = score1 + score2;
    double average = sum / 2.0;

    return average;
}
// ==================================================
// STEP 5: Function returns multiple results using struct
// ==================================================

struct ScoreInfo {
    double sum;
    double average;
    int count;
    double maxScore;
    double minScore;
};

ScoreInfo analyzeScores(const vector<double>& scores) {
    ScoreInfo result;

    result.sum = 0;
    result.count = scores.size();

    // Nếu danh sách rỗng
    if (result.count == 0) {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;

        return result;
    }

    // Gán giá trị ban đầu
    result.maxScore = scores[0];
    result.minScore = scores[0];

    // Duyệt danh sách điểm
    for (double s : scores) {
        result.sum += s;

        if (s > result.maxScore) {
            result.maxScore = s;
        }

        if (s < result.minScore) {
            result.minScore = s;
        }
    }

    // Tính điểm trung bình
    result.average = result.sum / result.count;

    return result;
}
// ==================================================
// MAIN PROGRAM
// ==================================================

int main() {

    // ------------------------------------------------
    // STEP 1: Gọi hàm không có tham số
    // ------------------------------------------------

    showMenu();
    // ------------------------------------------------
    // STEP 2: Gọi hàm có 1 tham số
    // ------------------------------------------------

    int studentID = 2112001;

    showStudentID(studentID);
    // ------------------------------------------------
    // STEP 3: Gọi hàm có nhiều tham số
    // ------------------------------------------------

    string studentName = "Nguyen An";

    printStudentInfo(studentName, studentID);
// ------------------------------------------------
    // STEP 4: Gọi hàm trả về 1 kết quả
    // ------------------------------------------------

    double math = 8.5;
    double english = 9.0;

    double average = calculateAverage(math, english);

    cout << "\n===== STEP 4: CALCULATE AVERAGE =====" << endl;
    cout << "Math score: " << math << endl;
    cout << "English score: " << english << endl;
    cout << "Average score = " << average << endl;

// ------------------------------------------------
    // STEP 5: Gọi hàm trả về nhiều kết quả
    // ------------------------------------------------

    vector<double> scores = {8.5, 7.0, 9.5, 6.0, 8.0};

    ScoreInfo info = analyzeScores(scores);

    cout << "\n===== STEP 5: MULTIPLE RESULTS =====" << endl;
    cout << "Total: " << info.sum << endl;
    cout << "Average: " << info.average << endl;
    cout << "Max score: " << info.maxScore << endl;
    cout << "Min score: " << info.minScore << endl;
    cout << "Count: " << info.count << endl;


    return 0;
}