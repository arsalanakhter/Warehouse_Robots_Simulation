#include <iostream>
#include <thread>
#include <vector>

#include "Vehicle.h"
#include "Street.h"
#include "Intersection.h"
#include "Graphics.h"


// Paris
void createTrafficObjects_Paris(std::vector<std::shared_ptr<Street>> &streets, std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string &filename, int nVehicles)
{
    // assign filename of corresponding city map
    filename = "../data/paris.jpg";

    // init traffic objects
    int nIntersections = 9;
    for (size_t ni = 0; ni < nIntersections; ni++)
    {
        intersections.push_back(std::make_shared<Intersection>());
    }

    // position intersections in pixel coordinates (counter-clockwise)
    intersections.at(0)->setPosition(385, 270);
    intersections.at(1)->setPosition(1240, 80);
    intersections.at(2)->setPosition(1625, 75);
    intersections.at(3)->setPosition(2110, 75);
    intersections.at(4)->setPosition(2840, 175);
    intersections.at(5)->setPosition(3070, 680);
    intersections.at(6)->setPosition(2800, 1400);
    intersections.at(7)->setPosition(400, 1100);
    intersections.at(8)->setPosition(1700, 900); // central plaza

    // create streets and connect traffic objects
    int nStreets = 8;
    for (size_t ns = 0; ns < nStreets; ns++)
    {
        streets.push_back(std::make_shared<Street>());
        streets.at(ns)->setInIntersection(intersections.at(ns));
        streets.at(ns)->setOutIntersection(intersections.at(8));
    }

    // add vehicles to streets
    for (size_t nv = 0; nv < nVehicles; nv++)
    {
        vehicles.push_back(std::make_shared<Vehicle>());
        vehicles.at(nv)->setCurrentStreet(streets.at(nv));
        vehicles.at(nv)->setCurrentDestination(intersections.at(8));
    }
}

// NYC
void createTrafficObjects_NYC(std::vector<std::shared_ptr<Street>> &streets, std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string &filename, int nVehicles)
{
    // assign filename of corresponding city map
    filename = "../data/nyc.jpg";

    // init traffic objects
    int nIntersections = 6;
    for (size_t ni = 0; ni < nIntersections; ni++)
    {
        intersections.push_back(std::make_shared<Intersection>());
    }

    // position intersections in pixel coordinates
    intersections.at(0)->setPosition(1430, 625);
    intersections.at(1)->setPosition(2575, 1260);
    intersections.at(2)->setPosition(2200, 1950);
    intersections.at(3)->setPosition(1000, 1350);
    intersections.at(4)->setPosition(400, 1000);
    intersections.at(5)->setPosition(750, 250);

    // create streets and connect traffic objects
    int nStreets = 7;
    for (size_t ns = 0; ns < nStreets; ns++)
    {
        streets.push_back(std::make_shared<Street>());
    }

    streets.at(0)->setInIntersection(intersections.at(0));
    streets.at(0)->setOutIntersection(intersections.at(1));

    streets.at(1)->setInIntersection(intersections.at(1));
    streets.at(1)->setOutIntersection(intersections.at(2));

    streets.at(2)->setInIntersection(intersections.at(2));
    streets.at(2)->setOutIntersection(intersections.at(3));

    streets.at(3)->setInIntersection(intersections.at(3));
    streets.at(3)->setOutIntersection(intersections.at(4));

    streets.at(4)->setInIntersection(intersections.at(4));
    streets.at(4)->setOutIntersection(intersections.at(5));

    streets.at(5)->setInIntersection(intersections.at(5));
    streets.at(5)->setOutIntersection(intersections.at(0));

    streets.at(6)->setInIntersection(intersections.at(0));
    streets.at(6)->setOutIntersection(intersections.at(3));

    // add vehicles to streets
    for (size_t nv = 0; nv < nVehicles; nv++)
    {
        vehicles.push_back(std::make_shared<Vehicle>());
        vehicles.at(nv)->setCurrentStreet(streets.at(nv));
        vehicles.at(nv)->setCurrentDestination(intersections.at(nv));
    }
}


// Warehouse
void createTrafficObjects_Warehouse(std::vector<std::shared_ptr<Street>> &streets, std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string &filename, int nVehicles)
{
    // assign filename of corresponding map
    filename = "../data/warehouse_layout.jpeg";

    // init traffic objects
    int nIntersections = 12;
    for (size_t ni = 0; ni < nIntersections; ni++)
    {
        intersections.push_back(std::make_shared<Intersection>());
    }

    // position intersections in pixel coordinates
    intersections.at(0)->setPosition(100, 90);
    intersections.at(1)->setPosition(600, 90);
    intersections.at(2)->setPosition(1050, 90);
    intersections.at(3)->setPosition(1550, 90);
    intersections.at(4)->setPosition(100, 350);
    intersections.at(5)->setPosition(600, 350);
    intersections.at(6)->setPosition(1050, 350);
    intersections.at(7)->setPosition(1550, 350);
    intersections.at(8)->setPosition(100, 600);
    intersections.at(9)->setPosition(600, 600);
    intersections.at(10)->setPosition(1050, 600);
    intersections.at(11)->setPosition(1550, 600);

    // create streets and connect traffic objects
    int nStreets = 17;
    for (size_t ns = 0; ns < nStreets; ns++)
    {
        streets.push_back(std::make_shared<Street>());
    }

    streets.at(0)->setInIntersection(intersections.at(0));
    streets.at(0)->setOutIntersection(intersections.at(1));
    streets.at(0)->setStreetID(0);

    streets.at(1)->setInIntersection(intersections.at(1));
    streets.at(1)->setOutIntersection(intersections.at(2));
    streets.at(1)->setStreetID(1);

    streets.at(2)->setInIntersection(intersections.at(2));
    streets.at(2)->setOutIntersection(intersections.at(3));
    streets.at(2)->setStreetID(2);


    streets.at(3)->setInIntersection(intersections.at(4));
    streets.at(3)->setOutIntersection(intersections.at(0));
    streets.at(3)->setStreetID(3);

    streets.at(4)->setInIntersection(intersections.at(5));
    streets.at(4)->setOutIntersection(intersections.at(1));
    streets.at(4)->setStreetID(4);

    streets.at(5)->setInIntersection(intersections.at(6));
    streets.at(5)->setOutIntersection(intersections.at(2));
    streets.at(5)->setStreetID(5);

    streets.at(6)->setInIntersection(intersections.at(7));
    streets.at(6)->setOutIntersection(intersections.at(3));
    streets.at(6)->setStreetID(6);


    streets.at(7)->setInIntersection(intersections.at(4));
    streets.at(7)->setOutIntersection(intersections.at(5));
    streets.at(7)->setStreetID(7);

    streets.at(8)->setInIntersection(intersections.at(5));
    streets.at(8)->setOutIntersection(intersections.at(6));
    streets.at(8)->setStreetID(8);

    streets.at(9)->setInIntersection(intersections.at(6));
    streets.at(9)->setOutIntersection(intersections.at(7));
    streets.at(9)->setStreetID(9);


    streets.at(10)->setInIntersection(intersections.at(8));
    streets.at(10)->setOutIntersection(intersections.at(4));
    streets.at(10)->setStreetID(10);

    streets.at(11)->setInIntersection(intersections.at(9));
    streets.at(11)->setOutIntersection(intersections.at(5));
    streets.at(11)->setStreetID(11);

    streets.at(12)->setInIntersection(intersections.at(10));
    streets.at(12)->setOutIntersection(intersections.at(6));
    streets.at(12)->setStreetID(12);

    streets.at(13)->setInIntersection(intersections.at(11));
    streets.at(13)->setOutIntersection(intersections.at(7));
    streets.at(13)->setStreetID(13);



    streets.at(14)->setInIntersection(intersections.at(8));
    streets.at(14)->setOutIntersection(intersections.at(9));
    streets.at(14)->setStreetID(14);

    streets.at(15)->setInIntersection(intersections.at(9));
    streets.at(15)->setOutIntersection(intersections.at(10));
    streets.at(15)->setStreetID(15);

    streets.at(16)->setInIntersection(intersections.at(10));
    streets.at(16)->setOutIntersection(intersections.at(11));
    streets.at(16)->setStreetID(16);



    // add vehicles to streets
    for (size_t nv = 0; nv < nVehicles; nv++)
    {
        vehicles.push_back(std::make_shared<Vehicle>());
        vehicles.at(nv)->setCurrentStreet(streets.at(nv));
        vehicles.at(nv)->setCurrentDestination(intersections.at(nv));
    }
}

/* Main function */
int main()
{
    /* PART 1 : Set up traffic objects */

    // create and connect intersections and streets
    std::vector<std::shared_ptr<Street>> streets;
    std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::string backgroundImg;
    int nVehicles = 1;
    createTrafficObjects_Warehouse(streets, intersections, vehicles, backgroundImg, nVehicles);

    /* PART 2 : simulate traffic objects */

    // simulate intersection
    std::for_each(intersections.begin(), intersections.end(), [](std::shared_ptr<Intersection> &i) {
        i->simulate();
    });

    // simulate vehicles
    std::for_each(vehicles.begin(), vehicles.end(), [](std::shared_ptr<Vehicle> &v) {
        v->simulate();
    });

    /* PART 3 : Launch visualization */

    // add all objects into common vector
    std::vector<std::shared_ptr<TrafficObject>> trafficObjects;
    std::for_each(intersections.begin(), intersections.end(), [&trafficObjects](std::shared_ptr<Intersection> &intersection) {
        std::shared_ptr<TrafficObject> trafficObject = std::dynamic_pointer_cast<TrafficObject>(intersection);
        trafficObjects.push_back(trafficObject);
    });

    std::for_each(vehicles.begin(), vehicles.end(), [&trafficObjects](std::shared_ptr<Vehicle> &vehicles) {
        std::shared_ptr<TrafficObject> trafficObject = std::dynamic_pointer_cast<TrafficObject>(vehicles);
        trafficObjects.push_back(trafficObject);
    });

    // draw all objects in vector
    Graphics *graphics = new Graphics();
    graphics->setBgFilename(backgroundImg);
    graphics->setTrafficObjects(trafficObjects);
    graphics->simulate();
}
