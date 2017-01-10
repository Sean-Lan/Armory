/**
 *
 * Sean
 * 2017-01-10
 *
 * Helper functions for convert integer vector into string and convert it back.
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string iVecToString(const vector<int> &iVec, char sep) {
  if (iVec.empty()) return "";
  int n = iVec.size();
  string res = to_string(iVec[0]);
  for (int i=1; i<n; ++i) {
    res += sep;
    res += to_string(iVec[i]);
  }
  return res;
}

vector<int> stringToIVec(const string &s, char sep) {
  if (s.empty()) return {};
  vector<int> iVec;
  int n = s.size();
  int start = 0;
  int i;
  for (i=0; i<n; ++i) {
    if (s[i] == sep) {
      string tmp = s.substr(start, i-start);
      iVec.push_back(atoi(tmp.c_str()));
      start = i+1;
    }
  }
  string tmp = s.substr(start, i-start);
  iVec.push_back(atoi(tmp.c_str()));
  return iVec;
}

int main() {
  char sep = ',';
  vector<int> iVec = {3, 4, -21, 53, 64};
  // first convert it into string
  string s = iVecToString(iVec, sep);
  cout << s << endl;

  // then convert the string into vector
  vector<int> converted = stringToIVec(s, sep);
  for (auto &i : converted) cout << i << " ";
  cout << endl;
  return 0;
}

