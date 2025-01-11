var obj = {
    name: "Aman",
    Dream_Company: "Big Tech Giant",
    display: ()=>{
        console.log(this.name,"Dream Companies are:",this.Dream_Company);
    }
}

var obj1 = {
    name: "Aman",
    Dream_Company: "Big Tech Giant",
    display: ()=>{
        setTimeout(() => {
            console.log(this.name,"Dream Companies are:",this.Dream_Company);
        }, 2000);
    }
}

var obj2 = {
    name: "Aman",
    Dream_Company: "Big Tech Giant",
    display: function() {
        setTimeout(() => {
            console.log(this.name,"Dream Companies are:",this.Dream_Company);
        }, 4000);
    }
}

console.log("Calling the First Obj's display function which is fat-arrow function inside which we print the this keyword:");
obj.display();
console.log("");
console.log("Calling the Second obj's display function where we bind our this console statement inside a setTimeout function which is too an arrow function:");
obj1.display();
console.log("");
console.log("Calling the Third Obj's display function which is a normal function inside which we have a setTimeout function which is arrow function which has this bind in it.");
obj2.display();