#include <iostream>
#include <vector>
using namespace std;
int maxind(vector<int> cost)
{
  int m = 0;
  int n = cost.size();
  for (int i = 0; i < n; i++)
  {
    if (cost[i] > cost[m])
    {
      m = i;
    }
  }
  return m;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  if(capacity==0 || weights.empty() ==1){
    return 0;
  }
  int m = maxind(values);
  float amount = min(weights[m],capacity);
  if(capacity < (amount + weights[m])){
    value = values[m] *(float)(amount/weights[m]);
  }
  /*else{
    value = values[m] *(float)(amount/weights[m]);
  }*/
  values.erase(values.begin() + m);
  weights.erase(weights.begin() + m);
  return (value +get_optimal_value(capacity,weights,values));
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
