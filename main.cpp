#include <iostream>

using namespace std;

void ask_for_scores(double scores[], const int scores_size, string name) {
    for (int i = 0; i < scores_size; i++) {
        bool second_try = false;
        do {
            if (second_try) {
                cout << "Score must be between 0 and 100, you entered: " << scores[i] << endl;
            }
            cout << "Enter score for " << name << " #" << i + 1 << " (0-100): ";
            cin >> scores[i];
            cout << endl;
            second_try = true;
        } while (scores[i] < 0 || scores[i] > 100);
    }
}

int main() {
    // A change
    // For Quizes
    char enter_another = 'y';
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

        const int FINAL = 1;
        double final_scores[FINAL];

        ask_for_scores(final_scores, FINAL, "Final");


        double final_score = 0;

        cout << "Scores entered:" << endl;
        for (double quiz_score: quiz_scores) {
            final_score += quiz_score * 0.075;
        }

        for (double project_score: project_scores) {
            final_score += project_score * 0.05;
        }

        for (double midterm_score: midterm_scores) {
            final_score += midterm_score * 0.15;
        }

        for (double final_score: final_scores) {
            final_score += final_score * 0.30;
        }

        cout << "Final score: " << final_score << endl;

        cout << "Again? (y/n) ";
        cin >> enter_another;
        cout << endl;
        cout << again << endl;
    }
    // } while (again);
    return 0;
}
