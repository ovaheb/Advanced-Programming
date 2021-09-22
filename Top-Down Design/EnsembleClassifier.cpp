#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include <unistd.h>

using namespace std;

#define LABELS_FILE_NAME "/labels"
#define CLASSIFIER_FILE_NAME "/classifier_"
#define DATASET_FILE_NAME "/dataset"
#define PARSING_CRITERIA ','
#define TEN 10
#define CSV_FORMAT ".csv"
#define ZERO '0'
#define HUNDRED 100

typedef vector<double> Weight_vector;
typedef vector<Weight_vector> Classifier;

string get_current_working_dir() 
{
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

vector<double> parse_input(string str)
{
    double number;
    vector<double> broken_line;
    string word;
    istringstream s(str);
    while (getline(s, word, PARSING_CRITERIA))
    {
        number = stod(word);
        broken_line.push_back(number);    
    }
    return broken_line;
}

string integer_to_string(int number)
{
    string result, remainder;
    remainder = (number % TEN) + ZERO;
    if ((number < TEN) && (number >= 0))
        result = remainder;
    else 
        result = integer_to_string(number / TEN) + remainder;
    return result;
}

vector<vector<double> > read_csv_file(string file_address)
{
    string str, titles;
    vector<double> broken_line;
    vector<vector<double> > file_data;
    ifstream csvfile;
    csvfile.open(file_address + CSV_FORMAT, ios::in);
    getline(csvfile, titles);
    while (getline(csvfile, str))
    {
        broken_line = parse_input(str);
        file_data.push_back(broken_line);
    }
    csvfile.close();
    return file_data;
}

bool is_classifier_available(string file_address)
{
    bool flag;
    ifstream csvfile;
    csvfile.open(file_address + CSV_FORMAT, ios::in);
    if (csvfile.is_open()) 
        flag = true;
    else 
        flag = false;
    csvfile.close();
    return flag;
}

vector<Classifier> read_classifiers(string file_address)
{
    int counter = 0;
    char classifier_number = ZERO;
    vector<Classifier> classifiers;
    Classifier temporary_classifier;
    while (is_classifier_available(file_address + classifier_number))
    {
        temporary_classifier = read_csv_file(file_address + classifier_number);
        classifiers.push_back(temporary_classifier);
        counter++;
        classifier_number = counter + ZERO;
    }
    return classifiers;
}

vector<int> read_labels(string file_address)
{
    int number;
    string titles;
    vector<int> labels;
    ifstream csvfile;
    csvfile.open(file_address + CSV_FORMAT, ios::in);
    getline(csvfile, titles);
    while (csvfile >> number)
        labels.push_back(number);
    csvfile.close();
    return labels;
}

double calculate_score(Weight_vector weights, vector<double> data)
{
    double sum = weights[weights.size() - 1];
    for (int i = 0; i < weights.size() - 1; i++)
        sum += weights[i] * data[i];
    return sum;
}

int classify_data(Classifier criteria, vector<double> data)
{
    int i, class_number = 0;
    double temp, max;
    max = calculate_score(criteria[0], data);
    for (i = 0; i < criteria.size(); i++)
    {
        temp = calculate_score(criteria[i], data);
        if (temp > max)
        {
            max = temp;
            class_number = i;
        }
    }
    return class_number;
}

int find_most_repeated_vector_element(vector<int> data)
{
    int max = 0, counter, most_repeated;
    for (int i = 0; i < data.size(); i++)
    {
        counter = (int) count(data.begin(), data.end(), data[i]);
        if (counter > max)
        {
            max = counter;
            most_repeated = data[i];
        }
    }
    return most_repeated;
}

int vote_classifications(vector<Classifier> classification_methods, vector<double> data)
{
    vector<int> classification_results;
    for (int i = 0; i < classification_methods.size(); i++)
        classification_results.push_back(classify_data(classification_methods[i], data));
    return find_most_repeated_vector_element(classification_results);
}

double calculate_correct_answers(vector<vector<double> > dataset, vector<Classifier> classification_methods, vector<int> labels)
{
    int voter_result, correct_answer = 0;
    for (int i = 0; i < dataset.size(); i++)
    {
        voter_result = vote_classifications(classification_methods, dataset[i]);
        if (voter_result == labels[i]) 
            correct_answer++;
    }
    return correct_answer;
}

int main(int argc, char* argv[])
{
    vector<Classifier> classification_methods;
    vector<vector<double> > dataset;
    vector<int> labels;
    string validation_address(argv[1]), Weight_vectors_address(argv[2]);
    int correct_answers;
    dataset = read_csv_file(get_current_working_dir() + "/" + validation_address + DATASET_FILE_NAME);
    classification_methods = read_classifiers(get_current_working_dir() + "/" + Weight_vectors_address + CLASSIFIER_FILE_NAME);
    labels = read_labels(get_current_working_dir() + "/" + validation_address + LABELS_FILE_NAME);
    correct_answers = calculate_correct_answers(dataset, classification_methods, labels);
    cout.precision(2);
    cout << "Accuracy: " << (double(correct_answers) / labels.size()) * HUNDRED << "%" << endl;
    return 0;
}