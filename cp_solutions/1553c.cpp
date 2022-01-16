#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  string s;

  cin>>s;

  int team1_optimal_score =0 , team2_least_score=0;

  int res1=10, res2=10;

  int odds = 5, evens=5;

  // optimal for team1
  for(int i=1;i<=10;i++) {

    // cout<<i<<" "<<team1_optimal_score<<" "<<team2_least_score<<endl;

    i %2 == 0 ? evens-- : odds--;
    
    if(s[i-1] == '?') {

      if(i%2 == 0) {
        team1_optimal_score+=1;
         
      }           
    }
    else {
      if(i%2 == 0) {
        team1_optimal_score += s[i-1] - '0';
      } else {
        team2_least_score += s[i-1] - '0';
      }
    }
    // cout<<i<<" "<<team1_optimal_score<<" "<<team2_least_score<<endl;

    if(team1_optimal_score > (team2_least_score + (odds))) {
      res1 = i;
      break;
    }

  }

  int team2_optimal_score =0 , team1_least_score=0;

  odds=5;
  evens = 5;

  // Optimal for team2
  for(int i=1;i<=10;i++) {

    // cout<<i<<" "<<team2_optimal_score<<" "<<team1_least_score<<endl;

    i %2 == 0 ? evens-- : odds--;
    
    if(s[i-1] == '?') {

      if(i%2) {
        team2_optimal_score+=1;
      }
    }

    else {

      if(i%2 == 0) {
        team1_least_score += s[i-1] - '0';
      } else {
        team2_optimal_score += s[i-1] - '0';
      }
    }

    // cout<<i<<" "<<team2_optimal_score<<" "<<team1_least_score<<endl;

     if(team2_optimal_score > (team1_least_score + (evens))) {
      res2 = i;
      break;
    }

  }

  cout<<min(res1,res2)<<endl;
  
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

auto start = high_resolution_clock::now();

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout<<"time: "<<duration.count()/1e6<<endl;
}
