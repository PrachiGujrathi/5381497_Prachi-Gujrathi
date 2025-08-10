#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    string meridian = s.substr(8, 2); // "AM" or "PM"
    int hour = stoi(s.substr(0, 2));

    if (meridian == "AM") {
        if (hour == 12) hour = 0; // midnight case
    } else { // PM
        if (hour != 12) hour += 12; // afternoon case
    }

    stringstream ss;
    ss << setw(2) << setfill('0') << hour << s.substr(2, 6); // keep :MM:SS
    return ss.str();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
