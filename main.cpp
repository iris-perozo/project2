#include <iostream>

using namespace std;

double ask_for_score(string name) {
    double score;
    int attempts = 0;
    do {
        if (attempts > 0) {
            cout << "Score must be between 0 and 100, you entered: " << score << endl;
        }
        cout << "Enter score for " << name << " (0-100): ";
        cin >> score;
        attempts++;
    } while (score < 0 || score > 100);
    return score;
}

void ask_for_scores(double scores[], const int scores_size, string name) {
    for (int i = 0; i < scores_size; i++) {
        scores[i] = ask_for_score(name + " " + to_string(i + 1));
    }
}

bool ask_again() {
    char input;
    cout << "Again? (y/n) ";
    cin >> input;
    return input == 'y' || input == 'Y';
}

int main() {
    bool again = true;
    // do {
    while (again) {
        const int NUM_QUIZES = 2;
        double quiz_scores[NUM_QUIZES];

        ask_for_scores(quiz_scores, NUM_QUIZES, "Quiz");

        const int NUM_PROJECTS = 5;
        double project_scores[NUM_PROJECTS];

        ask_for_scores(project_scores, NUM_PROJECTS, "Project");

        const int NUM_MIDTERMS = 2;
        double midterm_scores[NUM_MIDTERMS];

        ask_for_scores(midterm_scores, NUM_MIDTERMS, "Midterm");

        double final_exam_score = ask_for_score("Final Exam");

        // Start calculating final grade
        double final_grade = final_exam_score * 0.30;

        for (double quiz_score: quiz_scores) {
            final_grade += quiz_score * 0.075;
        }

        for (double project_score: project_scores) {
            final_grade += project_score * 0.05;
        }

        for (double midterm_score: midterm_scores) {
            final_grade += midterm_score * 0.15;
        }

        cout << "Final score: " << final_grade << endl;

        again = ask_again();
    }
    // } while (again);
    return 0;
}
