let array = [1, 2, 3, 4, 5, 6];

//The array prototype has a Symbol.iterator() function in it.

//This statement will throw the error.
//iterator = array.Symbol.iterator; //Wrong way to access the symbol.iterator fucntion inside the prototype.

iterator = array[Symbol.iterator]();

console.log(iterator);

console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());