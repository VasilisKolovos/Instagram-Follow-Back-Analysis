#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void names() {
    ifstream file1, file2;
    file1.open("followers.csv");
    file2.open("following.csv");
    if (file1.is_open()) {
        if (file2.is_open()) {
            string line1;
            string line2;
            getline(file1, line1);
            getline(file2, line2);
            int m1 = 0, m2 = 0, sum = 0, k=1, num=1;
            while (getline(file1, line1)) {
                m1++;
            }
            while (getline(file2, line2)) {
                m2++;
            }
            file1.close();
            file2.close();
            file1.open("followers.csv");
            file2.open("following.csv");
            getline(file1, line1);
            getline(file2, line2);
            for (int i = 0; i <= m2; i++) {
                getline(file2, line2, ',');
                getline(file2, line2);
                for (int j = 0; j <= m1; j++) {
                    getline(file1, line1, ',');
                    getline(file1, line1);
                    if (line2 == line1) {
                        file1.close();
                        break;
                    }
                    else {
                        if (j == m1) {
                            sum++;
                            file1.close();
                        }
                    }
                }
                file1.open("followers.csv");
            }
            string* out = new string[sum];
            file1.close();
            file2.close();
            file1.open("followers.csv");
            file2.open("following.csv");
            for (int i = 0; i <= m2; i++) {
                getline(file2, line2, ',');
                getline(file2, line2);
                for (int j = 0; j <= m1; j++) {
                    getline(file1, line1, ',');
                    getline(file1, line1);
                    if (line2 == line1) {
                        file1.close();
                        break;
                    }
                    else {
                        if (j == m1) {
                            out[k] = line2;
                            k++;
                            file1.close();
                        }
                    }
                }
                file1.open("followers.csv");
            }
            if (sum == 0) {
                cout << "All your followers, follow you back" << endl;
            }
            else {
                for (int i = 1; i < sum; i++) {
                    cout<< num++<< " " << out[i] << endl;
                }
            }
        }
        else {
            cout << "One or more files were not able to open" << endl;
        }
    }
    else {
        cout << "One or more files were not able to open" << endl;
    }
    file1.close();
    file2.close();
}

int main(int argc, char** argv) {
    names();
    system("pause");
    return 0;
}