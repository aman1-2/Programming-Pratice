function download(url) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started downloading the file from:",url,"....");
        setTimeout(function promise() {
            let data = "Dummy Data";
            resolve(data);
            console.log("Download is completed");
        }, 4000);
    });
}

function write(data) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started writing data:",data,"in file....");
        setTimeout(function promise() {
            let writeFile = "new.txt";
            resolve(writeFile);
            console.log("Writing is completed");
        }, 3000);
    });
}

function upload(fileName, url) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started Uploading the file:",fileName,"on url:",url,"....");
        setTimeout(function promise() {
            let response = "SUCCESS";
            resolve(response);
            console.log("Uploading is completed");
        }, 2000);
    });
}

async function steps() {
    console.log("Inside the steps");
    const downloadData = await 10;
    console.log("The Downloaded Data is:",downloadData);
    const writtenFile = await write(downloadData);
    console.log("The file in which data is written is:",writtenFile);
    const uploadRespose = await upload(writtenFile, "www.merePass.com");
    return uploadRespose;
}

steps();
console.log("Outside");