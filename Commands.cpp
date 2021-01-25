#include "Commands.h"
using namespace std;

// returns -1 if robot with robotNum = r does not exist
int exists(vector<Robot> &robots, int r) {
  // find the robot with robotNum = r
  for (int i = 0; i < robots.size(); ++i)
    if (robots[i].robotNum == r)
      return i;
  // if not found return -1
  return -1;
}

void show(vector<Robot> robots){
  // sort the robots by ascending order of robot number using a lambda function
  sort(robots.begin(), robots.end(), [](Robot &a, Robot &b){ return a.robotNum < b.robotNum; });
  // print each robot in the same format as in the input file start.txt
  for(int i = 0; i < robots.size(); ++i)
    cout << robots[i].robotNum << " " << robots[i].team << " " << robots[i].x_coord << " " << robots[i].y_coord << '\n'; 
}

void travelled(vector<Robot> robots) {
  // sort the robots by distance travelled
  // if two robots have travelled the same distance, order them by robot number
  sort(robots.begin(), robots.end(), [](Robot &a, Robot &b){
      if (a.travelled < b.travelled) 
        return true;
      else if (a.travelled == b.travelled)
        return a.robotNum < b.robotNum;
      else
        return false;
      });
  // list all the robots
  // each line consists of the robot number and the distance travelled
  for (int i = 0; i < robots.size(); ++i)
    cout << robots[i].robotNum << " " << robots[i].travelled << '\n';
}

void within(vector<Robot> &robots, int n) {
  // res is the number of robots within n steps of the origin
  int res = 0;
  // count the number of robots within n steps of origin
  for (int i = 0; i < robots.size(); ++i)
    if(abs(robots[i].x_coord) + abs(robots[i].y_coord) <= n)
      ++res;
  // print the result
  cout << res << '\n';
}

void turnleft(vector<Robot> &robots, int ind){
  // turns the robot to the left
  if(robots[ind].direction == 'N')
    robots[ind].direction = 'W';
  else if(robots[ind].direction == 'W')
    robots[ind].direction = 'S';
  else if(robots[ind].direction == 'S')
    robots[ind].direction = 'E';
  else
    robots[ind].direction = 'N';
}

void turnright(vector<Robot> &robots, int ind){
  // turns the robot to the right
  if(robots[ind].direction == 'N')
    robots[ind].direction = 'E';
  else if(robots[ind].direction == 'E')
    robots[ind].direction = 'S';
  else if(robots[ind].direction == 'S')
    robots[ind].direction = 'W';
  else
    robots[ind].direction = 'N';
}

void move(vector<Robot> &robots, int ind, int r){
  // calculate the possible new coordinates
  int x = robots[ind].x_coord, y = robots[ind].y_coord;
  if (robots[ind].direction == 'W')
    x -= 1;
  else if (robots[ind].direction == 'E')
    x += 1;
  else if (robots[ind].direction == 'N')
    y += 1;
  else
    y -= 1;

  // check if there is another robot in front of our robot
  // if there is an enemy robot -> remove that robot then move
  // if there is a robot from out team -> don't move at all
  // if there is nothing in front then move
  int test =- 1;
  for (int i = 0; i < robots.size(); ++i) {
    if (robots[i].x_coord == x && robots[i].y_coord == y)
      test = i;
  }
  // if 'test' at this point is not equal to -1 that means there is another robot on those coordinates
  // is it our robot or our team?
  if (test != -1 && (robots[ind].robotNum == robots[test].robotNum || robots[ind].team == robots[test].team))
    return;
  // there is a robot that needs to be deleted
  if (test != -1){
    robots.erase(robots.begin() + test);
    // update the index
    ind = exists(robots, r);
  }
  // update our robot's coordinates
  robots[ind].x_coord = x;
  robots[ind].y_coord = y;
  // update the distance travelled
  ++robots[ind].travelled;
}
