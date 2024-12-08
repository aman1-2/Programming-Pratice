function download(url) {
    return new Promise(function downloading(resolve, reject) {
        console.log("Started the Downloading Process from the url:",url);
        setTimeout(function downloadPromise() {
            let data = "Dummy Data";
            console.log("Downloading gets completed.")
            reject(data);
        }, 2000);
    });
}

async function steps() {
    try {
        const downloadData = await download("www.download.karo");
        console.log("Downloaded Data is:",downloadData);
    } catch (error) {
        //Printing the error object.
        console.log("We have handled the error:",error);
    } finally {
        console.log("Doesn't matter the code throws an error or not. Finally block will get executed at each situation.");
    }
}

steps();