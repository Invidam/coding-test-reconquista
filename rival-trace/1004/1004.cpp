#include <iostream>
#include <vector>

using namespace std;

// Problem site: https://https://www.acmicpc.net/problem/1004
class Coord {
public:
    int x;
    int y;

    Coord(int x, int y) : x(x), y(y) {}
};

class Planet {
public:
    Coord coord;
    int r;

    Planet(int x, int y, int r) : coord(Coord(x, y)), r(r) {}

    bool isInner(Coord &other) {
        int diffMult = (other.x - this->coord.x) * (other.x - this->coord.x) +
                       (other.y - this->coord.y) * (other.y - this->coord.y);
        return diffMult < (r * r);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;

    cin >> TC;

    int xTemp, yTemp;

    for (int i = 0; i < TC; ++i) {


        cin >> xTemp >> yTemp;
        Coord start = Coord(xTemp, yTemp);

        cin >> xTemp >> yTemp;
        Coord end = Coord(xTemp, yTemp);


        int n;

        cin >> n;

        vector<Planet> planets;


        for (int j = 0; j < n; ++j) {
            int rTemp;
            cin >> xTemp >> yTemp >> rTemp;

            planets.push_back(Planet(xTemp, yTemp, rTemp));
        }

        vector<Planet> startRanged, endRanged, totalRanged;

        for (int j = 0; j < n; ++j) {
            Planet curr = planets[j];

            if (curr.isInner(start) && curr.isInner(end)) {
                totalRanged.push_back(curr);
            } else if (curr.isInner(start)) {
                startRanged.push_back(curr);
            } else if (curr.isInner(end)) {
                endRanged.push_back(curr);
            }

        }

        cout << startRanged.size() + endRanged.size() << '\n';
    }


    return 0;
}

