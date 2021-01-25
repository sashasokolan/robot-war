#include "Robot.h"
#include "Commands.h"
#include <fstream>
#include <string>
using namespace std;

int main(){
  // vector used to store robot info
  vector<Robot> robots;
  // input file stream
  ifstream start;
  // robot number and team number are positive whole numbers
  unsigned int robotNum, team;
  // coords are whole numbers but can be negative
  int x_coord, y_coord;

  // check if the file is open
  start.open("start.txt");
  if (start.is_open() == false) {
    cout << "start.txt is not open" << '\n';
    return 0;
  }
  // get all info from start.txt and push_back those robots into a vector<Robot>
  while (start >> robotNum >> team >> x_coord >> y_coord)
    robots.push_back(Robot(robotNum, team, x_coord, y_coord));
  // close the file start.txt
  start.close();
  
  ifstream commands;
  string command;
  // check if the file is open
  commands.open("commands.txt");
  if (commands.is_open() == false) {
    cout << "commands.txt is not open" << '\n';
    return 0;
  }
  // get the commands
  while (commands >> command) {
    //std::cout << command << std::endl;
    if (command == "show")
      show(robots);
    else if (command == "travelled")
      travelled(robots);
    else if (command == "within") {
      int n;
      commands >> n;
      within(robots, n);
    } else {
      int r;
      commands >> r;
      int pos = exists(robots, r);
      // robot r does not exist -> ignore command
      if (pos == -1)
        continue;
      if (command == "turnleft")
        turnleft(robots, pos);
      else if (command == "turnright")
        turnright(robots, pos);
      else if (command == "move")
        move(robots, pos, r);
    }
  }
  // close the file
  commands.close();

  return 0;
}
