function fetchNextElement(array) {
    let idx = 0;
    function next() {
        if(idx == array.length) {
            return {value: undefined, done: true};
        }

        const nextElement = array[idx];
        idx++;
        
        return {value: nextElement, done: false};
    }

    return {next};
}

let array = [1, 2, 3, 4, 5, 6];


const automaticFetcher = fetchNextElement(array); //Inside automatic fetcher variable we store the object of next function.

console.log(automaticFetcher.next());
console.log(automaticFetcher.next());
console.log(automaticFetcher.next());
console.log(automaticFetcher.next());
console.log(automaticFetcher.next());
console.log(automaticFetcher.next());
console.log(automaticFetcher.next());