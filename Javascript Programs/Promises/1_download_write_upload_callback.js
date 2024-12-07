//1. Write a function to download data from a Url.
function download(url, cb) {
    console.log(`Downloading Started from ${url}...`);
    setTimeout(function dummyData() {
        let data = "Dummy Data";
        console.log("Downloading completed...");
        cb(data);
    }, 10000);
}

//2. WAF to save the downloaded data in a file and return the name of the file.
function writingFile(data, cb) {
    console.log(`Writing ${data} Started in file...`);
    setTimeout(function writingFile() {
       let fileName = "Dummy Text file";
        console.log("Writing in file completed...");
        cb(fileName);
    }, 5000);
}

//3. WAF to upload the file written in previous step to a newUrl.
function uploadingFile(fileName, newUrl, cb) {
    console.log(`Uploading the ${fileName} on ${newUrl}...`);
    setTimeout(function upload(){
        console.log("Uploading is Done...");
        let success = true;
        cb(true);
    }, 3000);
}

download("www.google.com", function downloadCallback(data) {
    console.log("The Downloaded data is:",data);
    writingFile(data, function writingCallback(fileName) {
        console.log("The file in which data is written is:",fileName);
        uploadingFile(fileName, "www.aman.in", function uploadCallback(flag) {
            console.log("Uploading status:",flag);
        });
    });
});