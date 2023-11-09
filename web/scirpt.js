document.addEventListener("DOMContentLoaded", function () {
    var wynikDiv = document.getElementById("wynik");

    function pobierzDane() {
        var xhr = new XMLHttpRequest();
        //xhr.open("GET", "url_do_twojego_serwera/api/dane.json", true); dodać adres do serwera
        //xhr.setRequestHeader("Content-Type", "application/json");

        xhr.onreadystatechange = function () {
            if (xhr.readyState === 4 && xhr.status === 200) {
                var daneJSON = JSON.parse(xhr.responseText);
                
            }
        };

        xhr.send();
    }


    setInterval(pobierzDane, 1000);


    pobierzDane();
});
