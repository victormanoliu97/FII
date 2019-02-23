let jsonResponse = {};


function get(destination) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", destination);
    xmlhttp.onreadystatechange = function() {
        if (this.readyState === 4)
        {
            console.log(this.response);
        }
    };
    xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xmlhttp.send();
}

function getIpStackMetrics(destination) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", destination);
    xmlhttp.onreadystatechange = function () {
        if (this.readyState === 4) {
            console.log(this.response + "\n");
            let response = JSON.parse(this.response);

            var name = document.getElementById("name");
            name.innerHTML = response["name"];

            var link = document.getElementById("link");
            link.innerHTML = response["link"].toString();

            var average_time = document.getElementById("average_time");
            average_time.innerHTML = response["average_time"];

            var succes_requests_perc = document.getElementById("succes_percent");
            succes_requests_perc.innerHTML = response["succes_requests_perc"];

            var failed_percent = document.getElementById("failed_percent");
            failed_percent.innerHTML = response["failed_requests_perc"];

            var encoding = document.getElementById("encoding");
            encoding.innerText = response["encoding"]
        }
    };
    xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xmlhttp.send();
}

function getGoogleMetrics(destination) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", destination);
    xmlhttp.onreadystatechange = function () {
        if (this.readyState === 4) {
            console.log(this.response + "\n");
            let response = JSON.parse(this.response);

            var name = document.getElementById("name_google");
            name.innerHTML = response["name"];

            var link = document.getElementById("link_google");
            link.innerHTML = response["link"].toString();

            var average_time = document.getElementById("average_time_google");
            average_time.innerHTML = response["average_time"];

            var succes_requests_perc = document.getElementById("succes_percent_google");
            succes_requests_perc.innerHTML = response["succes_requests_perc"];

            var failed_percent = document.getElementById("failed_percent_google");
            failed_percent.innerHTML = response["failed_requests_perc"];

            var encoding = document.getElementById("encoding_google");
            encoding.innerText = response["encoding"]
        }
    };
    xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xmlhttp.send();
}

function getWeatherMetrics(destination) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", destination);
    xmlhttp.onreadystatechange = function () {
        if (this.readyState === 4) {
            console.log(this.response + "\n");
            let response = JSON.parse(this.response);

            var name = document.getElementById("name_weather");
            name.innerHTML = response["name"];

            var link = document.getElementById("link_weather");
            link.innerHTML = response["link"].toString();

            var average_time = document.getElementById("average_time_weather");
            average_time.innerHTML = response["average_time"];

            var succes_requests_perc = document.getElementById("succes_percent_weather");
            succes_requests_perc.innerHTML = response["succes_requests_perc"];

            var failed_percent = document.getElementById("failed_percent_weather");
            failed_percent.innerHTML = response["failed_requests_perc"];

            var encoding = document.getElementById("encoding_weather");
            encoding.innerText = response["encoding"]
        }
    };
    xmlhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xmlhttp.send();
}


function showIpStackMetrics() {
    getIpStackMetrics("../cgi-bin/getIpStackMetrics.py");
}

function showGoogleMetrics() {
    getGoogleMetrics("../cgi-bin/getGoogleMetrics.py")
}

function showWeatherMetrics() {
    getWeatherMetrics("../cgi-bin/getWeatherMetrics.py")
}

function getIpStack() {
    get( "../cgi-bin/getLocationBasedOnIP.py");
}

function getGoogleGeo() {
    get("../cgi-bin/getCityBasedOnCoordinates.py");
}

function getWeather() {
     get("../cgi-bin/getWeather.py");
}