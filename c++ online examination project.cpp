#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
void start();
const int MAX_TIME = 60; // Maximum time allowed for the exam, in seconds
const int MAX_QUESTIONS = 10; // Maximum number of questions in the exam
const string QUESTION_FILE = "questions.txt"; // File name for questions
const string ANSWER_FILE = "answers.txt"; // File name for answers

int main() {
    system("color 4b");
    start();
    system("cls");
    ofstream questionfile("questions.txt");
    ofstream answerfile("answers.txt");
    questionfile<<"what is c?    a.letter     b.name        c.tree      d.person"<<endl;
    questionfile<<"what is 8?     a.leter      b.number        c.name       d.animal"<<endl;
    questionfile<<"which one is capital city of sudan     a.kairo      b.kartum     c.addis abeba     d.asmera"<<endl;
    questionfile<<"which one is extnict animal in the world     a.lion    b.tiger     c.dinosr    d.zebra "<<endl;
    questionfile<<"which one is developed country      a.ethiopia    b.eritrea      c.china      d.somalia"<<endl;
    answerfile<<"a"<<endl;
    answerfile<<"b"<<endl;
    answerfile<<"b"<<endl;
    answerfile<<"c"<<endl;
    answerfile<<"c"<<endl;
    
    questionfile.close();
    answerfile.close();
    
    // Seed random number generator
    srand(time(NULL));

    // Open files for reading
    ifstream questionFile(QUESTION_FILE.c_str());
    ifstream answerFile(ANSWER_FILE.c_str());

    // Check if files opened successfully
    if (!questionFile.is_open() || !answerFile.is_open()) {
        cerr << "Failed to open question or answer file" << endl;
        return 1;
    }

    // Read questions and answers from files into arrays
    string questions[MAX_QUESTIONS];
    string answers[MAX_QUESTIONS];
    int numQuestions = 0;
    while (numQuestions < MAX_QUESTIONS && getline(questionFile, questions[numQuestions])) {
        getline(answerFile, answers[numQuestions]);
        numQuestions++;
    }

    // Close files
    questionFile.close();
    answerFile.close();

    // Shuffle questions
    for (int i = 0; i < numQuestions; i++) {
        int j = rand() % numQuestions;
        swap(questions[i], questions[j]);
        swap(answers[i], answers[j]);
    }

    // Start exam
    time_t startTime = time(NULL);
    int questionNum = 0;
    int numCorrect = 0;
    while (questionNum < numQuestions) {
        // Display question
        cout << "Question " << questionNum+1 << ": " << questions[questionNum] << endl;

        // Wait for answer
        string answer;
        time_t currentTime = time(NULL);
        while (difftime(currentTime, startTime) <= MAX_TIME && getline(cin, answer) && answer.empty()) {
            currentTime = time(NULL);
        }

        // Check if time is up
        if (difftime(currentTime, startTime) > MAX_TIME) {
            cout << "Time is up" << endl;
            break;
        }

        // Check answer
        if (answer == answers[questionNum]) {
         
            numCorrect++;

        }

        // Move to next question
        questionNum++;
    }

    // Display results
    cout << "You answered " << numCorrect << " out of " << questionNum << " questions correctly." << endl;

    // Ask confirmation question if exam finished before time is up
    if (difftime(time(NULL), startTime) < MAX_TIME) {
        cout << "Are you sure you want to finish the exam? (y/n)" << endl;
        string confirmation;
        getline(cin, confirmation);
        if (confirmation != "y") {
            cout << "Exam not finished." << endl;
            return 0;
        }
    }

    // End of program
    return 0;
}
void start(){
    cout<<"**************************************"<<endl;                      
    cout<<"*         well                  ****** "<<endl;
    cout<<"*           come                ******"<<endl;
    cout<<"*             to                ****** "<<endl;
    cout<<"*            exam               ******"<<endl;
    cout<<"*             quetion           ****** "<<endl;
    cout<<"**************************************"<<endl;
    char c;
    c=1;
    cout<<"press any key";
    cin>>c;
}
