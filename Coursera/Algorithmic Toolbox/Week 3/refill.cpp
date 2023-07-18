#include <iostream>
#include <vector>
using namespace std;
int refuel(int location, vector<int> stops, int m, int d)
{
  int laststop;
  if (location + m >= d)
  {
    return 0;
  }
  if (stops.empty() == 1 || (stops[0]-location)>m)
  {
    return (-1);
  }
  laststop = location;
  while ((stops.empty() != 1) && (stops[0] - location) <= m)
  {
    laststop = stops[0];
    stops.erase(stops.begin());
  }
  if(refuel(laststop, stops, m, d)<0){
    return refuel(laststop, stops, m, d);
  }
  return 1+ refuel(laststop, stops, m, d);
}
int main()
{
  int n, m, d, location = 0;
  cin >> d >> m >> n;
  vector<int> stops(n+1);
  stops[0] = location;
  stops[n] = d;
  for (int i = 1; i < n; i++)
  {
    cin >> stops[i];
  }
  cout<<refuel(location, stops, m, d);
  return 0;
}