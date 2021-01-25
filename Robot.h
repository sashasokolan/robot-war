#ifndef ROBOT_H
#define ROBOT_H

class Robot {
  public:
    // robots, teams and travelled are identified by positive whole numbers
    unsigned int robotNum, team, travelled;

    // coordinates are whole numbers, but may be negative
    int x_coord, y_coord;

    // there are four possible directions
    char direction;

    // constructor
    Robot(unsigned int rNum, unsigned int t, int x, int y) : 
      robotNum{rNum}, team{t}, x_coord{x}, y_coord{y} {
        travelled = 0;
        direction = 'N';
      };

    // destructor
    ~Robot() {};
};

#endif