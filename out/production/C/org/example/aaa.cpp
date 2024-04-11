#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include<math.h>
using namespace std;

int main()
{
    vector<double> p = {51,62,69,64,65,56,58,57,55};
    vector<double> h = {167,182,176, 173,172,174,169,173,170};
    vector<double> weight_for_mknn(p.size());

    double max_dist = 6.7082;
    double min_dist = 1.41421; 
    for (int i = 0; i < p.size(); i++)
    {
       double temp = sqrt(pow((57 - p[i]), 2) + pow((170 - h[i]), 2));
     

        double weight = (max_dist - temp) / (max_dist - min_dist);

            cout << weight;
            cout << "\n";
    }
    return 0;
    
}