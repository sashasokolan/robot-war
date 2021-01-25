#ifndef COMMANDS_H
#define COMMANDS_H

#include "Robot.h"
#include <algorithm>
#include <vector>
#include <iostream>

int exists(std::vector<Robot> &robots, int r);

void show(std::vector<Robot> robots);

void travelled(std::vector<Robot> robots);

void within(std::vector<Robot> &robots, int n);

void turnleft(std::vector<Robot> &robots, int ind);

void turnright(std::vector<Robot> &robots, int ind);

void move(std::vector<Robot> &robots, int ind, int r);

#endif