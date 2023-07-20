#include <algorithm>
int solution(string &S) {
int n = S.length();
    int question_marks_count = count(S.begin(), S.end(), '?');
    
    if (question_marks_count % 2 != 0)
        question_marks_count--;
    int max_substring = 0;
    int left_brack_count = 0, right_brack_count = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '<') {
            left_brack_count++;
            if (right_brack_count > 0) {
                right_brack_count--;
                max_substring += 2;
            }
        }
        else if (S[i] == '>') {
            right_brack_count++;
            if (left_brack_count > 0) {
                left_brack_count--;
                max_substring += 2;
            }
        }
        else if (S[i] == '?') {
            if (left_brack_count > 0) {
                left_brack_count--;
                max_substring += 2;
            }
            else if (right_brack_count > 0) {
                right_brack_count--;
                max_substring += 2;
            }
            else if (question_marks_count > 0) {
                question_marks_count -= 2;
                max_substring += 2;
            }
        }
    }

    return max_substring;
}