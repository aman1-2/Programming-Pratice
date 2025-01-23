/**
 * We created a setCancellableTimeout function and what it is taking as argument in one callback function and other the delay function.
 * And then we can call setTimeout directly then what will happen is you are going to get the timmerID. Now don't want to return this timmerId.
 * And technically want to return a function and when somebody calls this function then you need to stop the timmer. And we know how to stop the
 * timmer by calling clearTimeout and passing the timmerID as the argument
 */
function setCancellableTimeout(callback, delay) {
    const timmerID = setTimeout(callback, delay);
    return () => {
        clearTimeout(timmerID);
    }
}

/**
 * So now if we call this setCancellableTimeout and pass a callback and delay in it an don't do anything then lets see what happens.
 */
let f = setCancellableTimeout(() => {console.log("Hi.")}, 3000);
/**
 * So this will print the value hi after the delay of 3000.
 * But now lets say we call f() in that case the timeout will be cancelled.
 */
f();

/**
 * And this is from the concept of function being first class citizen of Javascript. Why?
 * Because we can pass a function as an argument to another function and can ti return from a function and so on.
 * And the hint was given in example itself that there should be a setCancellableTimeout and when we call it then it cancels it.
 * So technically we were already aware about this that the return type must be a function
 */

/**
 * We can to create this without the help of the callback but in that case we would need to maintain a flag property so
 * boolean which we will check and if its not true then call the callback function if it comes out to be true in that 
 * case just return from the function.
 */

//Other way to implement it....
function setCancellableTimeout2(callback, delay) {
    let flag = true;
    const timmerID = setTimeout(() => {
        if(!flag)   return;
        callback();
    }, delay);
    return () => {
        flag = false; //Because of the closure property this setTimeout will remember the variable flag.
        clearTimeout(timmerID);
    }
}

let g = setCancellableTimeout2(() => {
    console.log("Print nhi hoga");
}, 12000);

g(); //If we will not call this then the callback passed inside the function will print its value.