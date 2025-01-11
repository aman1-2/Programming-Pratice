// let products = {
//     arr: [
//         {
//             name: "Iphone",
//             price: 100000,
//             description: "The new apple Iphone 13 pro.",
//             rating: 4.8,
//             getCategory: function print() {console.log(this.category)}
//         },
//         {
//             name: "MacBook M2",
//             price: 125000,
//             description: "The new MacBook M2.",
//             rating: 4.9,
//             getCategory: function print() {console.log(this.category)}
//         }
//     ],
//     category: "Electronic"
// }

// products.arr[0].getCategory();


//Doing some modification
// let products = {
//     arr: [
//         {
//             name: "Iphone",
//             price: 100000,
//             description: "The new apple Iphone 13 pro.",
//             rating: 4.8,
//             getCategory: () => {console.log(this.category)}
//         },
//         {
//             name: "MacBook M2",
//             price: 125000,
//             description: "The new MacBook M2.",
//             rating: 4.9,
//             getCategory: () => {console.log(this.category)}
//         }
//     ],
//     category: "Electronic",
//     getProducts: function () {
//         return this.arr;
//     }
// }

// products.getProducts()[0].getCategory();


const iphone = {
    name: "Iphone",
    price: 100000,
    description: "The new apple Iphone 13 pro.",
    rating: 4.8,
    category: "Electronic",
    display: () => {console.log(this)}
}

const macBook = {
    name: "MacBook M2",
    price: 125000,
    description: "The new MacBook M2.",
    rating: 4.9,
    category: "Electronic",
    display: function () {console.log(this)}
}

macBook.display();
iphone.display();