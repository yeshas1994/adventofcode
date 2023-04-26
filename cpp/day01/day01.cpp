#include <iostream> 
#include <fstream>
#include <string> 
#include <array>

#include <queue>

int main(int argc, char** argv)
{
  if (argc < 2)
    throw std::runtime_error("Please input txt file --> ./day01 day01.txt");

  std::string fname = argv[1];

  std::cout << argv[1] << std::endl;

  std::fstream allCalories; 
  allCalories.open(fname);

  int max = -1;

  std::string curr;
  int curr_calories = 0;
  std::priority_queue<int> q;

  while (std::getline(allCalories, curr))
  {
    //printf("%s\n", curr.c_str());
    if (curr.empty())
    {
      q.push(curr_calories); 
      curr_calories = 0;
    }
    else
    {
      curr_calories += std::stoi(curr);
    }
  }
  
  int sum = 0;
  for (int i = 0; i < 3; i++)
  {
    std::cout << q.top() << std::endl;
    sum += q.top(); 
    q.pop();
  }

  std::cout << sum << std::endl;

  return 0;
}
