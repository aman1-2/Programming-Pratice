setTimeout(function f() {
    console.log("Settime out function Timmer 1");
}, 10); 

setTimeout(function g() {
    console.log("Settime out function Timmer 2");
}, 5); 

console.log("For Loop Start.");
for(let i=0; i<10000000000; i++) {
    //Doing Something
}
console.log("For Loop Done.");

console.log("End");