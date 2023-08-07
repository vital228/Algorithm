#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>




using namespace std;


const string LETTERS_PLUS = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string LETTERS_MINUS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct letter {
    char l;
    int count;
};

bool cmp(letter a, letter b) {
    return a.count > b.count || (a.count == b.count && a.l > b.l);
}

int moveDist(string& path, int prev, int next, int count) {
    int p = 0;
    if (abs(next - prev) <= count / 2) {
        if (next < prev) {
            for (int i = next; i < prev; i++) {
                path += '<';
                p--;
            }
        }
        else {
            for (int i = prev; i < next; i++) {
                path += '>';
                p++;
            }
        }
    }
    else {
        if (next < prev) {
            for (int i = prev; i < next + count; i++) {
                path += '>';
                p++;
            }
        }
        else {
            for (int i = next; i < prev + count; i++) {
                path += '<';
                p--;
            }
        }
    }
    return p;
}


string algo1(string magicPhrase) {

    string path = "";
    map<char, int> ma;
    char zone[30];
    int k = 0;
    int p = 0;
    int posMa[11];
    for (int i = -1; i < 20; i += 3) {
        for (int j = 0; j < 3; j++) {
            if (i + j == -1) ma[' '] = k;
            else ma['A' + i + j] = k;
        }
        posMa[k] = i;
        k++;
    }
    for (int i = 20; i < 26; i += 2) {
        for (int j = 0; j < 2; j++) {
            ma['A' + i + j] = k;
        }
        posMa[k] = i;
        k++;
    }
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < 10; i++) {
            if (posMa[i] < 13) {
                for (int j = 0; j <= posMa[i]; j++) {
                    path += '+';
                }
            }
            else {
                for (int j = 26; j > posMa[i]; j--) {
                    path += '-';
                }
            }
            zone[t * 10 + i] = posMa[i];
            if (t != 2 || i != 9)
                path += '>';
        }
    }
    p = 29;
    for (char c : magicPhrase) {
        int inext = ma[c];
        int iprev = p % 10;
        p += moveDist(path, iprev, inext, 10);
        p = (p + 30) % 30;
        int t = (c == ' ') ? -1 : c - 'A';
        if (zone[p] >= t) {
            for (int i = t; i < zone[p]; i++) {
                path += '-';

            }
        }
        else {
            for (int i = zone[p]; i < t; i++) {
                path += '+';
            }
        }
        zone[p] = t;
        path += '.';
    }
    return path;
}

string algo2(string magicPhrase) {
    int count_letters[27];
    letter letters[27];
    int index_letters[27];
    for (int i = 0; i < 27; i++) {
        count_letters[i] = 0;
    }
    string path = "";
    for (char i : magicPhrase) {
        if (i == ' ') {
            count_letters[26]++;
        }
        else {
            count_letters[i - 'A']++;
        }
    }
    for (int i = 0; i <= 26; i++) {
        if (i == 26) {
            letters[i].l = ' ';
        }
        else {
            letters[i].l = (char)('A' + i);
        }
        letters[i].count = count_letters[i];
    }
    sort(letters, letters + 27, cmp);
    int p = 0;
    while (letters[p].count) {
        if (letters[p].l == ' ') {
            index_letters[26] = p;
        }
        else {
            int k = letters[p].l - 'A';
            index_letters[letters[p].l - 'A'] = p;
            if (k < 13) {
                for (int j = 0; j <= k; j++) {
                    path += '+';
                }
            }
            else {
                for (int j = 0; j < 26 - k; j++) {
                    path += '-';
                }
            }
        }
        p++;
        if (p < 27 && letters[p].count)
            path += '>';
    }
    p--;
    for (char c : magicPhrase) {
        int index = (c == ' ') ? index_letters[26] : index_letters[c - 'A'];
        p += moveDist(path, p, index, 30);
        path += '.';
        p = (p + 30) % 30;
    }
    return path;
}

string algo3(string magicPhrase) {
    string path = "";
    int zone[30];
    for (int i = 0; i < 30; i++) zone[i] = -1;
    int prevP = 0;
    for (char c : magicPhrase) {
        int minnextP = prevP;
        int cint = (c == ' ') ? -1 : c - 'A';
        int min = (abs(zone[prevP] - cint) <= 13) ? abs(zone[prevP] - cint) : 27 - abs(zone[prevP] - cint);
        for (int nextp = 0; nextp < 30; nextp++) {
            int t = (abs(nextp - prevP) <= 15) ? abs(nextp - prevP) : 30 - abs(nextp - prevP);
            t += (abs(zone[nextp] - cint) <= 13) ? abs(zone[nextp] - cint) : 27 - abs(zone[nextp] - cint);
            if (t < min) {
                min = t;
                minnextP = nextp;
            }
        }
        prevP += moveDist(path, prevP, minnextP, 30);
        prevP = (prevP + 30) % 30;
        int t = (c == ' ') ? -1 : c - 'A';
        if (zone[prevP] >= t) {
            for (int i = t; i < zone[prevP]; i++) {
                path += '-';

            }
        }
        else {
            for (int i = zone[prevP]; i < t; i++) {
                path += '+';
            }
        }
        zone[prevP] = t;
        path += '.';
    }
    return path;
}

string repeatLetterWithoutLoop(char c, int count, int zone[], int& pos) {
    string path = "";
    int prevP = pos;
    int minnextP = prevP;
    int cint = (c == ' ') ? -1 : c - 'A';
    int min = (abs(zone[prevP] - cint) <= 13) ? abs(zone[prevP] - cint) : 27 - abs(zone[prevP] - cint);
    for (int nextp = 0; nextp < 30; nextp++) {
        int t = (abs(nextp - prevP) <= 15) ? abs(nextp - prevP) : 30 - abs(nextp - prevP);
        t += (abs(zone[nextp] - cint) <= 13) ? abs(zone[nextp] - cint) : 27 - abs(zone[nextp] - cint);
        if (t < min) {
            min = t;
            minnextP = nextp;
        }
    }
    prevP += moveDist(path, prevP, minnextP, 30);
    prevP = (prevP + 30) % 30;
    int t = (c == ' ') ? -1 : c - 'A';
    if (zone[prevP] >= t) {
        for (int i = t; i < zone[prevP]; i++) {
            path += '-';
        }
    }
    else {
        for (int i = zone[prevP]; i < t; i++) {
            path += '+';
        }
    }
    for (int i = 0; i < count; i++) path += '.';
    pos = prevP;
    return path;
}


string algo4(string magicPhrase) {
    string path = "";
    int zone[30];
    for (int i = 0; i < 30; i++) zone[i] = -1;
    int pos = 0;
    for (int i = 0; i < magicPhrase.length(); i++) {
        int count = 1;
        char c = magicPhrase[i];
        while (i + 1 < magicPhrase.length() && magicPhrase[i] == magicPhrase[i + 1] && count < 26) {
            count++;
            i++;
        }
        int post = pos;
        string path_temp = repeatLetterWithoutLoop(c, count, zone, post);
        string t2 = "";

    }
    return path;
}




int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    string path = "";
    string al1 = algo1(magicPhrase);
    string al2 = algo2(magicPhrase);
    string al3 = algo3(magicPhrase);
    path = (al1.length() < al2.length()) ? al1 : al2;
    path = (al3.length() < path.length()) ? al3 : path;
    cout << path << endl;
}