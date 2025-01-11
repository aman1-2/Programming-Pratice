class Product {
    //Data-memebers of the class Product
    #name; //Private member
    // price;
    // description;

    //Writing own constructor for the product class
    constructor(n, p ,d) {
        this.#name = n;
        this.price = p;
        this.description = d;
        // return "10"; //Primitive -> No Effect
        // return {}; //Non-primitive -> will return this instead of default object created 
        // with the new keyword.
        return this; //If not returning anything then it is equivalent of saying this.
    }

    setName(n) { //Setting the name for the name property.
        if(typeof n != "string") {
            console.log("You are trying to set a Invalid name to the Product.");
            return;
        } else{
            this.#name = n;
        }
        return;
    }

    getName() { //Extracting the value of the private name property.
        console.log("Name of the Product is:",this.#name);
        return;
    }

    set name(n) {
        if(typeof n != "string") {
            console.log("You are trying to set a Invalid name to the Product.");
            return;
        } else{
            this.#name = n;
        }
        return;
    }

    get name() { //Extracting the value of the private name property.
        return this.#name;
    }

    //Methods or member function of the class
    display () {
      console.log(`{Name: ${this.#name}, Price: ${this.price}, Description: ${this.description}}`);  
    }
};

// const p = new Product(); //Initialized an Object of the Product.
// console.log(p); //This won't throw any error, infact will call the default constructor.

const p = new Product("Bag", 100, "School Bag"); 
p.name = -1
console.log(p) 
p.display();
console.log("Setting a new name with the help of setName function.");
p.setName("iPhone");
console.log("Accessing the name Property value with the help of getName fucntion.");
p.getName();
console.log("");
console.log("Setting a new name with the help of set name keyword.");
p.name = "Aman";
console.log("Accessing the name Property value with the help of get name keyword.");
console.log(p.name);