#include <iostream>
#include <iomanip>

using namespace std;

// =====================================================
// FUNCTION PROTOTYPES
// =====================================================

void inputStudents(int &N, double scores[]);
void countExcellentStudents(int N, double scores[]);
void countStudentsInRange(int N, double scores[]);
void findStudentsAboveAverage(int N, double scores[]);
void findSecondHighestScore(int N, double scores[]);
void searchForScore(int N, double scores[]);
void countScoreFrequency(int N, double scores[]);
void findFirstFailingStudent(int N, double scores[]);
void compareAdjacentStudents(int N, double scores[]);
void findLongestPassStreak(int N, double scores[]);
void createScoreDistribution(int N, double scores[]);
// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    int N;
    double scores[20];

    // Nhap so luong hoc sinh va diem
    inputStudents(N, scores);

    // =================================================
    // 1. COUNT EXCELLENT STUDENTS
    // =================================================
    countExcellentStudents(N, scores);

    // =================================================
    // 2. COUNT STUDENTS IN SCORE RANGE
    // =================================================
    countStudentsInRange(N, scores);

    // =================================================
    // 3. FIND STUDENTS ABOVE AVERAGE
    // =================================================
    findStudentsAboveAverage(N, scores);

    // =================================================
    // 4. FIND SECOND HIGHEST SCORE
    // =================================================
    findSecondHighestScore(N, scores);

    // =================================================
    // 5. SEARCH FOR A SCORE
    // =================================================
    searchForScore(N, scores);

    // =================================================
    // 6. COUNT SCORE FREQUENCY
    // =================================================
    countScoreFrequency(N, scores);

    // =================================================
    // 7. FIND FIRST FAILING STUDENT
    // =================================================
    findFirstFailingStudent(N, scores);

    // =================================================
    // 8. COMPARE ADJACENT STUDENTS
    // =================================================
    compareAdjacentStudents(N, scores);

    // =================================================
    // 9. FIND LONGEST PASS STREAK
    // =================================================
    findLongestPassStreak(N, scores);

    // =================================================
    // 10. CREATE SCORE DISTRIBUTION
    // =================================================
    createScoreDistribution(N, scores);

    return 0;
}