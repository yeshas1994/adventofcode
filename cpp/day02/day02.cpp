#include <iostream> 
#include <fstream>
#include <string> 
#include <sstream> 
#include <array>

struct move
{
  std::string move;
  std::string moveBeats;
  std::string moveLoses;
  int points;
};

int modulo(int a, int b)
{
  return (a%b + b)%b;
}

int main(int argc, char** argv)
{
  if (argc < 2)
    throw std::runtime_error("Please input txt file --> ./day01 day01.txt");

  std::string fname = argv[1];
 
  std::array<std::string, 3> abc = {"A", "B", "C"};
  move moves[] = { {"A", "C", "B", 1}, {"B", "A", "C", 2}, {"C", "B", "A", 3} };

  std::fstream f; 
  f.open(fname);

  std::string curr;
  int score = 0;
  while (std::getline(f, curr))
  {
    if (curr.empty()) break;
    std::stringstream ss(curr);
    std::string event, opp;
    int us, them;
    ss >> opp >> event;

    for (int i = 0; i < 3; i++)
    {
      if (opp == abc[i])
      {
        if (event == "X")
        {
          score += modulo(i-1,3) + 1;
        }
        else if (event == "Y")
        {
          score += i + 1 + 3;
        }
        else
        {
          score += modulo(i+1,3) + 1 + 6;
        }
      }
    }

  } 
  std::cout << score << std::endl;

  return 0;
}

  /*part1
  while (std::getline(f, curr))
  {
    if (curr.empty()) break;
    std::stringstream ss(curr);
    std::string me, opp;
    int us, them;
    ss >> opp >> me;

    for (const move& m : moves)
    {
      if (me == m.move)
      {
        if (opp == m.moveLoses)
        {
          score += m.points;
        }
        else if (opp == m.moveBeats)
        {
          score += m.points + 6;
        }
        else
        {
          score += m.points + 3;
        }
      }
    }
    //std::cout << opp << them <<":" <<me << us << std::endl;

  }
  */


