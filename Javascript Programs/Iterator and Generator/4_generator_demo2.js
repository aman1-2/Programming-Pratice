/**
 * Calling the return statement inside the Generator function.
 */

function* fetchNextElement() { //This is a Generator function
    console.log("This is the starting of the Generator Function.");
    yield 1;
    yield 2;
    console.log("Returning a value from the Generator Function.");
    return 12; //The return statement here too in the generator function would end the generator function like the normal function would
    //have exited with the return value of the function in same way this return value will be returned as the return value for our generator function.
    //Statements after return statement won't be executed. Just like the normal function would have acted.
    yield 3;
    console.log("Now going to end our generator with a last yield value.");
    yield 4;
}

const iterator = fetchNextElement(); 
console.log(iterator); 

console.log("1st ",iterator.next());
console.log("2nd ",iterator.next());
console.log("3rd ",iterator.next());
console.log("4th ",iterator.next());
console.log("5th ",iterator.next());
console.log("6th ",iterator.next());