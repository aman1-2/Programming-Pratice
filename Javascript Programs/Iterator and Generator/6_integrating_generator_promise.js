/**
 * Mimicing the functionality of downloading, writeFile and Upload. They will all return a promise object to us.
 */

function download(url) {
    return new Promise(function promise(resolve, reject) {
        console.log("Started Downloading the data from", url);
        let data = "Dummy Data";
        setTimeout(function downloading() {
            resolve(data);
            console.log("The Downloading is completed");
        }, 4000);
    });
}

function write(data) {
    return new Promise(function promise(resolve, reject) {
        console.log("Started Writing the Data:",data);
        setTimeout(function writing() {
            let fileName = "new.txt";
            resolve(fileName);
            console.log("The data Writing is Completed");
        }, 3000);
    });
}

function upload(fileName, url) {
    return new Promise(function promise(resolve, reject) {
        console.log("Uploading the file:",fileName);
        setTimeout(function uploading() {
            resolve("SUCCESS");
            console.log("Uploading is completed.")
        }, 1000);
    });
}

function* steps() {
    const downloadedData = yield download("www.karo.download.com");
    console.log("Data downloaded is:",downloadedData);
    const fileWritten = yield write(downloadedData);
    console.log("File written is:",fileWritten);
    const uploadResponse = yield upload(fileWritten, "www.merepass.com")
    console.log("Upload Status:",uploadResponse);

    return uploadResponse;
}

function doAfterReceiving(value) { //Made a recusive function which will call the next function of the yield till 
    //our promise response is not SUCCESS i.e till we haven't executed the upload promise.
    //Base case 
    if(value == "SUCCESS")   return;
    let future = iter.next(value);
    future.value.then(doAfterReceiving); //Made a recursive call.
}

//Creating a global generator iterator
iter = steps();
const future = iter.next(); //Since tthis will return us a promise object as all are yields are returning us a promise.
//Therefore we can attach a .then() method to our future.
future.value.then(doAfterReceiving); //Since the iter will return a object with value and done properties and promise object will get stored inside the value property therefore we made it mention value.then

// const calling = download("www.kar.download.com");
// calling.then(function(value){
//     let data = value;
//     console.log("The downloaded data is:",data);
//     return write(data);
// })
// .then(function(value) {
//     let fileName = value;
//     console.log("The file in which data is written is:",fileName);
//     return upload(fileName, "www.merepass.com");
// })
// .then(function(value) {
//     console.log("Status:",value);
// });