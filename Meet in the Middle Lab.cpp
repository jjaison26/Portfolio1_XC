#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main() {
        string fileName, line;
        int num;
        int n;
        vector<int> my_vec;
        cout << "Enter the file name: " << endl;
        cin >> fileName;
        ifstream file(fileName);
        if(file.is_open()) {
                while(getline(file, line, ',')) {
                        cout << line << endl;
                        num = stoi(line);
                        my_vec.push_back(num);

                }

                file.close();
                n = my_vec.size();
                cout << "Sorted Array" << endl;
                for(int i = 0; i < n; i ++) {
                        for(int j = 0; j < n-i; j++) {
                                if (my_vec[j] > my_vec[j+1]) {
                                        int temp = my_vec[j];
                                        my_vec[j] = my_vec[j+1];
                                        my_vec[j+1] = temp;

                                }
                        }
                }

                for(int i = 0; i < n; i++) {
                        cout << my_vec[i] << endl;;
                }
                if(n%2 == 0) {
                        cout << "The median is " << (my_vec[n/2] + my_vec[n/2 -1]) / 2 << endl;
                }
                else{
                        cout << "The median is " << my_vec[n/2] << endl;
                }

                float sum = 0;
                for(int i = 0; i < n; i++) {
                        sum += my_vec[i];
                }
                cout << "The mean of this data set is " << sum/n << endl;
                int mode = my_vec[0];
                int mode_count = count(my_vec.begin(), my_vec.end(), mode);
                int maxF;
                for(int i = 0; i < n; i++) {
                         maxF = count(my_vec.begin(), my_vec.end(), my_vec[i]);
                         if(maxF > mode_count) {
                                mode = my_vec[i];
                                mode_count = maxF;
                         }
                }
                cout << "The mode is " << mode << endl;
        }
        else {
                cout << "Error opening file!" << endl;
        }

        return 0;
}
