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
