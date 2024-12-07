#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void itineraryFromTickets(unordered_map<string, string>tickets) {
    //STEP 1: The first step is to start the starting point from where our journey should take place.
    unordered_set<string> to_set;
    for(auto ticket: tickets) { //Pairs are in the form of <from, to>
        to_set.insert(ticket.second); //Inserting the ticket's to value into the set
    }

    string start = ""; //Took a string start for storing the start value of the string

    //The starting point will be that value which exsits in the from but not in to.
    for(auto ticket: tickets) { //For this we looped our map once again.
        //And this time we just ensured that which value doesn't exists in the loop we took it out.
        if(to_set.find(ticket.first) == to_set.end()){
            start = ticket.first; //Starting point is recieved
            break;
        }
    }

    //STEP 2: Wenned to print the tour plan
    while(tickets.count(start) != 0) {
        cout<<start<<" -> ";
        start = tickets[start];
    }
    cout<<start<<endl;

    return;
}

int main() {
    unordered_map<string,string> tickets;
    tickets["Chennai"] = "Bangaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    itineraryFromTickets(tickets);

    return 0;
}