#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * A row class in which we will be basically store two values in it as :-
 * (.)Firstly we will store the count of the soldier.
 * (.)Secondly we will be storing the index position on the row.
 */
class Row {
public:
    int soldiers;
    int index;

    Row(int soldi, int idx) {
        this->index = idx;
        this->soldiers = soldi;
    }

    bool operator < (const Row &obj) const {
        if(this->soldiers == obj.soldiers)  return this->index > obj.index;
        return this->soldiers > obj.soldiers;
    }
};

void weakestKSoldiers(vector<vector<int>> matrix, int k) {
    //STEP 1: Is to create the vector of Row
    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++) {
        int count = 0; //Soldier count
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(count, i));
    }

    //STEP 2: Is to build the Priority Queue
    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0; i<k; i++) {
        cout<<"Row = "<<pq.top().index<<endl;
        pq.pop();
    }

    
}

int main() {
    vector<vector<int>> matrix = {{1,1,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}};
    int k = 2;

    weakestKSoldiers(matrix, k);

    return 0;
}