#include <iostream>
// https://www.w3schools.com/cpp/cpp_vectors.asp
// https://cplusplus.com/reference/vector/vector/
#include <vector>

using namespace std;

/**
 * @brief Prompts the user for a single score with a given label.
 * 
 * This function repeatedly asks the user to enter a score until a valid
 * decimal number between 0 and 100 is provided.
 * 
 * @param label The label to display when asking for the score.
 * @return double The valid score entered by the user.
 */
double ask_for_score(string label);

/**
 * @brief Prompts the user for multiple scores with a given label.
 * 
 * This function asks the user to enter a specified number of scores,
 * each with a given label, and returns them as a vector of doubles.
 * 
 * @param label The label to display when asking for each score.
 * @param num_scores The number of scores to ask for.
 * @return vector<double> A vector containing the valid scores entered by the user.
 */
vector<double> ask_for_scores(string label, const int num_scores);

/**
 * @brief Asks the user if they want to repeat the process.
 * 
 * This function prompts the user with a yes/no question and returns true
 * if the user inputs 'y' or 'Y', otherwise returns false.
 * 
 * @param prompt The prompt to display before waiting for user input (Default: "Again? (y/n) ").
 * @return bool True if the user wants to repeat the process, false otherwise.
 */
bool ask_yes_no(string prompt = "Again? (y/n) ");

int main() {
    // Weights for each score type (% as decimal)
    const double FINAL_EXAM_WEIGHT = 0.30, QUIZ_WEIGHT = 0.075, PROJECT_WEIGHT = 0.05, MIDTERM_WEIGHT = 0.15;
    // Number of each score type
    const int NUM_QUIZES = 2, NUM_PROJECTS = 5, NUM_MIDTERMS = 2;

    do {
        // Collect scores for quizzes, projects, and midterms
        // vector docs:
        // https://www.w3schools.com/cpp/cpp_vectors.asp
        // https://cplusplus.com/reference/vector/vector/
        vector<double> quiz_scores = ask_for_scores("Quiz", NUM_QUIZES);
        vector<double> project_scores = ask_for_scores("Project", NUM_PROJECTS);
        vector<double> midterm_scores = ask_for_scores("Midterm", NUM_MIDTERMS);

        // Collect score for the final exam
        double final_exam_score = ask_for_score("Final Exam");

        // Calculate the final score. We can start with the final exam.
        double final_score = final_exam_score * FINAL_EXAM_WEIGHT;
        for (double quiz_score : quiz_scores) {
            // Add each quiz score weighted by QUIZ_WEIGHT
            final_score += quiz_score * QUIZ_WEIGHT;
        }
        for (double project_score : project_scores) {
            // Add each project score weighted by PROJECT_WEIGHT
            final_score += project_score * PROJECT_WEIGHT;
        }
        for (double midterm_score : midterm_scores) {
            // Add each midterm score weighted by MIDTERM_WEIGHT
            final_score += midterm_score * MIDTERM_WEIGHT;
        }

        // Output the final score
        cout << "Final score: " << final_score << endl;
    } while (ask_yes_no()); // Repeat the process if the user wants to
    return 0;
}

double ask_for_score(string label) {
    string user_input;
    double score = -1; // Start with an invalid score
    int attempts = 0;
    do {
        if (attempts++ > 0) {
            // Inform the user of invalid input
            cout << "Score must be a decimal number between 0 and 100, you entered: " << user_input << endl;
        }
        // Prompt the user for input
        cout << "Enter score for " << label << " (0-100): ";
        cin >> user_input;
        // https://www.w3schools.com/cpp/cpp_exceptions.asp
        try {
            // Convert the input string to a double
            // https://cplusplus.com/reference/string/stod/
            score = stod(user_input);
        } catch (invalid_argument &e) {
            // If conversion fails, continue the loop
            continue;
        }
    } while (score < 0 || score > 100); // Ensure the score is within valid range
    return score;
}

vector<double> ask_for_scores(string label, const int num_scores) {
    vector<double> scores(num_scores); // Initialize a vector to hold the scores
    for (int i = 0; i < scores.size(); i++) {
        // Ask for each score individually
        scores[i] = ask_for_score(label + " " + to_string(i + 1));
    }
    return scores;
}

bool ask_yes_no(string prompt) {
    string input;
    cout << prompt;
    cin >> input;
    // Return true if the user inputs 'y' or 'Y'
    return input.front() == 'y' || input.front() == 'Y';
}
