#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;
//Two Credit (Starting Position)
int string_finder(string s1, char c1, int begin = 0) {
        int index = -1;
        if(begin > (s1.length()-1)) {
                return index;
        }
        else if(begin <= (s1.length()-1)){
        for(int i = begin; i < s1.length(); i++) {
                if(s1[i] == c1) {
                        return i;
                }
        }
        }
        return index;
}

int string_finder(string s1, string word, int begin = 0) {
        int index = -1;
        if(begin > (s1.length()-1)) {
                return index;
        }
        else if(begin <= (s1.length()-1)) {
        for(int i = begin; i < s1.length(); i++){
                int j;
                for(j = 0; j < word.length(); j++) {
                        if((s1[i+j] != word[j])) {
                                break;
                        }


                }
                if (j == word.length()){
                        return i;
                }
        }
        }
        return index;
}

int main() {
        assert(string_finder("The quick brown fox", 'T') == 0);
        assert(string_finder("The quick brown fox", "The") == 0);
        assert(string_finder("The quick brown fox", 'e') == 2);
        assert(string_finder("The quick brown fox", "quick") == 4);
        assert(string_finder("The quick brown fox", "quiet") == -1);
        assert(string_finder("The quick brown fox", 'z') == -1);
        assert(string_finder("The quick brown fox", "e") == 2);
        assert(string_finder("The quick brown fox", "quack") == -1);
        assert(string_finder("The quick brown fox", "e", 0) == 2);
        assert(string_finder("The quick brown fox", "e", 3) == -1);
        assert(string_finder("The quick brown fox", "e", 2) == 2);
        assert(string_finder("The quick brown fox", "e", 1) == 2);
        assert(string_finder("The quick brown fox", "e", 500) == -1);

        cout << "All tests have passed sucessfully!" << endl;
return 0;
}
