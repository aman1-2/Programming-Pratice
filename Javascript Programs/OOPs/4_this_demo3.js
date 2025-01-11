const iphone = {
    name: "Iphone",
    price: 100000,
    description: "The new apple Iphone 13 pro.",
    rating: 4.8,
    category: "Electronic",
    
    display : function() {

        const iphoneRed = {
            name: "IphoneRed",
            price: 100000,
            description: "The new apple Iphone 13 pro.",
            rating: 4.8,
            category: "Electronic",
            display: () => {console.log(this)}
        }
 
        iphoneRed.display(); //Inside the Iphone object's display function we have another object as IphoneRed 
        //and inside that IphoneRed object we have a display function which is printing the this keyword and here inside 
        // the display function of Iphone object we have called the display function of IphoneRed.

    }
}

iphone.display();