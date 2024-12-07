//1. WAF to download a data from the given URL.
function download(url) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started downloading from the url:",url);
        setTimeout(function downloaded() {
            console.log("Downloading Completed");
            let dummyData = "Dummy Data";
            resolve(dummyData);
        }, 10000);
    });
}

//2. WAF to save that downloaded data in a file and return the file-name.
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

//3. WAF to upload the file written in previous step to a newUrl.
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
x.then(function downloadPromise(data) {
    console.log("The Downloaded data is:",data);
    return write(data);
})
.then(function writingPromise(fileName) {
    console.log("The data is written on the file:",fileName);
    return upload(fileName, "www.upload.com");
})
.then(function (status) {
    console.log("Status:",status);
});