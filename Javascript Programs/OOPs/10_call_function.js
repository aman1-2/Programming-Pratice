// //Mentod -1 of trying it Like a Super constructor
// function Person(name, lovesTo) {
//     this.name = name;
//     this.lovesTo = lovesTo;
// }

// function Ambitious(Name, lovesTo, wantToBe) {
//     Person.call(this, Name, lovesTo); //Here we made the call function act as the super constructor.
//     this.wantToBe = wantToBe;
//     this.details = function () {
//         console.log(this.name,"loves to",this.lovesTo,"and wants to be a",this.wantToBe,"at last.");
//     }
// }

// Object.setPrototypeOf(Ambitious.prototype, Person.prototype);

// const obj = new Ambitious("Aman","Travel","Good Human");
// obj.details();

//Method -2 of using the call function
const Person = {
    name: "Aman",
    car: "Range-Rover",
    showDetails: function() {
        console.log(this.name,"Dream car is",this.car);
    }
}

const obj = function () { //Not doing console.log() because we are not returning anything
    this.showDetails();
}

obj.call(Person); //This will call directly the this keyword getting binded to the person object.