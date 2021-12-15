# P3 -- Parking lot software by pgroup-09

[![Build Status](https://focs.ji.sjtu.edu.cn:2222/api/badges/ENGR151-21/pgroup-09/status.svg)](https://focs.ji.sjtu.edu.cn:2222/ENGR151-21/pgroup-09)

## Workflow

Clone and setup your identity for this git repo
```
git clone ssh://git@focs.ji.sjtu.edu.cn:2222/ENGR151-21/your_pgroup_repo.git
cd your_pgroup_repo
git config user.name "studentid"
git config user.email "sjtu email"
```

### Development process

1. each student work on a different branch
2. when a task or feature is completed, issue a pull request to `dev` branch
3. carefully test your work on the `dev` branch, and when all bugs have been fixed issue a PR to `master`
4. if at any stage you get stuck with a merge conflict contact the teaching team

Ways to avoid merge conflicts:

- when sharing the work avoid overlap
- ensure each student work on different functions/classes
- as soon as you have finished working for the day push to your personal branch
- as soon as you have completed a task (eg. ufo completed) issue a PR to `dev`

Name your files as you wish and update `src/Makefile` and/or `src/CMakeLists.txt` accordingly

### Final recommendations

- Do not wait the last minute to get started
- If after a few days you have not found your teammates, please contact the teaching team
- At the beginning spend much more time discussing and designing your software than coding

All along the project, meet with your teammates on a regular basis and discuss your progress. If you meet any issue contact the teaching team as early as possible.

## Content

### Contributor

- Liu Yiming
- Yuan Jiale
- Gan hanyu
- Liu Jiaren

Liu Yiming and Yuan Jiale finished part 2--interstellar parking lot and give some proposals on part 1.

Gan hanyu and Liu Jiaren designed and worked on part 1--regular parking lot and later Liu Yiming finished it.

Liu Jiaren finished part1 of README and Yuan Jiale finished part2 of README.

## Description of the project

### Part 1

- This part is a general parking place. Four kind of vehicles -- car, van, motor and bike can enter this parking area.

- We have two mode for the user to run, you will be asked to choose one mode when you run part 1.

- The first mode is the demo mode, which means the floor number and slot number of each floors are all randomly defined in the beginning.

- In the second mode. the user can input the floor number and the slot number every slot.

- Different types of vehicles need to pay with different price, and this will be shown when the program start.

- The price system is similar to the real life, which means that if you park for 1.5hr, you have to pay for 2hr's parking fee.

- In this system, we just set one second as ten minutes.

- The start time will be set up as the time the user start the program, and then the time system will add 10 minutes every second.

- Every second, a new vehicle will be generated if there is such an empty slot to park it, and the program will check whether there is vehicles to leave the parking area.

- Every slot has its own tpye of vehicle to park, which means that different types of vehicle won't be sent to the same slot.

- The enter ticket will be printed when the vehicle enter, and it will show the entertime, the type of vehicle, the slot it will park to.

- The departure ticket will be print when a vehicle leaves, and the parking time, the price, the type of vehicle will be printed.

- After 60 seconds, which means 10 hours in the program, the program will automaticly stop.

### Part 2

- Unless all the slots are occupied, vehicles will randomly generated after each period of time at the entrance of the parking lot, except teleporters. The barrier at the entrance will open for these vehicles and close after they enter. Each vehicle will randomly choose a slot and move smoothly to the slot before it smoothly reverse into the slot.

- For Car, it has a flag above, which will move up and down while the car is moving.

- For UFO, it will spin all the time.

- For spacecraft, it will zoom in and out all the time.

- For teleporter, it will randomly appear in a slot and changing color and the number of sides as time goes by.

## How to run the project

- Run the command `make` on the Linux server to use Makefile to compile the whole project

- Run the command `./pms` on the Linux server to run part 1 of the project.

- Run the command `./ipa` (followed by option `-n k` here k is a specific number input by user to decide the number of slot of each line) on the Linux server to run part 2 of the project.

- Run the command `make clean` on the Linux server to clean the compiled executable file.

## Bonuses

- Polygon teleporters, with the number of sides changing over time.

- Add a small flag on the car, let it move up and down while the car is driving forward.

- Use singleton class to avoid a very long drawing function that continuously creates (destroys) objects.

- Something we think creative:

1. We design two base unit vector--`x_dir` and `y_dir` as the attributes of class Vehicle to indicate the orientation of a Vehicle. All Vector (x0,y0) can be reset as (x_dir * x0,y_dir * y0) and when rotating we only need to rotate the `x_dir` and `y_dir`.

2. We design several statuses for each Vehicle in a enumeration. Each status corresponds to the number of steps the Vehicle will cover under this status, a velocity of the Vehicle and an angle the Vehicle should rotate in each step. All the number of steps, the velocity and the angle are stored in arrays. The Vehicle will move and rotate according to these arrays.

## Bugs and something to improve

### Bugs

### Something to improved

## Function introduction

## Something should be mention (important)

### some changes on the codes given in p3.pdf

- We remove the method `move()`, `rotate()` and `zoom()` in class Figure and add `move()` and `rotate()` in class Vehicle, since `zoom()` is not necessary for all kinds of vehicles and ColoredFig doesn't need all of these three methods under our design.

- As mentioned in Bonus part above, we add attributes `x_dir` and `y_dir` in type of Vec in class Vehicle, and thus we change the parameter of method `move()` from `Vec dir` to `double v` since the direction of the current vehicle has been stored in itself.

- We remove the class Quadrilateral since it make no sense in our design

- We design the class Teleporter as a derived class of Vehicle rather than Rectangle to manage it under the vector of pointers of Vehicle along with other normal vehicles using the idea of polymorphism.
