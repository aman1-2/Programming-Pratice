function download(url, timeStamp) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started the Downloading Process from the url:",url);
        setTimeout(function downloadPromise() {
            let data = "Dummy Data";
            console.log("Downloading gets completed.")
            if(timeStamp > 4000)    reject(data);
            else    resolve(data);
        }, 2000);
    });
}

//Lets say we need to do three different downloading
const p1 = download("downoloading1.com", 5000);
const p2 = download("downoloading2.com", 3000);
const p3 = download("downoloading3.com", 2000);
Promise.all([p1, p2, p3]).then(function fulfillmentHandler(values) { //The values stores the array of all the resolved promises that we registeed or started with the help of promise.all method.
    console.log("Values for Promise.all:",values);
})