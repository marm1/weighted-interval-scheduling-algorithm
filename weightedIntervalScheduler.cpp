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
      int profit
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
      out << "Profit: " << Weight << endl;
      cout << endl;
    }
    int name;
    int startValue;
    int finishValue;
    int Weight;
    int Profit;
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

int computeOptWeight(vector<RequestRecord> &requests, int num_of_jobs){
  if(num_of_jobs == 0){
    return 0;
  }
  return maximum(computeOptWeight(num_of_jobs-1), requests[num_of_jobs].Weight + computeOptWeight(requests[num_of_jobs].Profit)));

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
      //calcluate p-values
      for(size_t i = 0; i < number_of_jobs; ++i) {
        for(size_t j = 1; j > 0; --j){
          if(my_requests.at(i).startValue >= my_requests.at(j).finishValue){
            my_requests.at(i).Profit = j;
          }
        }
      for(auto request:my_requests){
        request.display();
      }
      //Calculate the weighted interval schedule

      int memoArray[number_of_jobs];

      for(size_t i = 0; i < number_of_jobs; ++i) {

    myFile.close();
    return 0;
}
