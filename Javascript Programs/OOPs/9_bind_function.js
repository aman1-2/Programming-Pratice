const person = {
    name: "Aman Pratap Singh",
    lovesTo: "Travel",
    wantToBe: "Good Human",
    showDetails: function pritingDetails() {
        console.log(this.name,"loves to",this.lovesTo,"new places and hopes to be a",this.wantToBe);
    }
}

// const obj = function () {
//     //Inside this anonymous function the this will point to the global object.
//     console.log(this.showDetails()); //And inside the global object we don't have any showDetails function therefore throws an error.
//     // console.log(this); //It will point to a Global Object.

//     //Instead of calling a function  if we would have just called a variable then it would have returned undefined instead of error because
//     //in that case the this object won't be having that variable and if not having that variable then the value returned would be undefined.
// }

// obj(); //This statement will throw an error as obj is associated to a function therefore we are able to call obj as function.

const obj = function () {
    //Inside this anonymous function the this keyword will point to the global object.
    console.log(this.showDetails())
}

//Point to note is our bind function to returns a function at the end.
const x = obj.bind(person); //This time the on the obj function we have binded it with the person object that's why this time the this keyword in the obj will point to the Person object.
x();
console.log(x);