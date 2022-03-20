// Name: Marissa Mar
// Date: 17 March 2022

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Class to hold requests
struct RequestRecord {
  public:
    RequestRecord(
      int n,
      int start_value,
      int finish_value,
      int weight
    ){
      startValue = start_value;
      finishValue = finish_value;
      Weight = weight;
      name = n;
    }

    void display() {
      cout << "Name: " << name << endl;
      cout << "Start Value: " << startValue << endl;
      cout << "Finish Value: " << finishValue << endl;
      cout << "Weight: " << Weight << endl;
      cout << endl;
    }
    int name;
    int startValue;
    int finishValue;
    int Weight;
};


//Function: compareJobs
//Arguments: RequestRecord Record1, RequestRecord Record2
//Returns bool
//Description: if the finish value of record1 is higher than request 2 then return 2
// else return 0
bool compareJobs(RequestRecord Request1, RequestRecord Request2){
  if(Request1.finishValue < Request2.finishValue){
    return 1;
  }
  else{
    return 0;
  }
}

  // back tracking
//}
// Function: Compute Optimal jobs
// Arguments: Vector passed through with requests, size of jobs from <vector>
// Returns int optimal profit
// This is a recursive function that returns maximum profit from given array of jobs
//int computeOptimal(vector<RequestRecord> &my_requests, size_t jobs){
  // create for jobs a vector of weights profits and optimals
// create p class
  //Create a base case which is just 0
  //profits == 0
//  if(jobs == 0);
//    tmpRequests.
  // if we look at the first job then then p(1) = 0

  //Recursion formula
  //Opt(j) maximum of picking job j
  // weight of job j
  //opt(p(j)) remainining intervals of the ones that overlap
  // opt(j-1) overlooking previous and just overlooking
  // base case Opt(0) is 0

  //Opt(j) = max{weight of job j + opt(p(j)), OPT(j-1))
  // example: opt of job 2 = max of weight of 2 which is 4 + opt (p(2) = 0, opt(j-1) = 0)
  // so max(4, 0) is 4 so we pick
  // case 1 (we pick it) remove all overlapping jobs and compute solution for the subproblem of jobs left

  // case 2 (we don't pick it) simply compute optimal solution for the subproblem n-1 items left

  // we can do this recursively for j = 1,2,..n and define OPT(j) = maximum weight that can be achieved
  // by selected the jobs from first j intervals


  // help Function: let p(j) be the largest index i such that finish time of i is less than or equal to start time of j
  // This function will help to remove overlapping jobs

//Find non-overlapping interval schedule
// Returns if the interval in the loop from the WIS function is within the S-F interval
// Profit is the largest index i < j such that i is compatible with j
// max of two sub problems
//int weightedIntervalScheduling(vector<RequestRecord> &requests, int jobs){
//  int M[jobs];

  // base case
  // if there are no jobs then nothing
//  if(jobs == 0){/
//    M[0] = 0;
//    return 0;
//  }
  // Iterative Bottom-Up Dynamic Programming
//  M[0] = 0;
//  for(int i = 1; i < jobs; i++){
  //  int indexProfit = findProfits(requests, i);
//    if(indexProfit != -1){

  //  }

//  }

//  }
///}

findProfit(vector<RequestRecord> &requests, int j)
int findMaximumProfit(vector<RequestRecord> &requests, int j){
  int number_of_jobs = requests.size();
  // temporary array to hold optimized weights to check solution
  int tmpArray[number_of_jobs];
  // Base Case 
  if(j == 0){
    return 0;
  }
  else{
    if(requests.at(j).Weight + tmpArray[findOptimalPairInterval[job]] >= tmpArray[j-1]){
      output j together with result of find solution
    }
    else{
      //output the result of find-solution)j-1)
    }
  }
  //Create array to hold the maximum profit of non-overlapping compareJobs
  // ending at the i'th job
  int maxProfit[number_of_jobs];

  for(int i = 0; i < number_of_jobs; i++){
    //initialize current profit to 0
    maxProfit[i] = 0;

    for(int j = 0; j < i; j++){
      if(requests[j].finishValue <= requests.at[i].start && maxProfit[i] < maxProfit[j]){
        maxProfit[i] = maxProfit[j];
      }
    }
    maxProfit[i] += requests[i].weight;
  }
  return *max_element(maxProfit, maxProfit + n);

}
int main(){
    // Declare an input file stream variable
    ifstream myFile;

    // Open file stream from path which is located from this dir "request.csv"
    myFile.open("requests.csv");

    if(!myFile.is_open()){
      cerr << "Unable to open requests.csv" << endl;
      exit(1);
    }
    vector<RequestRecord> my_requests;
    string line = "";
    getline(myFile, line);
    cout << line << endl;
    line = "";
    int n = 1;
    while(!myFile.eof()){
      int name;
      int start_value;
      int finish_value;
      int weight;
      string tmpString = "";

      name = n;
      stringstream inputString(line);
      getline(myFile, tmpString,',');
      if(tmpString.length() == 0){
        break;
      }
      start_value = atoi(tmpString.c_str());

      getline(myFile, tmpString,',');
      finish_value = atoi(tmpString.c_str());

      getline(myFile, tmpString, '\n');
      weight = atoi(tmpString.c_str());

      RequestRecord request(n, start_value, finish_value, weight);
      my_requests.push_back(request);
      line = " ";
      n++;
      }
      cout << "Pre Sorted Requests" << endl;
      size_t number_of_jobs = my_requests.size();
      for(size_t i = 0; i < number_of_jobs; ++i) {
        cout << my_requests.at(i).name << " " << my_requests.at(i).startValue << " " << my_requests.at(i).finishValue << " "<< my_requests.at(i).Weight << endl;
      }
      // sort jobs by finish times so that  f1 <= f2 <= ... <= fn.
      // using built in function from c++
      //This function is used to sort the elements in the range in ascending order.
      sort(my_requests.begin(), my_requests.end(), compareJobs);

      cout << endl;
      cout << "Post Sorted Requests" << endl;
      for(size_t i = 0; i < number_of_jobs; ++i) {
        cout <<my_requests.at(i).name << " " <<  my_requests.at(i).startValue << " " << my_requests.at(i).finishValue << " "<< my_requests.at(i).Weight << endl;
      }
      for(auto request:my_requests){
        request.display();
      }

      cout << findMaximumProfit(my_requests);
      for(size_t i = number_of_jobs; i != 0; --i) {
        cout << findMaximumProfit(my_requests, i);
      }
    myFile.close();
    return 0;
}
