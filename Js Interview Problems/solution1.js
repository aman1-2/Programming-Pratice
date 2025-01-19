function sleep(milisecond) {
    return new Promise((resolve, reject) => {
        setTimeout(resolve, milisecond);
    });
}

function blockingSleep(milisecond) {
    let timeNow = new Date().getTime(); //This is will create a date object and on that date object using getTime function will return the time in milisecond. The current time in milisecond
    while(new Date().getTime() < timeNow + milisecond) { //And then here we are comparing when we created the timeNow in which we had the current milisecond value in that adding the blocking or sleepin time and then looping again and again that if the current time has increased from the timeNow+milisecond passed or not.
        //You need to wait.
    }
}

async function process() {
    console.log("Hello!");
    // await sleep(2000); //await always asks for a promise object. And as soon as the await is hit it throws us out of the function.
    blockingSleep(5000);
    console.log("Bye.");
}

console.log("Starting");
process();
