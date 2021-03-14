// Author: Grecu Narcis

/* Explanation:
   To compute aproximation of Pi we will generate random points and we will use some probabilistic.
*  The probability for a point generated inside a square to be inside the inscribed circle of square is pi/4
*  since, if the radius of circle is r, then side of square will be 2*r, therefore the area of circle is pi*r*r and
*  area of square is 4*r*r. So the probability will be area of circle / area of square = pi/4.
*  Let P = number of total points, and C = number of points inside circle. Then P/C should be equal pi/4.
*  Since we are dealing with probabilistic this will be only an aproximation and we will get pi = 4*P/C.
*/

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

# define M_PI 3.14159265358979323846

using namespace std;
using namespace sf;

const int width = 600, height = 600;

RenderWindow screen(VideoMode(width + 10, height + 100), "Calculating Pi using probabilistic");

const int pointRadius = 5;

Font font;
Text valueOfPi, aproxOfPi;

int square(int x) {
    return x * x;
}

int isInside(CircleShape point) {
    int x = point.getPosition().x;
    int y = point.getPosition().y;

    return (square(x + pointRadius - width / 2) + square(y + pointRadius - height / 2)) <= 300 * 300;
}

CircleShape generatePoint() {
    CircleShape result;

    int x = rand() % width;
    int y = rand() % height;

    result.setPosition(x, y);
    result.setRadius(pointRadius);
    result.setOutlineThickness(1);
    result.setOutlineColor(Color::Magenta);
    
    if (isInside(result))
        result.setFillColor(Color::Red);
    else
        result.setFillColor(Color::Green);

    return result;
}

void init() {
    font.loadFromFile("arial.ttf");
    valueOfPi.setFont(font);
    valueOfPi.setCharacterSize(30);
    valueOfPi.setPosition(0, 610);
    valueOfPi.setFillColor(Color::White);
    valueOfPi.setString("Pi is: " + to_string(M_PI));

    aproxOfPi = valueOfPi;
    aproxOfPi.setPosition(0, 640);

    srand(time(0));
}

int main()
{ 
    init();
    vector<CircleShape> points;

    int pointsInside = 0, totalPoints = 0;

    while (screen.isOpen()) {
        Event e;
        while (screen.pollEvent(e)) {
            if (e.type == Event::Closed)
                screen.close();
        }

        points.push_back(generatePoint());
        totalPoints++;
        
        if (isInside(points[points.size() - 1]))
            pointsInside++;

        double pi = 4. * pointsInside / totalPoints;

        aproxOfPi.setString("Aproximation of Pi is: " + to_string(pi));

        screen.clear();

        screen.draw(aproxOfPi);
        screen.draw(valueOfPi);

        for (int i = 0; i < points.size(); i++) 
            screen.draw(points[i]);
        
        screen.display();
    }

    return 0;
}