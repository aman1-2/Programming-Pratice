let obj = {
    x:10, y:20
};

Object.freeze(obj); //Neither can add a new property nor update the old one.
obj.x = 12;
obj.z = 6;

console.log("Example of Freeze function:");
console.log(obj);

console.log();

let obj1 = {
    x:"Aman", y:"Aditya"
};

Object.seal(obj1); //We cannot add a new property but we can update old ones.
obj1.x = 12;
obj1.z = "Anjali";

console.log("Example of Seal function:");
console.log(obj1);

console.log();

const obj2 = { //With the const we can't re-assign the object the updation in the object are allowed.
    Name: "Aman", x:6
};
obj2.Name = "Aditya";
obj2.z = 12;

console.log("Example of the const");
console.log(obj2);