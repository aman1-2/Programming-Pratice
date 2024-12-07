/*
Create a User Class with Properties: id(private), username(public), and password(private).
Its id should be initialized in a parametrised constructor.
It should have Getter and Setter for the password.
*/

#include<iostream>
using namespace std;

class User{
    int id;
    string password;
public:
    string user_name;

    User(int id, string name){
        this->id = id;
        this->user_name = name;
    }

    void getPassword(){ //Getter
        cout<<"User: "<<this->user_name<<"'s password is: "<<this->password<<"\n";
        return;
    }

    void setPassword(){ //Setter
        string password;
        cout<<"Create a password for the User: "<<this->user_name<<": ";
        cin>>password;
        this->password = password;
        return;
    }

    void getDetails(){
        cout<<"User name: "<<this->user_name<<endl;
        cout<<"ID: "<<this->id<<endl;
        cout<<"Password: "<<this->password<<endl;
        return;
    }
};

int main(){
    User u1(1, "Aman");
    u1.setPassword();
    u1.getPassword();
    u1.getDetails();

    return 0;
}