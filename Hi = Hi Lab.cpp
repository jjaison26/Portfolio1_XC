#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
//Three Credit (Ordered Numbers)

int strcmp_case_insensitive(string s1, string s2){
        string s1_new, s2_new;
        int num1 = 0;
        int num2 = 0;
        string str1 = "";
        string str2 = "";
        for(int i=0;i < s1.length();i++){
                s1_new += tolower(s1[i]);
        }
        for(int i=0;i < s2.length(); i++){
                s2_new += tolower(s2[i]);
        }

        if(s1.length() < s2.length()&& isdigit(s1[0]) == 0){
                return -1;
        }
        else if(s1.length() > s2.length()&& isdigit(s1[0]) == 0){
                return 1;
        }
        else if(isdigit(s1[0]) == 1) {
                istringstream iss1(s1);
                iss1 >> num1 >> str1;
                istringstream iss2(s2);
                iss2 >> num2 >> str2;
                if(num1 > num2) {
                        return 1;
                }
                else if(num1 < num2) {
                        return -1;
                }
                else{
                        if(s1.length() < s2.length()) {
                                return -1;
                        }
                        else if(s1.length() > s2.length()) {
                                return 1;
                        }
                        else {
                        for(int i = 0; i < s1.length(); i++) {
                                if(s1[i] != s2[i]) {
                                        if(s1[i] < s2[i]) {
                                                return -1;
                                        }
                                        else if(s1[i] > s2[i]) {
                                                return 1;
                                        }
                                }
                        }
                        }
                        return 0;


                }

        }
        else{
                for(int i=0;i < s2.length(); i++){
                        if(s1_new[i] != s2_new[i]){
                                if(s1_new[i] < s2_new[i]&& isdigit(s1[i]) == 0){
                                        return -1;
                                }
                                else if (s1_new[i] > s2_new[i] && isdigit(s1[i]) == 0) {
                                        return 1;
                                }

                        }
                }
                return 0;
        }
        return 0;
}

int main(){
        string s1, s2;
        cout << "Enter your first string." << endl;
        getline(cin,  s1);
        cout << "Enter your second string." << endl;
        getline(cin,  s2);
        cout << strcmp_case_insensitive(s1, s2)<< endl;
        return 0;
}

