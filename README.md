# Warhouse Robots Concurrent Traffic Simulation

<img src="data/warehouse_layout.jpeg"/>

This is the final project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The project builds upon the Traffic Simulation Project in the Concurrency module of the nano-degree program. The project simulates robots in a warehouse setting where the robots have to go from one location to the other in the warehouse. They have to wait at the intersections so that only one robot passes through the intersection at a time. They also have to respect a traffic light at the intersection before entering the intersection. The vehicles also attempt to reach a destination location to pick up things in the warehouse in the shortest possible manner by looking at the current available streets. Once they reach a destination  location, they come back to lower left corner (Street 16) for Drop-Off. This part of the code is in class Vehicle from line 100 - 180.

## Dependencies for Running Locally
* cmake >= 3.10.2
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.0
  * The OpenCV 4.0.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 7.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./traffic_simulation`.

## Rubrics Fulfileld by the Project
* **README (All Rubric Points REQUIRED)**
  * A README with instructions is included with the project
  * The README indicates which project is chosen.
    * Warehouse Robots Concurrent Traffic Simulation.
  * The README includes information about each rubric point addressed.
* **Compiling and Testing (All Rubric Points REQUIRED)**
  * The submission must compile and run.
    * Tested on Ubuntu 18.04 LTS (Bionic Beaver) with dependencies as mentioned above.
* **Loops, Functions, I/O**
  * The project demonstrates an understanding of C++ functions and control structures.
    * A variety of control structures are used in the project.
    * The project code is clearly organized into functions.
  * The project reads data from a file and process the data, or the program writes data to a file.
    * Reads data from `data/warehouse_layout.jpeg`.
* **Object Oriented Programming**
  * The project uses Object Oriented Programming techniques.
    * The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
  * Classes use appropriate access specifiers for class members.
    * All class data members are explicitly specified as public, protected, or private.
  * Classes abstract implementation details from their interfaces.
    * All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
  * Classes encapsulate behavior.
    * Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
  * Classes follow an appropriate inheritance hierarchy.
    * Inheritance hierarchies are logical. 
      * Classes `Vehicle`, `Intersection`, `Street` and `TrafficLight` are inherited from class `TrafficObject`.
      * Abstract classes are composed of pure virtual functions.
        * The `simulate()` function in class `TrafficObject` is pure virtual and needs implementation in each derived class.
  * Derived class functions override virtual base class functions.
    * One member function in an inherited class overrides a virtual base class member function.
      * The `simulate()` function in class `TrafficObject` is pure virtual and needs implementation in each derived class.
  * Templates generalize functions in the project.
    * One function is declared with a template that allows it to accept a generic parameter.
      * Functions `T MessageQueue<T>::receive()` and `void MessageQueue<T>::send(T &&msg)` in class `TrafficLight` are declared with a template
* **Memory Management**
  * The project makes use of references in function declarations.
    * At least two variables are defined as references, or two functions use pass-by-reference in the project code.
      * Function `void MessageQueue<T>::send(T &&msg)` in class `TrafficLight` receives an `lvalue` as a function argument.
      * The function `void TrafficLight::simulate()` is implemented by emplacing back a thread which passes the `&TrafficLight::cycleThroughPhases` as a referrence in the thread function.
  * The project uses smart pointers instead of raw pointers.
    * The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. The project does not use raw pointers.
      * The project uses a `shared_ptr` to pass around an object of type `MessageQueue<TrafficLightPhase>` in class `TrafficLight`.
* **Concurrency**
  * The project uses multithreading.
    * The project uses multiple threads in the execution.
      * A thread is started each time a vehicle queue is processed in function `Intersection::simulate()`
      * A thread is started each time an instance of `TrafficLight::cycleThroughPhases` is used in `TrafficLight::simulate()`
  * A promise and future is used in the project.
    * A promise and future is used to pass data from a worker thread to a parent thread in the project code.
      * A promise and future is used in `TrafficLight::cycleThroughPhases()` where a `_curentPhase` is sent through message queue and received in `TrafficLight::waitForGreen()`
  * A mutex or lock is used in the project.
    * A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock)` is used to protect data that is shared across multiple threads in the project code.
      * An `std::lock_guard<std::mutex>` is used in `WaitingVehicles::permitEntryToFirstInQueue()` in class `WaitingVehicles`. For this, the class `WaitingVehicels` also has a private member of type `std::mutex`.
  * A condition variable is used in the project.
    * A `std::condition_variable` is used in the project code to synchronize thread execution.
      * The `MessageQueue<T>::receive()` and `void MessageQueue<T>::send(T &&msg)` functions use the condition variable.
