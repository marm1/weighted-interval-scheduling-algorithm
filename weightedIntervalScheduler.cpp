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
      int weight,
      int compatible_job
    ){
      startValue = start_value;
      finishValue = finish_value;
      Weight = weight;
      name = n;
      compatibleJob = compatible_job;
    }

    void display() {
      cout << "Name: " << name << endl;
      cout << "Start Value: " << startValue << endl;
      cout << "Finish Value: " << finishValue << endl;
      cout << "Weight: " << Weight << endl;
      cout << "Compatible Job: " << Weight << endl;
      cout << endl;
    }
    int name;
    int startValue;
    int finishValue;
    int Weight;
    int compatibleJob;
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

//Function: findNonOverLappingPair
// Input: vector<RequestRecord> &my_requests, int i
// Returns index of the non-overlapping pair in the vector, otherwise it's
// return a -1 since it doesn't have a
int findNonOverLappingPair(vector<RequestRecord> &my_requests, int interval)
{
    for (int i = interval; i >= 0; i--) {
      // find the non-overlapping pair of weights
      if (my_requests.at(i).finishValue <= my_requests.at(interval).startValue) {
        return i;
      }
      //&& (findSum(L[j]) > findSum(L[i])))
  //        L[i] = L[j];
    }
    return -1;
}

// function: findSolution
// Input: int mem[], vector<RequestRecord> &my_requests, const int num_jobs, int total_weight
// Returns nothing but outputs the optimal weight and schedule to command
void findSolution(int mem[], vector<RequestRecord> &my_requests, const int num_jobs, int total_weight) {
    if (num_jobs == 0) {
      cout << endl;
      cout << "The Optimal Weight: " << total_weight << endl;
        return;
    }
    // if the weight + the elemennts in the memoized array is greater than the
    // element in previous array then print out the interval of the schedule
    // also calucuates maximum weight from vector> v and recursively calls itself
    else if (my_requests[num_jobs - 1].Weight + mem[num_jobs] > mem[num_jobs - 1]) {
       cout << num_jobs << " ";
       total_weight += my_requests[num_jobs-1].Weight;
       findSolution(mem, my_requests, my_requests.at(num_jobs - 1).compatibleJob, total_weight);
    }
    // if the weight + profit is not greater than previous job then recursively call the function again
    else {
        findSolution(mem, my_requests, num_jobs - 1, total_weight);
        cout << endl;
    }
}

// function: iterativeComptOut
// Input: vector<RequestRecord> &my_requests
// Returns nothing/
// Description: creates memoized array that add
void iterativeCompOpt(vector<RequestRecord> &my_requests){
  // Using the dynamic bottom-up approach dynamic programming to unwind recursion
  int memoizedArray[my_requests.size() + 1];
  // First index has 0 for base case
  memoizedArray[0] = 0;

  // Add the max values to the memoized array based on the max or largest weight + the compatible job Profits
  // or if the profit + weight in previous element is higher
  for (int j = 1; j < my_requests.size(); j++){
      memoizedArray[j] = max(my_requests[j].Weight + memoizedArray[my_requests[j].compatibleJob], memoizedArray[j-1]);
  }
  // create variable to hold total weight when finding the schedule
  int totalWeight = 0;
  findSolution(memoizedArray, my_requests, my_requests.size(), totalWeight);
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
    int n = 1;
    // read file till end and input all values into the vector
    while(!myFile.eof()){
      int name;
      int start_value;
      int finish_value;
      int weight;
      int compatible_job = 0;
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
      compatible_job = 0;
      RequestRecord request(n, start_value, finish_value, weight, compatible_job);
      my_requests.push_back(request);
      line = " ";
      n++;
      }
      // show pre sorted requests
      cout << "Pre Sorted Requests" << endl;
      cout << "Start Time " << "End Time " << "Weight " << "Compatible Job" << endl;
      int number_of_jobs = my_requests.size();
      for(int i = 0; i < number_of_jobs; ++i) {
        cout << my_requests.at(i).name << " " << my_requests.at(i).startValue << " " << my_requests.at(i).finishValue << " "<< my_requests.at(i).Weight <<  " " << my_requests.at(i).compatibleJob << endl;
      }
      // sort jobs by finish times so that  f1 <= f2 <= ... <= fn.
      // using built in function from c++
      //This function is used to sort the elements in the range in ascending order.
      sort(my_requests.begin(), my_requests.end(), compareJobs);

      cout << endl;
    //  cout << "Post Sorted Requests" << endl;
      //for(int i = 0; i < number_of_jobs; ++i) {
      //  cout <<my_requests.at(i).name << " " <<  my_requests.at(i).startValue << " " << my_requests.at(i).finishValue << " "<< my_requests.at(i).Weight << endl;
      //}
      // find compatible jobs
      // Calculate p(j) for each entry
      for (int i = number_of_jobs - 1; i >= 0; i--) {
        int compatibleInterval = findNonOverLappingPair(my_requests, i);
        if(compatibleInterval != -1){
          my_requests[i].compatibleJob = compatibleInterval + 1;
        }
        else{
          my_requests[i].compatibleJob = 0;
        }
      }

      cout << "Post Sorted Array after addition of Compatible Profits" << endl;
      cout << "Start Time " << "End Time " << "Weight " << "Compatible Job" << endl;
      for(int i = 0; i < number_of_jobs; ++i) {
        cout << my_requests.at(i).name << " " << my_requests.at(i).startValue << " " << my_requests.at(i).finishValue << " "<< my_requests.at(i).Weight << " " <<  my_requests.at(i).compatibleJob << endl;
      }
    // Output Solution
    cout << "The Optimal Schedule is: " << endl;
    iterativeCompOpt(my_requests);
    cout << endl;

    myFile.close();
    return 0;
}
