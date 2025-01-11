class Product {
    //Data-memebers of the class Product
    // name;
    // price;
    // description;

    //Writing own constructor for the product class
    constructor(n, p ,d) {
        this.name = n;
        this.price = p;
        this.description = d;
        // return "10"; //Primitive -> No Effect
        // return {}; //Non-primitive -> will return this instead of default object created 
        // with the new keyword.
        return this; //If not returning anything then it is equivalent of saying this.
    }

    //Methods or member function of the class
    display () {
      //Here we can write the logic for displaying the product.  
    }
};

// const p = new Product(); //Initialized an Object of the Product.
// console.log(p); //This won't throw any error, infact will call the default constructor.

const p = new Product("Bag", 100, "School Bag"); 
console.log(p) 