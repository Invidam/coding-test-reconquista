#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef pair<int, int> coord;

const pair<coord, coord> INVALID = pair(pair(10'001, 10'001), pair(-10'001, -10'001));

int TC, N;

vector<coord> coords;


void init(vector<coord> &sortedByXAll, vector<coord> &sortedByYAll) {
    cin >> N;

    coords = vector<coord>(N);

    for (int j = 0; j < N; ++j) {
        cin >> coords[j].first;
        cin >> coords[j].second;
    }

    sortedByXAll = coords;

    sort(sortedByXAll.begin(), sortedByXAll.end(), [](const coord &a, const coord &b) -> bool {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });

    sortedByYAll = coords;
    sort(sortedByYAll.begin(), sortedByYAll.end(), [](const coord &a, const coord &b) -> bool {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
}

int getDistanceSquare(const coord &a, const coord &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool isBigger(const coord &a, const coord &b) {
    return a.first == b.first ? a.second > b.second : a.first > b.first;
}

pair<coord, coord> getClosestCoordByBruteForce(const vector<coord> &sortedX) {
    int minDiffSquare = getDistanceSquare(INVALID.first, INVALID.second);

    pair<coord, coord> ret = INVALID;

    for (int i = 0; i < sortedX.size(); ++i) {
        for (int j = i + 1; j < sortedX.size(); ++j) {
            int diffSquare = getDistanceSquare(sortedX[i], sortedX[j]);

            if (diffSquare < minDiffSquare) {
                minDiffSquare = diffSquare;
                ret = pair(sortedX[i], sortedX[j]);
            }
        }
    }

    return ret;
}

bool isOverRange(const vector<coord> &ranged, int i, int gap) { return i + gap >= ranged.size(); }

pair<coord, coord> getClosestPairBySplit(const vector<coord> &sortedX, const vector<coord> &sortedY,
                                         int bestDistance,
                                         pair<coord, coord> &bestPair) {
    int mid = sortedX.size() / 2;
    vector<coord> ranged;

    coord midCoord = sortedX[mid];

    for (const auto &item: sortedY) {
        if ((item.first - midCoord.first) * (item.first - midCoord.first) >= bestDistance) continue;
        ranged.emplace_back(item);
    }

    for (int i = 0; i < ranged.size(); ++i) {
        for (int gap = 1; gap <= 8; ++gap) {
            if (isOverRange(ranged, i, gap)) {
                break;
            }

            int bestDistanceCand = getDistanceSquare(ranged[i], ranged[i + gap]);

            if (bestDistanceCand < bestDistance) {
                bestDistance = bestDistanceCand;
                bestPair = pair(ranged[i], ranged[i + gap]);
            }
        }
    }

    return bestPair;
}

bool canUseBruteForce(const vector<coord> &sortedX) { return sortedX.size() <= 3; }

vector<coord> updateRightSortedY(const vector<coord> &sortedX, const vector<coord> &sortedY) {
    int mid = sortedX.size() / 2;
    vector<coord> rightSortedY;

    for (const auto &elem: sortedY) {
        if (isBigger(elem, sortedX[mid])) {
            rightSortedY.emplace_back(elem);
        }
    }
    return rightSortedY;
}

vector<coord> updateLeftSortedY(const vector<coord> &sortedX, const vector<coord> &sortedY) {
    int mid = sortedX.size() / 2;
    vector<coord> leftSortedY;

    for (const auto &elem: sortedY) {
        if (!isBigger(elem, sortedX[mid])) {
            leftSortedY.emplace_back(elem);
        }
    }
    return leftSortedY;
}

pair<coord, coord> getClosestCoord(const vector<coord> &sortedX, const vector<coord> &sortedY) {
    if (canUseBruteForce(sortedX)) {
        return getClosestCoordByBruteForce(sortedX);
    }

    int mid = sortedX.size() / 2;

    vector<coord> leftSortedX(sortedX.begin(), sortedX.begin() + mid),
            rightSortedX(sortedX.begin() + mid, sortedX.end());
    vector<coord> leftSortedY = updateLeftSortedY(sortedX, sortedY),
            rightSortedY = updateRightSortedY(sortedX, sortedY);

    const pair<coord, coord> retL = getClosestCoord(leftSortedX, leftSortedY);
    const pair<coord, coord> retR = getClosestCoord(rightSortedX, rightSortedY);

    int bestDistance = min(getDistanceSquare(retL.first, retL.second), getDistanceSquare(retR.first, retR.second));
    pair<coord, coord> bestPair = getDistanceSquare(retL.first, retL.second) == bestDistance ? retL : retR;

    return getClosestPairBySplit(sortedX, sortedY, bestDistance, bestPair);
}

int main() {
    FAST_IO;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        vector<coord> sortedByXAll;
        vector<coord> sortedByYAll;

        init(sortedByXAll, sortedByYAll);

        pair<coord, coord> resultCoords = getClosestCoord(sortedByXAll, sortedByYAll);

        printf("%.2f\n", sqrt(getDistanceSquare(resultCoords.first, resultCoords.second)));

    }
}
