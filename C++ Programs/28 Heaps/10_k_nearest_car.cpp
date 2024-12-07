#include<iostream>
#include<queue>
using namespace std;

class Car {
public:
    int idx;
    int distSqr;

    Car(int i, int dist) {
        this->idx = i;
        this->distSqr = dist;
    }

    bool operator < (const Car &obj) const {
        return this->distSqr > obj.distSqr; //minHeap
    }
};

void kNearestCar(vector<pair<int, int>> pos, int k) {
    /**
     * For each car we need to store two values - 
     * one is the index value because eventually we need to return the index of the car. Because we need to maintain this index value while fixing.
     * And second is the distance (Actually the square of the distance) from origin to the car point.
     */

    //STEP 1: Before making a Priority Queue we will first make a vector of cars that will hold all the car values.
    vector<Car> cars; //And in the cars for a single car we would have the index and square-distance for each car values.
    //The reason for not using the Priority Queue first is becasue

    for(int i=0; i<pos.size(); i++) { //So here we have build our cars vector which will store the car object in it and each car object stores two properties as the index value of the car and the distance-square of the object.
        //For building our cars vector it takes a time compexity of O(n).
        int distSq = (pos[i].first*pos[i].first) + (pos[i].second*pos[i].second);
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); //O(n)

    for(int i=0; i<k; i++) { //O(k * log n + n)
        cout<<pq.top().idx<<endl; //O(1)
        pq.pop(); //O(log n)
    }
}

int main() {
    //Enterd the position of the cars.
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int k = 2; //The values how many near cars we want to calculate.

    kNearestCar(pos, k);

    return 0;
}