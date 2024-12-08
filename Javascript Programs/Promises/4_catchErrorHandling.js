function download(url) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started downloading from the url:",url);
        setTimeout(function downloaded() {
            console.log("Downloading Completed");
            let dummyData = "Dummy Data";
            reject(dummyData);
        }, 10000);
    });
}

function write(data) {
    return new Promise(function writing(resolve, reject) {
        console.log(`Started writing the ${data} in the text file.`);
        setTimeout(function writted() {
            console.log("Writing Completed");
            let newFile = "file.txt";
            resolve(newFile);
        }, 5000);
    });
}

function upload(fileName, newUrl) {
    return new Promise(function uploaded(resolve, reject) {
        console.log(`Started uploading the ${fileName} to ${newUrl}.`);
        setTimeout(function uploaded() {
            console.log("Uploading Completed");
            let status = true;
            resolve(status);
        }, 3000);
    }); 
}


let x = download("www.google.com");
x.then(
    function downloadPromise(data) {
        console.log("The Downloaded data is:",data);
        return write(data);
    }
)
.then(
    function writingPromise(fileName) {
        console.log("The data is written on the file:",fileName);
        return upload(fileName, "www.upload.com");
    }
)
.then(
    function (status) {
        console.log("Status:",status);
    }
)
.catch(function catchHandler(value) {
    console.log("Catch Handler an Error occured which is catched value is:",value)
});