function MyMap(arr, fn) {
    let result = [];

    for(let i=0; i<arr.length; i++) {
        result.push(fn(arr[i], i));
    }

    return result;
}

let arr = [1,2,3,4,5,6];

let res = MyMap(arr, function (ele) {
    return ele*ele;
});

console.log(res);