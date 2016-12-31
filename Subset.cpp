#include <iostream>
#include <vector>

using namespace std;

void printSubset(vector<int> &v) {
  cout << "{ ";
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << "}";
  cout << endl;
}

void ss(vector<int> &list, int n, vector<int> current, int sum) {
  if( sum == 0 ) {
   printSubset(current);
    return; 
  }

  if( n == 0 ) 
    return;
  
  if( list[n-1] <= sum ) {
    ss(list, n-1, current, sum);
    current.push_back(list[n-1]);
    ss(list, n-1, current, sum-list[n-1]);
  } else {
    ss(list, n-1, current, sum);
  }
}

int main() {

  vector<int> l,curr;
  int num, temp, sum, i = 0;
  
  cin >> num;
  
  while(i < num) {
    cin >> temp;
    l.push_back(temp);
    i++;
  }

  cin >> sum;
  
  ss(l, num, curr, sum);
  
  return 0;
}

/*
Console input:
30
3214 3426 5432 1278 1231 9877 6547 7643 8123 5467 1235 5678 2357 8765 2650 2136 5643 4538 8890 2453 2346 1649 7645 9875  8760 9465 1874 4583 1867 8641
34701
*/
