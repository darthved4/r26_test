# R26_test

<p align="center">
  <img src="https://github.com/teamrudra/r26_test/blob/main/misc/rover.webp" width="480" height="480"/>

#### Some Instructions
1. You may use any online resources, datasheets, or documentation needed, but be mindful of your time and stay focused on the task.
2. The duration of the test is 90 mins from 5:15pm to 6:45 pm.
3. There will be a MCQ test conducted [here](https://rudra26test.vercel.app/)
4. There are 4 tasks in the tests. Complete all of them.
5. In case you are not able to complete all the tasks, do upload whatever you are able to.
6. In the `README.md` of your repository include your thought process, places where you got stuck, where you used the help of AI, google or other online resources.
7. Even if you are not able to solve anything, do fill the readme and what your thought process would have been.
8. Carefully read the instructions to implement the required functionality.
9. Install [mingw(c compiler)](https://www.mingw-w64.org/downloads/#w64devkit) and [git](https://git-scm.com/downloads) if you haven't already done it.
10. After finishing your test, provide the link to your forked repository in the google form provided at the end.

### Aim/Objective: To decode GPS data of start and goal position, and create a path planning algorithm which computes an optimal path over a predefined gridmap

## Description
You are implementing code to decode GPS position data, received from a u-blox GNSS module on-board a rover (check out the [datasheet](https://drive.google.com/file/d/1rOcPxpP-3JE8l39kBMiQV6KKe8B6zlDf/view)). You are given the current/start position of the rover and the goal position where the rover has to reach, your goal is to develop a path planning algorithm to traverse over a pre-defined gridmap and generate necessary odometry commands (total time & angle traversed) to guide the rover along the generated path. 

### Task 0: Fork the provided repository and ensure it is set to PUBLIC so we can access and assess your work.
### Task 1: Decoding gps data (in ubx format) from u-blox reciever.
Working with UBX format and extracted relevant navigation data for use in the planner.
### Task 2: Develop a path planning algorithm to traverse over a gridmap.
Implemented a grid-based path planner that computes an optimal route from start to goal.
### Task 3: Generate odometry commands to guide the rover along the generated path.
Converted the path into motion commands (direction and timing) based on wheel parameters.
### Task 4: Compile and run the code.
Verified the workflow on sample inputs and ensured the project compiles successfully with g++.

#### Code
1. [src/main.cpp](src/main.cpp): Code for running the test.
2. [src/ublox_reader.cpp](src/ublox_reader.cpp): Recitfy errors in this code to compute correct lat & lon coordinates.
3. [src/planning.cpp](src/planning.cpp): Complete the defined `Planner::pathplanning` function 
4. [src/odometry.cpp](src/odometry.cpp): Complete the defined `Odometry::computeCommands` function 

#### How to Compile & Check your code
(make sure you are in the root directory)   
1. Compile your code by running: `make build`
2. To check if your code is implemented correctly run: `make check`
   
If you are able to compile your code successfully you should see something like this on your screen:

```
*** Success: ***
--------------------------------------------
```

4. If your make check was unsuccesfull, you can clean your attempt by running `make clean`, review your implementation and repeat the previous steps.

# Solution
## Understanding
 
I have been given a task to decode the gps data from the repo, then to use the given sources to develop a path planning algorithm

i have looked and all the files and gotten a general understanding of how the project is structured.
lib folder has all the header files
src folder has cpp files with functions defined and the main.cpp file is the main program that calls all these functions and creates objects etc
test folder test cases where i can perhaps verify the final program. 

testcase.txt files are the UBX (hex bytes) format, have to decode this.

## Thought Process

Task 0: done forked and cloned the repo.

Task 1: UBX data has to be decoded, to see what part of the program is broken, ill try understanding the error statements. Turns out the error is caused by the ublox_reader.cpp file, it seems to be pointing at some wrong indices. checked where buffer was used elsewhere, found decodeUBX function, there seems to be an issue with it, buffer does not point at class field as mentioned.

## Implementation

Task 1: used chatGPT to help me run the program and figure out what the error means. understood the code and input file well (got to know input format, got help from google and datasheet)
fixed the field mismatches in ublox_reader to match the actual byte positions. 
fixed the indexing issue in the decodeUBX function; got correctly decoded output of gps lat,lon.

How did you decide to implement your solution.

Mention the details, such as the path planning & odometry how you tested it.

# Google Form
[Link to Repo Submission](https://docs.google.com/forms/d/e/1FAIpQLSdlVJ2LzP8wUOATRD804zDVL611rwwGMO1y_ecYu5aoV5YQfw/viewform)


<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/feynman-simple.jpg" width="600" height="600"/>
</p>
     
