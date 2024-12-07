// function* fetchNextElement() {
//     console.log("Inside the generator function.");
//     const x = 10;
//     yield 6;
//     console.log("Entering again after yielding a value.");
//     const y = x + (yield 12);
//     console.log("Value of Y is: ", y);
// }

// console.log("Start");
// const iter = fetchNextElement();

// console.log("Calling the Generators:-");
// console.log("first ", iter.next());
// console.log("second ", iter.next("Aman"));
// console.log("third ", iter.next());

function* fetchNextElement() {
    console.log("Inside the generator function.");
    const x = 10;
    yield 6;
    console.log("Entering again after yielding a value.");
    const y = x + (yield 12);
    console.log("Value of Y is: ", y);
} 

console.log("Start");
const iter = fetchNextElement();

console.log("Calling the Generators:-");
console.log("first ", iter.next());
console.log("second ", iter.next());
console.log("third ", iter.next(10));