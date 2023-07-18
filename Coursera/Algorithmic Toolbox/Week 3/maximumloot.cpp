#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int maxind(vector<float> weights, vector<float> values)
{
  int max_i = 0;
  double max = 0;

  for(int i = 0; i< weights.size();i++)
  {
    if(weights[i] !=0 && (double) (values[i]/weights[i]) >max)
    {
      max = (double) values[i]/weights[i];
      max_i = i;
    } 
  }
  return max_i;

}
double maximumloot(float w,vector<float> weights,vector<float> values)
{
  double value = 0.0;
  for(int i =0;i<weights.size();i++)
  {
    if(w==0){
      return value;
    }
    int index = maxind(weights,values);
    float amount = min(weights[index], w);
    value += amount * (double) values[index]/weights[index];
    weights.erase(weights.begin()+index);
    w-=amount;
  }
  return value+maximumloot(w,values,weights);
}
/*int maximumloot(float w, vector<float> weight, vector<float> cost)
{
  if (w==0 || weight.size() == 0)
  {
    return 0;
  }
  float value=0;
  int m = maxind(cost);
  //cout<<m<<"{}\n";
  float a = min(weight[m], w);
  //cout<<a<<"<>\n";
  if (weight[m] <w){
  value = cost[m] * (a/weight[m]);
  //cout<<value<<"++\n";
  }
  
  cost.erase(cost.begin() + m);
  weight.erase(weight.begin() + m);
  //cout<<w-a<<"??\n";
  return (value + maximumloot(w, weight, cost));
}*/
int main()
{
  float n, w;
  cin >> n >> w;
  vector<float> cost(n);
  vector<float> weight(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cost[i]>>weight[i];
  }
  cout << maximumloot(w, weight, cost);
}