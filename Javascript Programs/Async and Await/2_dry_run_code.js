function download(url) {
    return new Promise(function exec1(resolve, reject) {
        console.log("Started downloading the file from:",url,"....");
        setTimeout(function downloading() {
            let data = "Dummy Data";
            resolve(data);
            console.log("Download is completed");
        }, 4000);
    });
}

function write(data) {
    return new Promise(function exec(resolve, reject) {
        console.log("Started writing data:",data,"in file....");
        setTimeout(function writing() {
            let writeFile = "new.txt";
            resolve(writeFile);
            console.log("Writing is completed");
        }, 3000);
    });
}

function upload(fileName, url) {
    return new Promise(function exec(resolve, reject) {
        console.log("Started Uploading the file:",fileName,"on url:",url,"....");
        setTimeout(function uploading() {
            let response = "SUCCESS";
            resolve(response);
            console.log("Uploading is completed");
        }, 2000);
    });
}

async function steps() {
    console.log("Inside the steps");
    const downloadData = await download("www.dowloadKariyeJii.com");
    console.log("The Downloaded Data is:",downloadData);
    const writtenFile = await write(downloadData);
    console.log("The file in which data is written is:",writtenFile);
    const uploadRespose = await upload(writtenFile, "www.merePass.com");
    return uploadRespose;
}

steps().then((value) => {console.log("We have completed steps with value:",value)});

console.log("Outside");
for(let i=0; i<10000000000; i++) {}
setTimeout(function f(){ console.log("Timmer is Done.")}, 2000);
console.log("Execution of for loop is Done.");