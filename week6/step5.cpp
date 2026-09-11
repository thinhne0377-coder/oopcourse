#include <iostream>
#include <vector>
using namespace std;
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

    if (result.count == 0) {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;
        return result;
    }
 result.minScore = scores[0];
    result.maxScore = scores[0];

    for (double s : scores) {
        result.sum += s;

        if (s > result.maxScore)
            result.maxScore = s;

        if (s < result.minScore)
            result.minScore = s;
    }

    result.average = result.sum / result.count;

    return result;
}
int main() {
    vector<double> scores = {8.5, 7.0, 9.5, 6.0, 8.0};