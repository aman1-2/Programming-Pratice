function* fetchNextElement() { //This is a Generator function
    console.log("This is the starting of the Generator function.");
    yield 1;
    yield 2;
    console.log("Now we are somewhere in the middle of the generator function.");
    yield 3;
    console.log("Now going to end our generator with a last yield value.");
    yield 4;
}

const iterator = fetchNextElement(); //This function call will return you can iterator this wont start the function execution here it will just return a Generator iterator.
//Its not like normal generator functions that we called a generator function then it will immediately starts executing the generator function it will at initial step return the iterator of generator to it.
console.log(iterator); //Its a whole object altogether.

console.log("1st ",iterator.next());
console.log("2nd ",iterator.next());
console.log("3rd ",iterator.next());
console.log("4th ",iterator.next());
console.log("5th ",iterator.next());
console.log("6th ",iterator.next());