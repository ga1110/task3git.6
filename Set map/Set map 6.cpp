#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int t = 0;
    string word = "";
    set<string>vopr_vosk, pov, temp1, temp2, temp;
    string txt = "VecTor set mAiN algorithm! veCtor sEt AlgoRithm iosTreAm. string nAmeSpace VeCTor SeT alGoriThM?";
    string razd = "!?.";
    for (int i = 0; i < txt.size(); i++) {
        if (count(razd.begin(), razd.end(), txt[i]) != 0) {
            while (t != i) {
                if (txt[t] == ' ' || t == i - 1) {
                    if (t == i - 1) {
                        word += txt[t];
                    }
                    switch (txt[i]) {
                    case('!'):
                        vopr_vosk.insert(word);
                        word.erase();
                        t++;
                        break;
                    case('?'):
                        vopr_vosk.insert(word);
                        word.erase();
                        t++;
                        break;
                    case('.'):
                        pov.insert(word);
                        word.erase();
                        t++;
                        break;
                    }
                }
                else {
                    word += tolower(txt[t]);
                    t++;
                }
            }
            i += 2;
            t = i;
        }
    }
    vector<string>rez(vopr_vosk.size());
    set_difference(pov.begin(), pov.end(), vopr_vosk.begin(), vopr_vosk.end(), rez.begin());
    for (vector<string>::iterator it = rez.begin(); it != rez.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
}
