
#include <iostream>
#include <iterator>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "point.hpp"
#include "roadmap.hpp"
#include "rmgenerator.hpp"
#include "model.hpp"
#include "agent.hpp"
#include "path.hpp"
#include "search.hpp"
#include "pf.hpp"

int main() {

    srand(time(NULL));

    double speed = 1.5;
    double noise_std = 0.000;
    double goal_radius = 0.3;
    double dt = 0.07;
    int num_samples = 20;
    std::list<Dodger::Agent *> agents;

    Dodger::StochasticAgent *ag = new Dodger::StochasticAgent(
        new Dodger::LinearModel(0, 0),
        new Dodger::CosModel(-8, 4, 0, 0),
        Dodger::Point(1, 2), noise_std);

    Dodger::StochasticAgent *ag2 = new Dodger::StochasticAgent(
        new Dodger::LinearModel(0, 0),
        new Dodger::CosModel(-8, 4, 0, 0),
        Dodger::Point(3, 2), noise_std);

    Dodger::StochasticAgent *ag3 = new Dodger::StochasticAgent(
        new Dodger::LinearModel(0, 0),
        new Dodger::CosModel(8, 4, 0, 0),
        Dodger::Point(0, 2), noise_std);

    Dodger::StochasticAgent *ag4 = new Dodger::StochasticAgent(
        new Dodger::LinearModel(0, 0),
        new Dodger::CosModel(8, 4, 0, 0),
        Dodger::Point(4, 2), noise_std);

    Dodger::StochasticAgent *ag5 = new Dodger::StochasticAgent(
        new Dodger::CosModel(10, 5, 0, 0),
        new Dodger::LinearModel(0, 0),
        Dodger::Point(2, 3), noise_std);

    Dodger::StochasticAgent *ag6 = new Dodger::StochasticAgent(
        new Dodger::CosModel(-10, 5, 0, 0),
        new Dodger::LinearModel(0, 0),
        Dodger::Point(2, 2), noise_std);

    Dodger::StochasticAgent *ag7 = new Dodger::StochasticAgent(
        new Dodger::CosModel(10, 5, 0, 0),
        new Dodger::LinearModel(0, 0),
        Dodger::Point(2, 1), noise_std);

    agents.push_back(ag);
    agents.push_back(ag2);
    agents.push_back(ag3);
    agents.push_back(ag4);
    agents.push_back(ag5);
    agents.push_back(ag6);
    agents.push_back(ag7);

    Dodger::Point start(2, 0);
    Dodger::Point goal(2, 4);

    Dodger::PF pf(agents, goal_radius, speed, dt, num_samples);

    Dodger::Path path = pf.get_path(start, goal);
    cout << Dodger::Search::json(path, agents) << endl;
}
