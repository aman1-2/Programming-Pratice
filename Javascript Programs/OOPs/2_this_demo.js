let iphone = {
    name: "Iphone 13 Pro",
    price: 100000,
    description: "The new apple Iphone 13 pro.",
    rating: 4.8,

    display: function() {
        console.log("Printing this of iphone:",iphone)
    }
};

console.log("Printing the iphone object:",iphone);

let macBook = {
    name: "MacBook M2",
    price: 125000,
    description: "The new MacBook M2.",
    rating: 4.9,

    display: function() {
        console.log("Printing this of iphone:",iphone)
    }
};

console.log("Printing the MacBook object:",iphone);

console.log("\nCalling the display function of the respective objects to see what there this have access to:-\n");
iphone.display();
macBook.display();

console.log("\nSeeing what the 'this' keyword when not associated to anything prints when called from the global code:-\n");
console.log(this);

